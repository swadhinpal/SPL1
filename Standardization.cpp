#include<bits/stdc++.h>
using namespace std;

int main()
{
    char p[200],ch;
    FILE *fp, *fp1;

    fp=fopen("BST.txt","r");
    fp1=fopen("newfile.txt","w");

    if(fp==NULL||fp1==NULL)
    {
        cout<<"Error";
        exit(1);
    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
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
        fputc(ch,fp1);
        ch=fgetc(fp);
    }

    fclose(fp);
    fclose(fp1);
}
