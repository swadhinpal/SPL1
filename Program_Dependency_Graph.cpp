#include<bits/stdc++.h>
//#include"Control_Dependency__Graph.h"
#include"Data_Dependency__Graph.h"
//#include"Header1.h"
using namespace std;

int main()
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

    for(int i=0;i<line.size();i++)
    {
       cout<<i<<"-> ";
       for(int j=0;j<line.size();j++)
       {
           if(PDG[i][j]==1) cout<<j<<" ";
       }
       cout<<endl;
    }

return 0;
}

