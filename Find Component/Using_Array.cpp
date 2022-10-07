#include<bits/stdc++.h>
using namespace std;
int qu[100005];
int node[1004][1005];
int frnt=0, size_=0;
int visit[200004];
void enqueue(int x)
{
    qu[size_]=x;
    size_= size_+1;
}
int dequeue()
{
    return qu[frnt++];
}

void bfs(int cnt, int s, int n_node)
{
    enqueue(s);

    while(frnt<size_)
    {
        int s= dequeue();
        for(int i=0;i<=n_node;i++)
        {
            if(node[s][i] && !visit[i])
            {
                 visit[i]=cnt;
                 enqueue(i);
            }
        }
    }
}
int main()
{
    freopen("findComponent.txt", "r", stdin);
    memset(node, 0, sizeof(node));
    memset(visit, 0, sizeof(visit));

    int n_node, n_edge;
    cin>>n_node>>n_edge;
    int u, v,cnt=0;
    for(int i=0;i<n_edge;i++)
    {
        cin>>u>>v;
        node[u][v]=1;
        node[v][u]=1;
    }

     for(int i=0;i<=n_node;i++)
     {
         if(!visit[i])
         {
             frnt=size_=0;
             cnt++;
             visit[i]=cnt;
             bfs(cnt,i,n_node);
         }
     }

    for(int i=0;i<=n_node; i++)
    {
        cout<<i<<"   "<<visit[i]<<endl;
    }
    cout<<"Component is : "<<cnt<<endl;

    return 0;
}
