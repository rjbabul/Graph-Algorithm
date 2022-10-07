#include<bits/stdc++.h>
using namespace std;

int parent[100003];
int visit[100004];
int level[100006];
int travalse[100004];

vector<int> node[10002];

stack<int>st;

int n_node, m_edge, start_node;

int t_index=0;

void dfs()
{

    int s= st.top();
    travalse[t_index++]=s;

    for(int i=0;i<node[s].size();i++)
    {
            int v=node[s][i];
            if(visit[v]==0)
            {
                visit[v]=1;
                level[v]= level[s]+1;
                parent[v]=s;
                st.push(v);
                dfs();
            }
    }
   st.pop();
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

        node[u].push_back(v);
        node[v].push_back(u);
    }

    cin>>start_node;

    level[start_node]=0;
    visit[start_node]=1;

    st.push(start_node);

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
