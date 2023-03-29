#include<bits/stdc++.h>
#include"Degree_Centrality1.h"
using namespace std;
//double closeness(vector<vector<int>>PDG1,int s,int sizze);

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




	
