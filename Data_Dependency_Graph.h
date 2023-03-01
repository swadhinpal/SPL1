#include<bits/stdc++.h>
#include"Control_Dependency__Graph.h"
using namespace std;

vector<vector<int>>Data_Graph()
{
    int m;
    char ch;
    int *end_curly;
    FILE *fp6,*fp7;
    vector<string>code_line,data_flow;
    code_line=segmentation();
    for(int i=0;i<code_line.size();i++)
    {
        string s=code_line[i];
        cout<<i+1<<" "<<s<<endl;
    }

    vector<int>data_line;
    m=code_line.size();
    m++;

    vector<vector<int>> Data_Graph1( m , vector<int> (m, 0));
    end_curly=closing_curly_braces();

    for(int i=0;i<m-1;i++)
    {
        string s=code_line[i],prv="",s1="",s2="",s3="",var_b4_eq="";
        int cnt=0,eq_line=0;

        for(int j=0;j<s.length();j++)
        {
           if(s[j]=='"')
           {
               j++;
               while(s[j]!='"')
               {
                   j++;
               }
               j++;
           }
           if(s[j]=='[')
           {
               j++;
               while(s[j]!=']')
               {
                   j++;
               }
               j++;
           }
           if(s[j]=='&')
           {
               j++;
              while(!(j==s.length()||s[j]==' '||s[j]=='+'||s[j]=='-'||s[j]=='='||s[j]=='&'||s[j]=='('||s[j]==')'
                      ||s[j]=='>'||s[j]=='<'||s[j]=='!'||s[j]=='*'||s[j]=='/'||s[j]=='%'))
              {
                 s3+=s[j];
                 j++;
              }
              for(int k=0;k<data_flow.size();k++)
              {
                  if(s3==data_flow[k])
                  {
                      Data_Graph1[i+1][data_line[k]]=1;
                      data_line[k]=i+1;
                      break;
                  }
              }
              s3="";
           }

           if(s[j]=='=')
           {
               j++;
               if(j!=s.length())
               {
                   if(!(('a'<=s[j]&&s[j]<='z')||('A'<=s[j]&&s[j]<='Z'))){
                  while(!(j==s.length()||s[j]==' '||s[j]=='+'||s[j]=='-'||s[j]=='='||s[j]=='&'||s[j]=='('||s[j]==')'||s[j]=='>'
                      ||s[j]=='<'||s[j]=='!'||s[j]=='*'||s[j]=='/'||s[j]=='%'))
                 {
                   //if(('a'<=s[j]&&s[j]<='z')||('A'<=s[j]&&s[j]<='Z')) break;
                    j++;
                 }
                }
                else j--;
               }
           }

           if(s[j]=='+'||s[j]=='-')
           {
               cnt++;
               if(cnt==2){
               //cout<<i+1<<"-+ "<<prv<<endl;
               for(int k=0;k<data_flow.size();k++)
               {
                  if(prv==data_flow[k])
                  {
                      //Data_Graph1[i+1][data_line[k]]=1;
                      data_line[k]=i+1;
                      break;
                  }
               }}
           }

           else if(s[j]!='+'&&s[j]!='-') cnt=0;

           if(j==s.length()||s[j]==' '||s[j]=='+'||s[j]=='-'||s[j]=='='||s[j]=='&'||s[j]=='('||s[j]==')'||s[j]=='>'
              ||s[j]=='<'||s[j]=='!'||s[j]=='*'||s[j]=='/'||s[j]=='%')
           {

               if(s[j]=='=')
               {
               for(int k=0;k<data_flow.size();k++)
               {
                  if(s1==data_flow[k])
                  {
                      //cout<<i+1<<"= "<<s1<<endl;
                      var_b4_eq=s1;
                      eq_line=i+1;
                      s1="";
                      Data_Graph1[i+1][data_line[k]]=1;
                      data_line[k]=i+1;
                      break;
                  }
               }
              }
              if(s[j]=='(')
              {
                  if(s1=="main")
                  {
                    data_flow.clear();
                    data_line.clear();
                  }
                  s1="";
              }

              bool keyword=false, built_in_func=false;
              fp6=fopen("All_keyword.txt","r");
              ch=fgetc(fp6);
              if(fp6==NULL)
              {
                cout<<"Invalid";
                exit(1);
              }
             while(ch!=EOF)
             {
                if(ch!='\n')
                {
                  s2+=ch;
                }
                else
                {
                   if(s1==s2)
                   {
                      //cout<<s2<<endl;
                      keyword=true;
                      s2="";
                      break;
                   }
                   else s2="";
                }
               ch=fgetc(fp6);
              }
              fclose(fp6);


              fp7=fopen("Built-in-function.txt","r");
              ch=fgetc(fp7);
              if(fp7==NULL)
              {
                cout<<"Invalid";
                exit(1);
              }
             while(ch!=EOF)
             {
                if(ch!='\n')
                {
                  s2+=ch;
                }
                else
                {
                   if(s1==s2)
                   {
                      //cout<<s2<<endl;
                      built_in_func=true;
                      s2="";
                      break;
                   }
                   else s2="";
                }
               ch=fgetc(fp7);
              }
            fclose(fp7);

            if(j!=s.length())
            {
                if(s[j+1]!='(')
                {
                   if(!keyword&&!built_in_func)
                   {
                       bool present=false;
                       if(data_flow.size()>0)
                       {

                           for(int k=0;k<data_flow.size();k++)
                           {
                               if(s1==data_flow[k])
                               {
                                   if(s1!=var_b4_eq||(s1==var_b4_eq&&eq_line!=i+1))
                                   {
                                       Data_Graph1[i+1][data_line[k]]=1;present=true;break;
                                   }
                               }
                           }
                       }
                       if(!present&&s1!="")
                        {
                            data_flow.push_back(s1);
                            data_line.push_back(i+1);
                        }
                    }
                }

            }

            prv=s1;
            s1="";
           }
           else
           {
               s1+=s[j];
           }

        }
    }

    /*for(int i=1;i<m;i++)
    {
        cout<<i<<"-> ";
        for(int j=1;j<m;j++)
        {
            if(Data_Graph1[i][j]!=0) cout<<j<<" ";
        }
        cout<<endl;
    }*/
    return Data_Graph1;
}
