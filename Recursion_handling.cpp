#include<bits/stdc++.h>
#include"Built-in_flow.h"
using namespace std;

int main()
{
    vector<string>line_,prototype_name,function_name,function_call;
    line_=segmentation();
    for(string sss: line_)
    {
        cout<<sss<<endl;
    }
    int *closing_braket,size_;
    closing_braket=closing_curly_braces();
    int prototype_index[200],function_index[200],fcall_index[200];
    FILE *fp4,*fp5;
    char ch;
    size_=line_.size()+1;
    vector<vector<int>> Control_Graph1;
    //( size_ , vector<int> (size_, 0));
    Control_Graph1=Graph();

    for(int y=0;y<line_.size();y++)
    {
       string s22,s33,s=line_[y];
       bool is_keyword=false,is_built_in_func=false;
       for(int t=0;t<=s.length();t++)
       {
          if(t==s.length()||s[t]==' '||s[t]=='('||s[t]==')'||s[t]=='{'||s[t]=='}'||s[t]=='=')
          {
             if(s[t]=='(')
             {
                 //cout<<y<<" ";
                 //cout<<s22<<endl;
             fp4=fopen("Required_keyword.txt","r");
             ch=fgetc(fp4);
             if(fp4==NULL)
             {
                cout<<"Invalid";
                exit(1);
             }
             while(ch!=EOF)
             {
                if(ch!='\n')
                {
                  s33+=ch;
                }
                else
                {
                   if(s22==s33)
                   {
                      is_keyword=true;
                      //cout<<s22<<endl;break;
                   }
                   else s33="";
                }
               ch=fgetc(fp4);
              }

            fclose(fp4);

            fp5=fopen("Built-in-function.txt","r");
             ch=fgetc(fp5);
             if(fp5==NULL)
             {
                cout<<"Invalid";
                exit(1);
             }
             while(ch!=EOF)
             {
                if(ch!='\n')
                {
                  s33+=ch;
                }
                else
                {
                   if(s22==s33)
                   {
                      is_built_in_func=true;
                      //cout<<s22<<endl;break;
                   }
                   else s33="";
                }
                ch=fgetc(fp5);
             }
               fclose(fp5);

                if(!is_built_in_func&&!is_keyword)
                {

                    if(s22!="for"&&s22!="while"&&s22!="switch"&&s22!="if"&&s22!="main")
                    {
                        //cout<<y+1<<" "<<s22<<" ";
                        //cout<<"Not built in"<<endl;
                        if(closing_braket[y+2]==0)
                        {
                            string st1="",st2="";int keyword=0;
                            for(int x=0;x<s.length();x++)
                            {

                               if(s[x]==' '||s[x]=='=')
                               {
                               fp4=fopen("Required_keyword.txt","r");
                               ch=fgetc(fp4);

                               if(fp4==NULL)
                               {
                                 cout<<"Invalid";
                                 exit(1);
                               }
                               while(ch!=EOF)
                               {
                                  if(ch!='\n')
                                  {
                                     st2+=ch;
                                  }
                               else
                               {
                                  if(st1==st2)
                                  {
                                    if(s[x]!='=')keyword++;
                                    //cout<<st1<<endl;break;
                                  }
                                  else st2="";
                                }
                               ch=fgetc(fp4);
                               }

                              fclose(fp4);
                              st1="";
                            }
                            else
                            {
                                st1+=s[x];
                            }
                        }
                        if(keyword)
                        {
                            prototype_name.push_back(s22);
                            prototype_index[prototype_name.size()-1]=y+1;
                        }
                        else
                        {
                            function_call.push_back(s22);
                            fcall_index[function_call.size()-1]=y+1;
                        }

                        }
                        else
                        {
                            function_name.push_back(s22);
                            function_index[function_name.size()-1]=y+1;
                        }
                    }
                }


            }

            //if(s2=="return")

            s22="";
           }

           else
           {
              s22+=s[t];
           }
        }
    }

    for(int ii=0;ii<function_call.size();ii++)
    {
        int jj,idx;
        string ss= function_call[ii];
        Control_Graph1[fcall_index[ii]][fcall_index[ii]+1]=0;
        bool proto=false;
        for(jj=0;jj<prototype_name.size();jj++)
        {
            if(prototype_name[jj]==ss)
            {
                Control_Graph1[prototype_index[jj]-1][prototype_index[jj]]=0;
                Control_Graph1[fcall_index[ii]][prototype_index[jj]]=1;
                proto=true;
                idx=jj;
                //break;
            }
            Control_Graph1[prototype_index[jj]-1][prototype_index[jj]]=0;
        }
        if(proto)
        {
            for(int kk=0;kk<function_name.size();kk++)
            {
                if(function_name[kk]==ss)
                {
                    Control_Graph1[function_index[kk]-1][function_index[kk]]=0;
                    Control_Graph1[prototype_index[idx]][function_index[kk]]=1;
                    Control_Graph1[closing_braket[function_index[kk]+1]][fcall_index[ii]+1]=1;
                }
            }
        }
        else
        {
            for(int kk=0;kk<function_name.size();kk++)
            {
                if(function_name[kk]==ss)
                {
                    Control_Graph1[function_index[kk]-1][function_index[kk]]=0;
                    Control_Graph1[fcall_index[ii]][function_index[kk]]=1;
                    Control_Graph1[closing_braket[function_index[kk]+1]][fcall_index[ii]+1]=1;
                    //cout<<closing_braket[function_index[kk]+1]<<" ";
                }
            }
        }
    }
    Control_Graph1[prototype_index[0]-1][prototype_index[prototype_name.size()-1]+1]=1;
    Control_Graph1[prototype_index[prototype_name.size()-1]][prototype_index[prototype_name.size()-1]+1]=0;
 cout<<"proto"<<endl;
   for(int i=0;i<prototype_name.size();i++)
   {
       cout<<prototype_index[i]<<" "<<prototype_name[i]<<endl;
   }
 cout<<"function body"<<endl;
   for(int i=0;i<function_name.size();i++)
   {
       cout<<function_index[i]<<" "<<function_name[i]<<endl;
   }
    cout<<"function call"<<endl;
   for(int i=0;i<function_call.size();i++)
   {
       cout<<fcall_index[i]<<" "<<function_call[i]<<endl;
   }
   for(int i=0;i<size_;i++)
   {
       for(int j=0;j<size_;j++)
       {
           if(i==0) cout<<j<<" ";
           else if(j==0) cout<<i<<" ";
           else cout<<Control_Graph1[i][j]<<" "<<" ";
       }
       cout<<endl;
   }

 return 0;
}

