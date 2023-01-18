#include<bits/stdc++.h>
#include"Built-in_flow.h"
using namespace std;

int main()
{
    vector<string>line_,prototype_name,function_name,function_call;
    int return_[2000]={0};
    line_=segmentation();

    for(int i=0;i<line_.size();i++)
    {
       string sss=line_[i];
       cout<<i+1<<" "<<sss<<endl;
    }

    int *closing_braket,size_;
    closing_braket=closing_curly_braces();
    int prototype_index[200],function_index[200];
    vector<set<int>>fcall_index;
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
             /*fp4=fopen("Required_keyword.txt","r");
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

            fclose(fp4);*/

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

                if(!is_built_in_func/*&&!is_keyword*/)
                {
                     //cout<<y+1<<" "<<s22<<endl;
                    if(s22!="for"&&s22!="while"&&s22!="switch"&&s22!="if"&&s22!="main")
                    {
                        //cout<<y+1<<" "<<s22<<" ";
                        //cout<<"Not built in"<<endl;
                        if(closing_braket[y+2]==0)
                        {
                            string st1="",st2="";
                            int keyword=0;
                            for(int x=0;x<s.length();x++)
                            {
                               //cout<<s<<endl;
                               if(s[x]==' '||s[x]=='='||s[x]=='('||s[x]==')')
                               {
                               if(s22!=st1){
                                if(s[x]=='='||s[x]=='('||s[x]==')') keyword=0;
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
                                    //if(s[x]!='=')
                                    keyword++;
                                    //else keyword=0;
                                    //cout<<st1<<endl;
                                    //cout<<st1<<endl;break;
                                  }
                                  else st2="";
                                }
                               ch=fgetc(fp4);
                               }

                              fclose(fp4);
                              st1="";
                            }
                            else break;

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
                            bool included=false;
                            int pp;
                            //cout<<s22<<endl;
                            for(pp=0;pp<function_call.size();pp++)
                            {
                                 if(function_call[pp]==s22){included=true;break;}
                            }
                            if(included)
                            {
                                //function_call.push_back(s22);
                                //cout<<s22<<"in"<<endl;
                                set<int> ss;
                                ss=fcall_index[pp];
                                ss.insert(y+1);
                                fcall_index[pp]=ss;
                                //fcall_index[function_call.size()-1]=y+1;
                            }
                            else
                            {

                                function_call.push_back(s22);
                                set<int> ss;
                                ss.insert(y+1);

                                //cout<<function_call.size()-1<<endl;
                                fcall_index.push_back(ss);
                            }
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

            if(s22=="return") {return_[y+1]=1; Control_Graph1[y+1][y+2]=0;/*cout<<y+1<<endl;*/}

            s22="";
           }

           else
           {
              s22+=s[t];
           }
        }
    }

   //cout<<"abc"<<endl;

    for(int ii=0;ii<function_call.size();ii++)
    {
        int jj,idx;
        string ss= function_call[ii];
        for(int ww: fcall_index[ii])
        {
            //Control_Graph1[ww][ww+1]=0;
        }
        bool proto=false;
        for(jj=0;jj<prototype_name.size();jj++)
        {
            if(prototype_name[jj]==ss)
            {
                Control_Graph1[prototype_index[jj]-1][prototype_index[jj]]=0;
                 for(int ww: fcall_index[ii])
                 {
                     Control_Graph1[ww][prototype_index[jj]]=1;
                 }

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
                    for(int ww: fcall_index[ii])
                    {
                      //0Control_Graph1[closing_braket[function_index[kk]+1]][ww+1]=1;
                    }
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
                    for(int ww: fcall_index[ii])
                    {

                           Control_Graph1[ww][function_index[kk]]=1;
                           //0Control_Graph1[closing_braket[function_index[kk]+1]][ww+1]=1;

                    }
                }
            }
        }
    }

    if(prototype_name.size()!=0){
    Control_Graph1[prototype_index[0]-1][prototype_index[prototype_name.size()-1]+1]=1;
    Control_Graph1[prototype_index[prototype_name.size()-1]][prototype_index[prototype_name.size()-1]+1]=0;}

    //cout<<return_[15]<<" "<<return_[21]<<endl;
     for(int i=0;i<function_name.size();i++)
     {
         //cout<<function_name[i]<<" "<<function_index[i]<<" "<<closing_braket[function_index[i]+1]<<endl;
         bool present=false;
         for(int j=function_index[i];j<closing_braket[function_index[i]+1];j++)
         {
             //cout<<function_name[i]<<" "<<j<<endl;
             if(return_[j]==1)
             {
                 //cout<<function_name[i]<<"return"<<j<<endl;
                 for(int aa=0;aa<function_call.size();aa++)
                 {
                     if(function_call[aa]==function_name[i])
                     {
                         for(int ww: fcall_index[aa])
                         {
                             //cout<<j<<" "<<ww<<"jww"<<endl;
                            Control_Graph1[j][ww]=1;
                         }
                     }
                 }
                 present=true;
             }
         }
         if(!present)
         {
             for(int aa=0;aa<function_call.size();aa++)
                 {
                     if(function_call[aa]==function_name[i])
                     {
                         for(int ww: fcall_index[aa])
                         {
                            Control_Graph1[closing_braket[function_index[i]+1]][ww]=1;
                         }
                     }
                 }
         }
     }
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
       for(int ww: fcall_index[i])
        {
            cout<<ww<<" "<<function_call[i]<<endl;

        }
   }
   for(int i=1;i<size_;i++)
   {
       cout<<i<<"-> ";
       for(int j=1;j<size_;j++)
       {
          /* if(i==0) cout<<j<<" ";
           else if(j==0) cout<<i<<" ";
           else cout<<Control_Graph1[i][j]<<" "<<" ";*/
            if(Control_Graph1[i][j]!=0) cout<<j<<" ";
       }
       cout<<endl;
   }

 return 0;
}
