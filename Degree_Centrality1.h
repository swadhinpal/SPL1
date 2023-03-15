#include<bits/stdc++.h>
#include"PDG.h"
using namespace std;

vector<double>Degree_Centrality()
{
    vector<string>statement;
    statement=segmentation();
    int sizze =statement.size()+1;
    int N=sizze-2;
    //cout<<statement.size()<<" "<<N<<endl;
    double val;
    int in_Deg[sizze], out_Deg[sizze];
    in_Deg[sizze]={0},out_Deg[sizze]={0};
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



	
