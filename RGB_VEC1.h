#include<bits/stdc++.h>
#include"Sentence_Embedding1.h"
using namespace std;

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


