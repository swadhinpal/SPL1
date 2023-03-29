#include<bits/stdc++.h>
#include"Katz_Centrality1.h"
using namespace std;

vector<vector<string>>nor()
{
    vector<string>code_lines,nor,var,func;
    vector<vector<string>>res;
    code_lines=segmentation();
    FILE *fp,*fp1;
    char ch;
    //fp1=fopen("newfile1.txt","w");
    for(int i=0;i<code_lines.size();i++)
    {
        //cout<<nor.size()<<endl;
        string s1="",s2="",s=code_lines[i];
        nor.push_back(s1);

        for(int j=0;j<s.length();j++)
        {
           if(s[j]=='<')
            {
                if(s1=="#include")
                {
                    string s4=nor[i];
                    s4+=s1;
                    s4+=' ';
                    nor[i]=s4;
                    s1="";
                    j++;
                    while(s[j]!='>')
                    {
                       s1+=s[j];
                       j++;
                   }
                }
                else if(s1.length()>0&&s1!=" ")
                {
                    for(int k=0;k<var.size();k++)
                    {
                       if(s1[0]=='*') {
                       string s5="";
                       for(int k=1;k<s1.length();k++)
                       {
                          if(s1[k]!='!'||s1[k]!='*')s5+=s1[k];
                       }
                       s1=s5;
                       }

                       string s3=var[k];
                       if(s3==s1)
                       {
                           string s3="var";
                           //char c=k+1+'0';
                           s3+=to_string(k+1);
                           //s3+=c;
                           s3+=' ';
                           string s4=nor[i];
                           s4+=s3;
                           //s4+=' ';
                           nor[i]=s4;
                           //nor[i]+=s3;
                           break;
                       }
                    }

                    if(s1[0]>='0'&&s1[0]<='9')
                    {
                        string s4=nor[i];
                        s4+="num";
                        s4+=' ';
                        nor[i]=s4;
                    }
                    /*string s4=nor[i];
                    s4+=s1;
                    s4+=' ';
                    nor[i]=s4;
                    s1="";*/
                }
                s1="";
                string s4=nor[i];
                s4+=s[j];
                if(s[j]!=' ')s4+=' ';
                nor[i]=s4;
            }
            else if(s[j]=='"')
            {
                j++;
                while(s[j]!='"') j++;
            }

            else if(j==s.length()-1||s[j]==' '||s[j]=='+'||s[j]=='-'||s[j]=='/'||s[j]=='&'||s[j]=='%'
                    /*||s[j]=='*'*/||s[j]==')'||s[j]=='='||s[j]=='{'||s[j]=='}'||s[i]=='!'||s[j]=='<'||s[j]=='>'||s[j]=='|')
            {
                //cout<<s1<<endl;

                bool is_keyword=false;
                fp=fopen("All_keyword.txt","r");
                ch=fgetc(fp);
                if(fp==NULL)
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
                      if(s2==s1)
                      {
                         is_keyword=true;
                         string s4=nor[i];
                         s4+=s1;
                         s4+=' ';
                         nor[i]=s4;
                         break;
                      //cout<<s22<<endl;break;
                      }
                      else s2="";
                   }
                   ch=fgetc(fp);
                 }

               fclose(fp);

                bool is_accepting=true;
                if(s1[0]-'0'>=0&&s1[0]-'0'<=9)
                {
                   //cout<<s1<<endl;
                    is_accepting=false;
                    string s4=nor[i];
                    s4+="num";
                    s4+=' ';
                    nor[i]=s4;
                }
               if(s1.length()<2)
               {
                   if(s1.length()==0) is_accepting=false;
                   else if(s1==" ")is_accepting=false;
               }


               if(!is_keyword&&is_accepting)
               {
                   //cout<<s1<<endl;
                   bool is_present=false;
                   for(int k=0;k<var.size();k++)
                   {
                       string s5="";
                       for(int k=0;k<s1.length();k++)
                       {
                          if(s1[k]!='!'&&s1[k]!='*')s5+=s1[k];
                       }
                       s1=s5;


                       string s3=var[k];
                       if(s3==s1)
                       {
                           string s3="var";
                           //char c=k+1+'0';
                           s3+=to_string(k+1);
                           //s3+=c;
                           s3+=' ';
                           string s4=nor[i];
                           s4+=s3;
                           //s4+=' ';
                           nor[i]=s4;
                           //nor[i]+=s3;
                           is_present=true;
                           break;
                       }
                   }
                   if(!is_present)
                   {
                          string s5="";
                          for(int k=0;k<s1.length();k++)
                          {
                             if(s1[k]!='!'&&s1[k]!='*'&&s1[k]!=' ')s5+=s1[k];
                          }
                          s1=s5;
                       if(s1.length()>0)var.push_back(s1);
                       string s3="var";
                       //char c= var.size()+'0';
                       s3+=to_string(var.size());
                       //s3+=c;
                       s3+=' ';
                       string s4=nor[i];
                       s4+=s3;
                       s4+=' ';
                       nor[i]=s4;
                       //nor[i]+=s3;
                   }
               }
               string s4=nor[i];
               s4+=s[j];
               if(s[j]!=' ')s4+=' ';
               nor[i]=s4;
               //nor[i]+=s[j];
               //nor[i]+=' ';
               s1="";
            }
            else if(s[j]=='(')
            {

                //cout<<s1<<endl;
                bool is_keyword=false;
                fp=fopen("All_keyword.txt","r");
                ch=fgetc(fp);
                if(fp==NULL)
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
                      if(s2==s1)
                      {
                          //cout<<s1<<endl;
                         is_keyword=true;
                         string s4=nor[i];
                         s4+=s1;
                         s4+=' ';
                         nor[i]=s4;
                         break;
                      //cout<<s22<<endl;break;
                      }
                      else s2="";
                   }
                   ch=fgetc(fp);
                 }

                fclose(fp);


                bool is_built_in_func=false;

                if(s1=="printf"||s1=="scanf"||s1=="calloc"||s1=="malloc"||s1=="fopen"||s1=="fclose"||s1=="fgetc"
                   ||s1=="fputc"||s1=="reallow"||s1=="free"||s1=="strcat"||s1=="strcmp"||s1=="system")
                {
                    nor[i]+=s1;
                    nor[i]+=" ";
                    is_built_in_func=true;
                }
                else{
                fp1=fopen("Built-in-function.txt","r");
                ch=fgetc(fp1);
                if(fp1==NULL)
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
                      if(s2==s1)
                      {
                          //cout<<s1<<endl;
                         is_built_in_func=true;
                         s2="built_in_func ";
                         string s4=nor[i];
                         s4+=s2;
                         //s4+=' ';
                         nor[i]=s4;
                         //nor[i]+=s2;
                         break;
                      //cout<<s22<<endl;break;
                      }
                      else s2="";
                   }
                   ch=fgetc(fp1);
                 }

               fclose(fp1);}
               bool is_accepting=true;
               if(s1.length()<2)
               {
                   if(s1.length()==0) is_accepting=false;
                   else if(s1==" "||s1=="+"||s1=="-"||s1=="*"||s1=="/"||s1==">"||s1=="<"||s1=="&"||s1=="%"||s1=="|"||s1=="!")is_accepting=false;
               }

               if(!is_built_in_func&&!is_keyword&&is_accepting)
               {
                   bool is_present=false;
                   if(s1[0]=='*') {
                    string s5="";
                    for(int k=1;k<s1.length();k++)
                    {
                        s5+=s1[k];
                    }
                    s1=s5;
                   }
                   for(int k=0;k<func.size();k++)
                   {
                       string s3=func[k];
                       if(s3==s1)
                       {

                           //cout<<s1<<endl;
                           string s5="func";
                           //char c=k+1+'0';
                           s5+=to_string(k+1);
                           //s3+=c;
                           s5+=' ';
                           string s4=nor[i];
                           s4+=s5;
                           //s4+=' ';
                           nor[i]=s4;
                           //nor[i]+=s3;
                           is_present=true;
                           break;
                       }
                   }
                   if(!is_present)
                   {
                       //cout<<s1<<endl;
                       /*if(s1[0]=='*') {
                       string s5="";
                       for(int k=1;k<s1.length();k++)
                       {
                           s5+=s1[k];
                       }
                       s1=s5;
                       }*/
                       func.push_back(s1);
                       string s6="func";
                       //char c= var.size()+'0';
                       s6+=to_string(func.size());
                       //s3+=c;
                       s6+=' ';
                       string s4=nor[i];
                       s4+=s6;
                       //s4+=' ';
                       nor[i]=s4;
                       //nor[i]+=s3;
                   }
               }
               string s4=nor[i];
               s4+=s[j];
               if(s[j]!=' ')s4+=' ';
               nor[i]=s4;
               //nor[i]+=s[j];
               //nor[i]+=' ';
               s1="";
            }
            else
            {
                s1+=s[j];
            }
        }

    }
    res.push_back(nor);
    res.push_back(var);
    res.push_back(func);

    //cout<<nor.size()<<endl;
    for(string str:nor)
    {
       // cout<<str<<endl;
    }
    //cout<<"var"<<endl;
    for(string str:var)
    {
        //cout<<str<<endl;
    }
    //cout<<"func"<<endl;
    for(string str:func)
    {
        //cout<<str<<endl;
    }

    return res;
}


	
