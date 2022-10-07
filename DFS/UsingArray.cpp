#include<bits/stdc++.h>
using namespace std;

int parent[100003];
int visit[100004];
int level[100006];
int travalse[100004];
int qu[100005];
int node[1002][1004];

int top =-1, t_index=0;

int n_node, m_edge, start_node;

void inqueue(int x)
{
    qu[++top]=x;
}

int queue_top()
{
    return qu[top];
}
void dequeue()
{
    top--;
}

void dfs()
{

    int s= queue_top();
    travalse[t_index]=s;
    t_index++;
    for(int i=1;i<=n_node;i++)
    {
        if(node[s][i])
        {

            int v=i;
            if(visit[v]==0)
            {
                visit[v]=1;
                level[v]= level[s]+1;
                parent[v]=s;
                inqueue(v);
                dfs();
            }
        }

    }
    dequeue();
}

int main()
{
    int v, u;
    freopen("dfs.txt", "r", stdin);

    memset(level, 0, sizeof(level));
    memset(visit, 0, sizeof(visit));
    memset(node, 0, sizeof(node));

    cin>>n_node>>m_edge;

    for(int i=1;i<=n_node; i++) parent[i]=i;

    for(int i=0;i<m_edge;i++)
    {

        cin>>u>>v;
        node[u][v]=1;
        node[v][u]=1;
    }

    cin>>start_node;
    level[start_node]=0;
    visit[start_node]=1;
    inqueue(start_node);
    travalse[t_index++]= start_node;

    dfs();


    for(int i=1;i<=n_node;i++)
    {
        cout<<travalse[i]<<" ";
    }
    cout<<endl;

    int s=9;
    while(parent[s]!=s)
    {
        cout<<s<<"->";
        s=parent[s];
    }
    cout<<s<<endl;

}
