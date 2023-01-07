#include<bits/stdc++.h>
using namespace std;

int main()
{
  FILE *fp;
  char ch,str[2000],c;
  int i=0,length,j=0,k=0,l=0,cnt=0;
  int openning_curly_braces[2000]={0},closing_curly_braces[2000]={0};
  string s="";
  vector<string>lines;
  vector<int>store;

  fp=fopen("BST.c","r");

  if(fp==NULL)
  {
    cout<<"Error in file loading\n";
    exit(0);
  }

  ch=getc(fp);
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
          ch=getc(fp);
        }
        k=0;
      }

      if(ch!='\n')
      {
          str[i]=ch;
          length=i;
          i++;
          if(ch!=' ')k=0;
          cnt=0;
      }
      else
      {
         if(cnt==0){
          s+=to_string(j+1);
          for(i=0;i<=length;i++)
          {
             if(str[i]=='{')
                {
                    openning_curly_braces[j+1]++;
                    store.push_back(j+1);
                }
                else if(str[i]=='}')
                {
                    l=store.back();
                    store.pop_back();
                    closing_curly_braces[l]=j+1;
                }

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
          //cout<<lines[j-1]<<endl<<endl;*/
      }
     //cout<<ch;
     ch=getc(fp);
  }
  //cout<<j<<endl;
  for(string x: lines)
  {
      cout<<x<<endl<<endl;
  }
  cout<<"openning"<<endl;
  for(i=0;i<=200;i++)
  {
      cout<<openning_curly_braces[i]<<" ";
  }
  cout<<endl<<"closing"<<endl;
  for(i=0;i<=200;i++)
  {
      cout<<closing_curly_braces[i]<<" ";
  }

  fclose(fp);

  return 0;
}
