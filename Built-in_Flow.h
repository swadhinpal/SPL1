#include<bits/stdc++.h>
#include"Segmentation.h"
using namespace std;

vector<vector<int>>Graph()
{
    int i,j,k=0,l,n,p,q,b=0,d,r;
    char ch;
    int *closing__braces;
    FILE *fp3;
    string s,s2="",s3="";
    vector<int>store_loop,case_,switch_,do_while;

    vector<string>line;
    line=segmentation();
    n=line.size();
    n++;

    vector<vector<int>> Control_Graph( n , vector<int> (n, 0));
    closing__braces=closing_curly_braces();

    for(i=1;i<n-1;i++)
    {
          Control_Graph[i][i+1]=1;
    }

    //cout<<line[2]<<endl;
    //s=line[2];
    //cout<<s[6];

   for(i=0;i<line.size();i++)
   {
       for(int kk:do_while)
       {
           if(i==kk) i++;
           //cout<<kk<<"kk"<<endl;
       }
       s=line[i];
       if(store_loop.size()!=0)
       {
           b= store_loop.back();
           if(closing__braces[b]==0&&i>b) store_loop.pop_back();
           else if(closing__braces[b]!=0&&closing__braces[b]<i)store_loop.pop_back();
       }

       for(j=0;j<=s.length();j++)
       {
          if(j==s.length()||s[j]==' '||s[j]=='('||s[j]==')'||s[j]=='{'||s[j]=='}')
          {
             fp3=fopen("Required_keyword.txt","r");
             ch=fgetc(fp3);
             if(fp3==NULL)
             {
                cout<<"Invalid";
                exit(1);
             }
             while(ch!=EOF)
             {
                if(ch!='\n')
                {
                  s3+=ch;
                }
                else
                {
                   if(s2==s3)
                   {
                      //cout<<s2<<endl;break;
                   }
                   else s3="";
                }
               ch=fgetc(fp3);
              }
            //s2="";
            fclose(fp3);
            if(s2=="for"||s2=="while")
            {
                l=i+1;
                //cout<<l<<" "<<closing__braces[l]<<endl;
                while(closing__braces[l]==0)
                {
                   l++;
                   if(l==line.size()) break;
                }
                store_loop.push_back(l);
                if(l!=line.size())
                {
                    Control_Graph[i+1][closing__braces[l]+1]=1;
                    Control_Graph[closing__braces[l]][closing__braces[l]+1]=0;
                    Control_Graph[closing__braces[l]][i+1]=1;
                }
            }
            else if(s2=="do")
            {
                l=i+1;
                string wh,ss1,ss2,ss="";
                //ss2=line[closing__braces[l]+1];
                //cout<<l<<" "<<closing__braces[l]<<endl;
                while(closing__braces[l]==0)
                {
                   l++;
                   if(l==line.size()) break;
                }
                k=0;
                 ss1=line[closing__braces[l]];
                for(p=0;p<ss1.length();p++)
                {
                   if(p==ss1.length()||ss1[p]==' '||ss1[p]=='('||ss1[p]==')'||ss1[p]=='{'||ss1[p]=='}')
                   {
                     if(ss=="while")
                     {
                        k=1;ss="";break;
                     }
                     else
                     {
                        ss="";
                     }
                   }
                  else
                  {
                     ss+=ss1[p];
                  }
                }
                //cout<<k<<"k"<<" "<<l<<"l"<<endl;
                if(k==1) {store_loop.push_back(l);do_while.push_back(closing__braces[l]);}
                else {store_loop.push_back(l+1);do_while.push_back(closing__braces[l]+1);}

                if(l!=line.size())
                {
                    if(k==1)
                    {
                      //Control_Graph[i+1][closing__braces[l]+1]=1;
                      //Control_Graph[closing__braces[l]][closing__braces[l]+1]=0;
                      Control_Graph[closing__braces[l]][i+1]=1;
                    }
                    else
                    {
                      //Control_Graph[i+1][closing__braces[l]+2]=1;
                      //Control_Graph[closing__braces[l]+1][closing__braces[l]+1]=0;
                      Control_Graph[closing__braces[l]+1][i+1]=1;
                    }
               }
            }
            else if(s2=="continue")
            {
                b= store_loop.back();
                if(closing__braces[b]==0)Control_Graph[i+1][b]=1;
                else Control_Graph[i+1][b-1]=1;
            }
            else if(s2=="break")
            {
               b= store_loop.back();
               if(closing__braces[b]==0)Control_Graph[i+1][b+1]=1;
               else Control_Graph[i+1][closing__braces[b]+1]=1;
            }

            else if(s2=="if")
            {
                int nxt_else=i;
                //cout<<i+1<<" "<<"i+1"<<" ";
                k=1;
                while(k)
                {
                  d=closing__braces[nxt_else+2];
                  string ss="", compare=line[d];
                  k=0;
                  //cout<<d+1<<" "<<compare<<endl;
                  for(p=0;p<=compare.length();p++)
                  {
                     if(p==compare.length()||compare[p]==' '||compare[p]=='('||compare[p]==')'||compare[p]=='{'||compare[p]=='}')
                     {
                       if(ss=="else")
                       {
                          k=1;ss="";
                          //cout<<d+1<<" ";
                          Control_Graph[i+1][d+1]=1;
                          Control_Graph[d][d+1]=0;
                          break;
                       }
                       else
                       {
                          ss="";
                       }
                     }
                    else
                    {
                       ss+=compare[p];
                    }
                  }
                  nxt_else=d;
                  //cout<<d<<" "<<"d"<<" "<<k<<" "<<"k"<<" ";
                }

            }
            else if(s2=="else")
            {
                j+=2;
            }
            else if(s2=="switch")
            {
               q=i+2;
               r=i;
               d=closing__braces[q];
               Control_Graph[q-1][q]=0;
               Control_Graph[q][q+1]=0;
               //cout<<d<<" "<<"d"<<" ";
                k=1;
                while(k)
                {
                  string ss="", compare=line[q];
                  //cout<<compare;
                  //cout<<d+1<<" "<<compare<<endl;
                  for(p=0;p<=compare.length();p++)
                  {
                     if(p==compare.length()||compare[p]==' '||compare[p]=='('||compare[p]==')'||compare[p]=='{'||compare[p]=='}'||compare[p]==':')
                     {
                       if(ss=="case"||ss=="default")
                       {
                          k=1;ss="";
                          //cout<<" "<<q+1<<" "<<"q+1"<<endl;
                          if(q!=i+2) Control_Graph[r+1][q+1]=1;
                          //Control_Graph[d][d+1]=0;
                          r=q;
                          break;
                       }
                       else if(ss=="break")
                       {
                           k=1;
                           //if(q==d-1) k==0;
                           //cout<<" "<<q+1<<" "<<"q+1"<<" ";
                           ss="";
                           Control_Graph[q+1][d+1]=1;
                           break;
                       }
                       /*else if(ss=="default")
                       {
                           k=1;ss="";
                           cout<<" "<<q+1<<" "<<"q+1"<<" ";
                           Control_Graph[r+1][q+1]=1;
                           break;
                       }*/
                       else
                       {
                          ss="";
                       }
                     }
                    else
                    {
                       ss+=compare[p];
                    }
                  }
                  q++;
                  if(q==d) break;
                }
                i=d+1;
            }

            s2="";
            }
            else
            {
               s2+=s[j];
            }
       }
   }

   /*cout<<line.size()<<endl;

   for(string x: line)
   {
        cout<<x<<endl;
   }

   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           if(i==0) {cout<<j<<" "; if(j<10) cout<<" ";}
           else if(j==0) {cout<<i<<" "; if(i<10) cout<<" ";}
           else cout<<Control_Graph[i][j]<<" "<<" ";
       }
       cout<<endl;
   }

   for(i=0;i<=line.size();i++)
   {
       cout<<closing__braces[i]<<" ";
   }*/

   return Control_Graph;
}
