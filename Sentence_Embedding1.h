#include<bits/stdc++.h>
#include"norm.h"
using namespace std;

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

