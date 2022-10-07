#include<bits/stdc++.h>
using namespace std;
#define inf 10000
int node[1000][100];
void init(int n , int m)
{
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++){if(i==j)node[i][j]=0; else node[i][j]=inf; }
}


int main()
{
    freopen("Floyd_Warshall.txt","r", stdin);
    int m ,n, u, v, w;
    while(cin>>n>>m)
    {

       init(n,m);

       for(int i=1;i<=m;i++)
       {
           cin>>u>>v>>w;
           node[u][v]=w;
           node[v][u]=w;
       }

       for(int k=1;k<=n;k++)
       {
           for(int i=1;i<=n;i++)
           {
               for(int j=1;j<=n;j++)
               {
                   node[i][j]= min(node[i][j], node[i][k]+node[k][j]);
               }
           }
       }

       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
           {
               cout<<node[i][j]<<" ";
           }
           cout<<endl;
       }

        ;
    }
    return 0;
}
