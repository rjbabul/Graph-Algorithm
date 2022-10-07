#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
struct {
    int u;
    int v;
    int w;
}queue_[200005];

int node[1003][1004];
int dist[100005];
int frnt=0, size_=0;
int parant[100005];
void enqueue(int v, int w)
{
    queue_[size_].v=v;
    queue_[size_].w=w;
    size_= size_+1;
}
void dequeue()
{
    frnt=frnt+1;
}
int main()
{

    freopen("dijkstra.txt","r", stdin);

    memset(node, 0, sizeof(node));
    for(int i=0;i<100004;i++) dist[i]=inf, parant[i]=i;

    int n_node, n_edge,u,v,w, s_node;
    cin>>n_node>>n_edge;
    for(int i=0;i<n_edge;i++)
    {
        cin>>u>>v>>w;
        node[u][v]=w;
        node[v][u]=w;
    }
    cin>>s_node;
    dist[s_node]=0;
    enqueue(s_node,dist[s_node]);
    while(frnt<size_)
    {
        w= queue_[frnt].w;
        u= queue_[frnt].v;
        dequeue();

        for(int i=0;i<=n_node; i++)
        {
            if(node[u][i]>0)
            {
                v=i;
                if(dist[u]+node[u][i] < dist[v]) {
                    dist[v]= dist[u]+node[u][i];
                    enqueue(v,dist[v]);
                    parant[v]=u;
                }
            }
        }
    }

     for(int i=1;i<=n_node;i++)
    {
        cout<<i<<setw(5)<<dist[i]<<setw(5);
        u = i;
        while(parant[u]!=u){
            cout<<u<<"-->";
            u=parant[u];
        }
        cout<<u<<endl;
    }
    return 0;
}
