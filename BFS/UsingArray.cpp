#include<bits/stdc++.h>
using namespace std;
int q[200005];
int front_=0, size_=0;
int node[1000][1000];
int visit[1000];
int parent[200004];
int travals[200004];
int level[200004];

void inqueue(int x)
{
    q[size_]=x;
    size_= size_ + 1;
}
int dequeue()
{
    front_ = front_ + 1;
    return  q[front_ -1];
}


int main()
{
    freopen("input.txt", "r", stdin);

    int n_node , m_edge,u,v;

    memset(node, 0, sizeof(node));
    memset(level, 0, sizeof(level));
    cin>>n_node>>m_edge;
    for(int i=1;i<=n_node; i++) parent[i]=i;

    for(int i=0;i<m_edge ; i++)
    {
        cin>>u>>v;
        node[u][v]=1;
        node[v][u]=1;  /// undirected graph

    }
    int start_node,s;

    cin>>start_node;
    inqueue(start_node);
    visit[start_node]= 1;
    level[start_node]=0;
   int j=0;
    while(front_<=size_)
    {
        s =  dequeue();
        travals[j++]=s;

        for(int i=1; i<=n_node;i++)
        {
            if(node[s][i]==1){
                v=i;
                if(visit[v]==0)
                {
                    visit[v]=1;
                    parent[v]=s;
                    inqueue(v);
                    level[v]= level[s]+1;
                }
            }
        }

    }
    cout<<"Node"<<setw(6)<<"Level"<<setw(6)<<"Path"<<endl;
    for(int i=1; i<=n_node;i++){
        cout<<setw(2)<<i<<setw(6)<<level[i]<<setw(6);
        s=i;
        while(parent[s]!=s){
            cout<<s<<"->";
            s= parent[s];
        }
        cout<<s<<endl;
    }

    return 0;
}
