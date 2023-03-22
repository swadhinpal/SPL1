
#include<bits/stdc++.h>
#include"PDG.h"
using namespace std;

int main()
{
    vector<vector<int>>A;
    A=PDG();
    int n=A.size();
    double alpha,beta=1,epsilon=0.01,maxEigenvalue=0.0,lambda=0.0;
    int max_iterations = 1000,i,j,k,p;
    vector<double>eigenvector(n,1.0/n),newEigenvector(n,0.0);

    for(k=0;k<max_iterations;k++)
    {
        do
        {
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
         } while(fabs(lambda-maxEigenvalue)>epsilon);
    }

    alpha=2/(3*lambda);
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

    for(int i=1;i<x.size();i++)
    {
        cout<<i<<"->"<<x[i]<<endl;
    }

    return 0;
}





	
