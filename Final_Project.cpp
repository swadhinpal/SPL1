#include<bits/stdc++.h>
using namespace std;

void Standardization()
{
    char p[200],ch,prv;
    FILE *fp, *fp1;
    char file_name[15];
    cout<<"Enter input file name: ";
    //cin>>file_name;
    fscanf(stdin, "%s", file_name);
    fp=fopen(file_name,"r");
    fp1=fopen("newfile.txt","w");

    if(fp==NULL||fp1==NULL)
    {
        cout<<"Error";
        exit(1);
    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        if(ch=='"')
        {
            fputc(ch,fp1);
            ch=fgetc(fp);
            while(ch!='"')
            {
                fputc(ch,fp1);
                ch=fgetc(fp);
            }
        }
        if(ch=='/')
        {
           ch=fgetc(fp);
           if(ch=='/')
          {
            while(ch!='\n')
            {
                ch=fgetc(fp);
            }
           }
           else if(ch=='*')
           {
               while(1)
               {
                   ch=fgetc(fp);
                while(ch!='*')
                 {
                   ch=fgetc(fp);
                 }
                ch=fgetc(fp);
                if(ch=='/') {ch=fgetc(fp); break;}
               }
           }
           else
           {
             fputc('/',fp1);
             //fputc(ch,fp1);
           }

        }
        prv=ch;
        if(ch=='{'||ch=='}') fputc('\n',fp1);
        if(ch!=' ') fputc(ch,fp1);
        if(ch=='{'||ch=='}') fputc('\n',fp1);
        ch=fgetc(fp);
        if(prv==' '&&(ch!='('||ch!='{'||ch!=' ')) fputc(' ',fp1);

    }

    fclose(fp);
    fclose(fp1);
}


vector<string>segmentation(){
//void segmentation(){
  FILE *fp2;
  char ch,str[2000],c;
  int i=0,length,j=0,k=0,l=0,cnt=0;
  string s="";
  vector<string>lines;

  fp2=fopen("newfile.txt","r");

  if(fp2==NULL)
  {
    cout<<"Error in file loading\n";
    exit(0);
  }

  ch=getc(fp2);
  while(ch!=EOF)
  {
      if(ch==','||ch==';')
      {
          ch=' ';
      }

      if(ch==' ')k++;
      if(k==2)
      {
        while(ch==' ')
        {
          ch=getc(fp2);
        }
        k=0;
      }

      if(ch!='\n')
      {
          str[i]=ch;
          length=i;
          i++;
          if(ch!=' ')k=0;
          if(ch!=' ')cnt=0;
      }
      else
      {
         if(cnt==0){
          //s+=to_string(j+1);
          for(i=0;i<=length;i++)
          {
             /*if(str[i]=='{')
                {
                    openning_curly_braces[j+1]++;
                    store.push_back(j+1);
                }
                else if(str[i]=='}')
                {
                    l=store.back();
                    store.pop_back();
                    closing_curly_braces[l]=j+1;
                }*/

             s+=str[i];
          }

          //cout<<s<<endl;
          lines.push_back(s);
          s="";
          j++;
          i=0;
          k=0;
          cnt++;
         }
        // else s="";
          //cout<<lines[j-1]<<endl<<endl;*/
      }
     //cout<<ch;
     ch=getc(fp2);
  }
  //cout<<j<<endl;
   fclose(fp2);
  return lines;
  //return 0;

}

int *closing_curly_braces()
{
    vector<string>line1;
    line1=segmentation();
    static int closing_braces[2000]={0};
    int openning_braces[2000]={0};
    vector<int>store;
    char x;
    int i,val;
    string s;
    for(i=0;i<line1.size();i++)
    {
        s=line1[i];
        for(char y:s)
        {
            if(y=='{')
            {
                    openning_braces[i+1]=1;store.push_back(i+1);
            }
            else if(y=='}')
            {
                val=store.back();
                store.pop_back();
                closing_braces[val]=i+1;
            }
        }

    }
  return closing_braces;
}

int *openning_curly_braces()
{
    int *closing_curly,i;
    static int openning_braces[2000]={0};
     vector<string>line2;
     line2=segmentation();
     closing_curly=closing_curly_braces();
     for(i=0;i<=line2.size();i++)
     {
         if(closing_curly[i]!=0) openning_braces[i]=1;
     }
  return openning_braces;
}

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

vector<vector<int>>Control_Graph()
{
    vector<string>line_,prototype_name,function_name,function_call;
    int return_[2000]={0};
    line_=segmentation();

    for(int i=0;i<line_.size();i++)
    {
       string sss=line_[i];
       //cout<<i+1<<" "<<sss<<endl;
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
 //cout<<"proto"<<endl;
   for(int i=0;i<prototype_name.size();i++)
   {
       //cout<<prototype_index[i]<<" "<<prototype_name[i]<<endl;
   }
 //cout<<"function body"<<endl;
   for(int i=0;i<function_name.size();i++)
   {
       //cout<<function_index[i]<<" "<<function_name[i]<<endl;
   }
    //cout<<"function call"<<endl;
   for(int i=0;i<function_call.size();i++)
   {
       for(int ww: fcall_index[i])
        {
            //cout<<ww<<" "<<function_call[i]<<endl;

        }
   }
   /*for(int i=1;i<size_;i++)
   {
       cout<<i<<"-> ";
       for(int j=1;j<size_;j++)
       {
          /* if(i==0) cout<<j<<" ";
           else if(j==0) cout<<i<<" ";
           else cout<<Control_Graph1[i][j]<<" "<<" ";*//*
            if(Control_Graph1[i][j]!=0) cout<<j<<" ";
       }
       cout<<endl;
   }*/

 return Control_Graph1;
}

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

vector<vector<int>>PDG()
{
    vector<string>line;
    line=segmentation();
    int sizze =line.size()+1;

    vector<vector<int>>Control__Graph,Data__Graph,PDG(sizze, vector<int>(sizze,0));
    Control__Graph=Control_Graph();
    Data__Graph=Data_Graph();

    for(int i=1;i<=line.size();i++)
    {
       for(int j=1;j<=line.size();j++)
       {
           if(Control__Graph[i][j]+Data__Graph[i][j]>0) PDG[i][j]=1;
           else PDG[i][j]=0;
       }
    }

    /*for(int i=0;i<line.size();i++)
    {
       cout<<i<<"-> ";
       for(int j=0;j<line.size();j++)
       {
           if(PDG[i][j]==1) cout<<j<<" ";
       }
       cout<<endl;
    }*/

    /*for(int i=0;i<sizze-1;i++)
    {
       for(int j=0;j<sizze-1;j++)
       {
           if(j==0) {cout<<i<<" ";if(i<10) cout<<" ";}
           else if(i==0) {cout<<j<<" ";if(j<10) cout<<" ";}
           else cout<<PDG[i][j]<<" "<<" ";
       }
       cout<<endl;
    }*/

return PDG;
}

vector<double>Degree_Centrality()
{
    vector<string>statement;
    statement=segmentation();
    int sizze =statement.size()+1;
    int N=sizze-2;
    //cout<<statement.size()<<" "<<N<<endl;
    double val;
    int in_Deg[sizze]={0},out_Deg[sizze]={0};
    vector<vector<int>>PDG1;
    vector<double>DC(sizze,0.0);
    PDG1=PDG();

    for(int i=1;i<sizze-1;i++)
    {
       for(int j=1;j<sizze-1;j++)
       {
           out_Deg[i]+=PDG1[i][j];
       }
    }

    cout<<"In-Degree:\n";
    for(int j=1;j<sizze-1;j++)
    {
       for(int i=1;i<sizze-1;i++)
       {
           in_Deg[j]+=PDG1[i][j];
       }
       //cout<<in_Deg[j]<<" ";
    }
    cout<<endl;
    cout<<"Out-Degree:\n";
    for(int i=1;i<sizze-1;i++)
    {
      val=(in_Deg[i]+out_Deg[i]);
      val/=(N-1);
      //cout<<out_Deg[i]<<" ";
      //cout<<setprecision(1)<<val<<" ";
      DC[i]= val;
    }
     cout<<endl;

    cout<<sizze-1<<"Degree Centrality:\n";
    for(int i=1;i<sizze;i++)
    {
        cout<<i<<":"<<setprecision(4)<<DC[i]<<endl;
    }

 return DC;
}

vector<double>Closeness_Centrality()
{
    double closeness(vector<vector<int>>PDG1,int s,int sizze);

    vector<string>statement;
    statement=segmentation();
    int sizze =statement.size()+1;

    int N=sizze-2,s,*d;
    double val;
    vector<vector<int>>PDG1;
    vector<double>CC(sizze,0.0);
    PDG1=PDG();

    for(int i=1;i<sizze-1;i++)
    {
        for(int j=1;j<sizze-1;j++)
        {
           //if(PDG1[i][j]==1) PDG1[j][i]=1;
        }
    }

    for(int i=0;i<sizze-1;i++)
    {
       for(int j=0;j<sizze-1;j++)
       {
           if(j==0) {cout<<i<<" ";if(i<10) cout<<" ";}
           else if(i==0) {cout<<j<<" ";if(j<10) cout<<" ";}
           else cout<<PDG1[i][j]<<" "<<" ";
       }
       cout<<endl;
    }
    /*d=path_BFS(PDG1,3,sizze);
    for(int i=1;i<sizze-1;i++)
    {
        cout<<i<<"(^_^)"<<d[i]<<endl;
    }*/
    for(int i=1;i<sizze;i++)
    {
        val=closeness(PDG1,i,sizze);
        if(val!=-1)val*=(N-1);
        else val=0;
        CC[i]=val;
    }
    for(int i=1;i<sizze;i++)
    {
        cout<<i<<":"<<CC[i]<<endl;
    }
   //val=closeness(PDG1,1,sizze);
   //cout<<val<<endl;
  return CC;
}

/*int *path_BFS(vector<vector<int>>PDG1,int s,int sizze)
{
    int colour[sizze]={-1},prev[sizze]={-1},dist=0;
    double closeness;
    static int d[2000]={-1};
    for(int i=0;i<sizze;i++) {d[i]=-1;prev[i]=-1;colour[i]=-1;}
    colour[s]=0; d[s]=0;
    queue<int>Q;
    Q.push(s);

    while(Q.size()!=0)
    {
        int u= Q.front();
        Q.pop();
        for(int i=1;i<sizze;i++)
        {
            //cout<<"YS"<<endl;
            //cout<<PDG1[u][i]<<" G C "<<colour[i]<<endl;
            if(PDG1[u][i]==1&&colour[i]==-1)
            {
                colour[i]=0;
                prev[i]=u;
                d[i]=d[u]+1;
                //cout<<i<<";;;;"<<d[i]<<endl;
                Q.push(i);
            }
        }

        colour[u]=1;
    }
    for(int i=1;i<sizze-1;i++)
    {
        if(d[i]!=-1) dist+=d[i];
    }
    cout<<dist<<endl;

   return d;
}*/

double closeness(vector<vector<int>>PDG1,int s,int sizze)
{
    int colour[sizze]={-1},prev[sizze]={-1};
    double closeness,dist=0.0;
    static int d[2000]={-1};
    for(int i=0;i<sizze;i++) {d[i]=-1;prev[i]=-1;colour[i]=-1;}
    colour[s]=0; d[s]=0;
    queue<int>Q;
    Q.push(s);

    while(Q.size()!=0)
    {
        int u= Q.front();
        Q.pop();
        for(int i=1;i<sizze;i++)
        {
            //cout<<"YS"<<endl;
            //cout<<PDG1[u][i]<<" G C "<<colour[i]<<endl;
            if(PDG1[u][i]==1&&colour[i]==-1)
            {
                colour[i]=0;
                prev[i]=u;
                d[i]=d[u]+1;
                //cout<<i<<";;;;"<<d[i]<<endl;
                Q.push(i);
            }
        }

        colour[u]=1;
    }
    for(int i=1;i<sizze-1;i++)
    {
        if(d[i]!=-1) dist+=d[i];
    }
    cout<<dist<<endl;
    if(dist!=0.0)closeness=1/dist;
    else closeness=-1;
    cout<<closeness<<endl;
   return closeness;
}

vector<double>Katz_Centrality()
{
    vector<vector<int>>A;
    A=PDG();
    int n=A.size();
    double alpha,beta=1,epsilon=0.01,maxEigenvalue=0.0,lambda=0.0;
    int max_iterations = 1000,i,j,k=0,p;
    vector<double>eigenvector(n,1.0/n),newEigenvector(n,0.0);
    //cout<<"katz"<<endl;

    //for(k=0;k<max_iterations;k++)
    //{
        do
        {
           if(k>max_iterations) break;
           maxEigenvalue=lambda;
           for(i=0;i<n;i++)
           {
              newEigenvector[i]=0.0;
              for(j=0;j<n;j++)
              {
                 newEigenvector[i]+=A[i][j]*eigenvector[j];
              }
           }

           double norm=0;
           for(j=0;j<n;j++)
           {
             norm+=(newEigenvector[j]*newEigenvector[j]);
           }

           norm=sqrt(norm);
           if(norm==0) norm=0.0001;
           for (j=0;j<n;j++)
           {
               newEigenvector[j]/=norm;
           }

           lambda=0.0;
           for(i=0;i<n;i++)
           {
              lambda+=newEigenvector[i];
           }
           //cout<<"l  "<<lambda<<endl;
           for(i=0;i<n;i++)
           {
              eigenvector[i]=newEigenvector[i];
           }
           k++;
         } while(fabs(lambda-maxEigenvalue)>epsilon);
    //}
    //cout<<"katz1"<<endl;
    if(lambda!=0)alpha=2/(3*lambda);
    else {cout<<"00000"<<endl;lambda=0.0001;alpha=2/(3*lambda);}
    cout<<"lambda "<<lambda<<" alpha "<<alpha<<endl;


    vector<double>x(n,1.0/n);
    for(k=0;k<max_iterations;k++)
    {
        vector<double>x_new(n,beta);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(A[i][j])
                {
                    x_new[i]+=alpha*A[i][j]*x[j];
                }
            }
        }
        double norm=0;
        for(j=0;j<n;j++)
        {
          norm+=(x_new[j]*x_new[j]);
        }

        norm=sqrt(norm);
        for (j=0;j<n;j++)
        {
            x_new[j]/=norm;
        }

        double error=0;
        for(j=0;j<n;j++)
        {
          error+=(x[j]*x[j]);
        }

        error=fabs(error - n);
        if(error < n * epsilon)
        {
            break;
        }
        x=x_new;
    }
     //cout<<"katz2"<<endl;
    for(int i=1;i<x.size();i++)
    {
        cout<<i<<"->"<<x[i]<<endl;
    }

    return x;
}

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

vector<vector<double>>embed1()
{
    vector<vector<string>>vec;
    vector<string>norm,var,func;
    vec=nor();
    norm=vec[0];
    var=vec[1];
    func=vec[2];
    int size_=norm.size();
    int var_size=var.size();
    int func_size=func.size();
    vector<string>var_store, func_store,built_in_func_store,keyword,symbol;
    vector<vector<int>>embed(size_ , vector<int> (50, 0));
    vector<vector<double>>embed1(size_ , vector<double> (50, 0.0));


    cout<<size_<<endl;
    for(string str:norm)
    {
        //cout<<str<<endl;
    }

    for(int i=0;i<=var_size;i++)
    {
        string s="var";
        s+=to_string(i);
        var_store.push_back(s);
        s="";
    }

    for(int i=0;i<=func_size;i++)
    {
        string s="func";
        s+=to_string(i);
        func_store.push_back(s);
        s="";
    }


    FILE *fp;
    fp=fopen("Required_Function.txt","r");
    char ch;
    string s="";
    built_in_func_store.push_back(s);
    built_in_func_store.push_back("built_in_func");
    if(fp==NULL)
    {
        cout<<"Invalid";
        exit(1);
    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        if(ch!='\n')
        {
            s+=ch;
        }
        else
        {
            built_in_func_store.push_back(s);
            s="";
        }
        ch=fgetc(fp);
    }
    fclose(fp);

    fp=fopen("All_keyword.txt","r");
    ch;
    s="";
    keyword.push_back(s);
    if(fp==NULL)
    {
        cout<<"Invalid";
        exit(1);
    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        if(ch!='\n')
        {
            s+=ch;
        }
        else
        {
            keyword.push_back(s);
            s="";
        }
        ch=fgetc(fp);
    }
    fclose(fp);

    fp=fopen("Symbols.txt","r");
    ch;
    s="";
    symbol.push_back(s);
    if(fp==NULL)
    {
        cout<<"Invalid";
        exit(1);
    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        if(ch!='\n')
        {
            s+=ch;
        }
        else
        {
            symbol.push_back(s);
            s="";
        }
        ch=fgetc(fp);
    }
    fclose(fp);

    for(int i=0;i<size_;i++)
    {
        int cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0;
        string s1=norm[i],s2="";
        cout<<i+1<<":"<<s1<<endl;
        for(int j=0;j<=s1.length();j++)
        {
            //var_store, func_store,built_in_func_store,keyword,symbol;
            if(j==s1.length()||s1[j]==' ')
            {
              bool present=false;
              if(s2==" "||s2=="") present=true;

              if(!present)for(int k=0;k<built_in_func_store.size();k++)
              {
                  //cout<<s2<<endl;

                  if(built_in_func_store[k]==s2) { if(cnt1==0){embed[i][0]=embed[i][0] | k;}
                  else if(cnt1<5)
                  {
                      if(cnt1==1){
                      embed[i][5]=embed[i][0] | k;
                      embed[i][10]=embed[i][0] & k;
                      }
                      else{
                        embed[i][10*cnt1-5]=embed[i][10*(cnt1-1)-5] | k;
                        embed[i][10*cnt1]=embed[i][10*(cnt1-1)-5] & k;
                      }
                  }
                  else{
                     embed[i][45]=embed[i][35] | k;
                  }
                  cnt1++;
                  present=true;break;}
              }
              if(!present)for(int k=0;k<keyword.size();k++)
              {
                  //if(keyword[k]==s2) {embed[i][1]=embed[i][1] | k;present=true;break;}
                  if(keyword[k]==s2) { if(cnt2==0){embed[i][1]=embed[i][1] | k;}
                  else if(cnt2<5)
                  {
                      if(cnt2==1){
                      embed[i][6]=embed[i][1] | k;
                      embed[i][11]=embed[i][1] & k;}
                      else{
                        embed[i][(10*cnt2)-4]=embed[i][(10*(cnt2-1))-4] | k;
                        embed[i][(10*cnt2)+1]=embed[i][(10*(cnt2-1))-4] & k;
                      }
                  }
                  else{
                     embed[i][46]=embed[i][36] | k;
                  }
                  cnt2++;
                  present=true;break;}
              }
              if(!present)for(int k=0;k<var_store.size();k++)
              {
                  //if(var_store[k]==s2) {embed[i][2]=embed[i][2] | k;present=true;break;}
                  if(var_store[k]==s2) { if(cnt3==0){embed[i][2]=embed[i][2] | k;}
                  else if(cnt3<5)
                  {
                      if(cnt3==1){
                      embed[i][7]=embed[i][2] | k;
                      embed[i][12]=embed[i][2] & k;}
                      else{
                        embed[i][10*cnt3-3]=embed[i][10*(cnt3-1)-3] | k;
                        embed[i][10*cnt3+2]=embed[i][10*(cnt3-1)-3] & k;
                      }
                  }
                  else{
                     embed[i][47]=embed[i][37] | k;
                  }
                  cnt3++;
                  present=true;break;}
              }
              if(!present)for(int k=0;k<func_store.size();k++)
              {
                  //if(func_store[k]==s2) {embed[i][3]=embed[i][3] | k;present=true;break;}
                  if(func_store[k]==s2) { if(cnt4==0){embed[i][3]=embed[i][3] | k;}
                  else if(cnt4<5)
                  {
                      if(cnt4==1){
                      embed[i][8]=embed[i][3] | k;
                      embed[i][13]=embed[i][3] & k;}
                      else{
                        embed[i][10*cnt4-2]=embed[i][10*(cnt4-1)-2] | k;
                        embed[i][10*cnt4+3]=embed[i][10*(cnt4-1)-2] & k;
                      }
                  }
                  else{
                     embed[i][48]=embed[i][38] | k;
                  }
                  cnt4++;
                  present=true;break;}
              }
              if(!present)for(int k=0;k<symbol.size();k++)
              {
                  //if(symbol[k]==s2) {embed[i][4]=embed[i][4] | k;present=true;break;}
                  if(symbol[k]==s2) { if(cnt5==0){embed[i][4]=embed[i][4] | k;}
                  else if(cnt5<5)
                  {
                      if(cnt5==1){
                      embed[i][9]=embed[i][4] | k;
                      //if(embed[i][9]>100||embed[i][9]<-100) cout<<"k:"<<k<<" ";
                      embed[i][14]=embed[i][4] & k;}
                      else{
                        embed[i][10*cnt5-1]=embed[i][10*(cnt5-1)-1] | k;
                        embed[i][10*cnt5+4]=embed[i][10*(cnt5-1)-1] & k;
                      }
                  }
                  else{
                     embed[i][49]=embed[i][39] | k;
                  }
                  cnt5++;
                  present=true;break;}
              }
              s2="";
            }
            else
            {
                s2+=s1[j];
            }
        }
    }

    for(string str:keyword)
    {
        //cout<<str<<endl;
    }
    for(string str:symbol)
    {
        //cout<<str<<endl;
    }
    cout<<embed.size()<<endl;

    for(int i=0;i<size_;i++)
    {
        for(int j=0;j<50;j++)
        {
            if(embed[i][j]==0&&j>4&&j<10)
            {
                embed[i][j]=embed[i][j-5];
            }
            else if(embed[i][j]==0&&j>9)
            {
                embed[i][j]=embed[i][j-10];
            }
        }
    }

    for(int i=0;i<size_;i++)
    {
        cout<<i<<":"<<" ";
        for(int j=0;j<50;j++)
        {
            cout<<embed[i][j]<<" ";
            embed1[i][j]=double(embed[i][j]);
        }
        cout<<endl;
    }
    cout<<"double"<<endl;
    for(vector<double>v:embed1)
    {
        for(double val: v)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    //vector<vector<int>>embed(size_ , vector<int> (20, 0));


    return embed1;
}

vector<vector<double>>RED()
{
    vector<vector<double>>embed;
    embed=embed1();
    vector<vector<double>>RED_Vec(embed.size(),vector<double>(50,0.0));
    vector<double>Degree__Centrality;
    Degree__Centrality=Degree_Centrality();



    for(int i=1;i<Degree__Centrality.size();i++)
    {
        int j=i-1;
        for(int k=0;k<50;k++)
        {
            RED_Vec[j][k]=embed[j][k]*Degree__Centrality[i];
        }
        //cout<<i<<":"<<Degree__Centrality[i]<<endl;
    }

    for(int i=0;i<RED_Vec.size();i++)
    {
        for(int j=0;j<50;j++)
        {
            //cout<<RED_Vec[i][j]<<" ";
        }
        //cout<<endl;
    }

    return RED_Vec;
}

vector<vector<double>>GREEN()
{
    vector<vector<double>>embed;
    embed=embed1();
    vector<vector<double>>GREEN_Vec(embed.size(),vector<double>(50,0.0));
    vector<double>Closeness__Centrality;
    Closeness__Centrality=Closeness_Centrality();



    for(int i=1;i<Closeness__Centrality.size();i++)
    {
        int j=i-1;
        for(int k=0;k<50;k++)
        {
            GREEN_Vec[j][k]=embed[j][k]*Closeness__Centrality[i];
        }
    }

    for(int i=0;i<GREEN_Vec.size();i++)
    {
        for(int j=0;j<50;j++)
        {
            //cout<<GREEN_Vec[i][j]<<" ";
        }
        //cout<<endl;
    }
return GREEN_Vec;
}

vector<vector<double>>BLUE()
{
    vector<vector<double>>embed;
    embed=embed1();
    vector<vector<double>>BLUE_Vec(embed.size(),vector<double>(50,0.0));
    vector<double>Katz__Centrality;
    Katz__Centrality=Katz_Centrality();


    for(int i=1;i<Katz__Centrality.size();i++)
    {
        int j=i-1;
        for(int k=0;k<50;k++)
        {
            BLUE_Vec[j][k]=embed[j][k]*Katz__Centrality[i];
        }

    }

    for(int i=0;i<BLUE_Vec.size();i++)
    {
        for(int j=0;j<50;j++)
        {
            cout<<BLUE_Vec[i][j]<<" ";
        }
        cout<<endl;
    }

    return BLUE_Vec;
}

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMPInfoHeader;
#pragma pack(pop)

int main()
{
    // Pixel values for the RGB image
    Standardization();

    char image_name[15];
    cout<<"\nEnter image file name: ";
    fscanf(stdin, "%s", image_name);
    vector<vector<double>>R,G,B;
    R=RED();
    G=GREEN();
    B=BLUE();
    int h= R.size();

    /*float R[3][4] = {{1,1,1,1},{1,2,3,3},{1.1,3.5,6,7}};
    float G[3][4] = {{69,122,122,122},{255,255,255,200},{24,36.3,46.4,56.5}};
    float B[3][4] = {{9,8,7,6},{1,1,2,2},{3,4.4,5.5,6.6}};*/

    // BMP image dimensions
    int width =50;
    int height =h;

    // BMP header data
    BMPHeader bmpHeader = {0};
    bmpHeader.type = 0x4D42;
    bmpHeader.size = sizeof(BMPHeader) + sizeof(BMPInfoHeader) + width * height * 3;
    bmpHeader.offset = sizeof(BMPHeader) + sizeof(BMPInfoHeader);

    // BMP info header data
    BMPInfoHeader bmpInfoHeader = {0};
    bmpInfoHeader.size = sizeof(BMPInfoHeader);
    bmpInfoHeader.width = width;
    bmpInfoHeader.height = height;
    bmpInfoHeader.planes = 1;
    bmpInfoHeader.bitsPerPixel = 24;
    bmpInfoHeader.compression = 0;
    bmpInfoHeader.imageSize = width * height * 3;
    bmpInfoHeader.xPixelsPerMeter = 0;
    bmpInfoHeader.yPixelsPerMeter = 0;
    bmpInfoHeader.colorsUsed = 0;
    bmpInfoHeader.colorsImportant = 0;

    // Create the BMP file
    FILE* file = fopen(image_name, "wb");
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    // Write pixel data
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            uint8_t r = R[y][x] * 255;
            uint8_t g = G[y][x] * 255;
            uint8_t b = B[y][x] * 255;

            fwrite(&b, sizeof(uint16_t), 1, file);
            fwrite(&g, sizeof(uint16_t), 1, file);
            fwrite(&r, sizeof(uint16_t), 1, file);
        }
    }

    fclose(file);

    return 0;
}







