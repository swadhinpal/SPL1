#include<bits/stdc++.h>
using namespace std;

vector<string>segmentation(){
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
