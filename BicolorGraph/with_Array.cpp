#include<bits/stdc++.h>
using namespace std;
int visit[100003];
int color[100005];
int node[1004][1004];
int qu[200005];
int start=0, size_=0;

int dequeue()
{
    start= start+1;
    return qu[start-1];

}
void enqueue(int x)
{
    qu[size_]=x;
    size_= size_+1;
}

main()
{
    memset(color, -1, sizeof(color));
    memset(visit,0,sizeof(visit));
    memset(node, 0, sizeof(node));

    freopen("bicolor.txt","r", stdin);
    int n_node, n_edge;
    cin>>n_node>>n_edge;
    int u,v;

    for(int i=0;i<n_edge;i++)
    {
        cin>>u>>v;
        node[u][v]=1;
        node[v][u]=1;
    }
    int s;

    cin>>s;

    color[s]=1;
    visit[s]=1;
    enqueue(s);
    bool flag=true;
    while(start<size_)
    {
        s=dequeue();
        for(int i=1;i<=n_node;i++)
        {
            if(node[s][i])
            {
                v= i;
                if(color[v]==-1)
                {
                    color[v]= color[s]^1;
                    enqueue(v);
                }
                else if(color[v]!=color[s])continue;
                else flag=false;
            }
        }
    }
    for(int i=1;i<=n_node;i++)
    {
        cout<<color[i]<<"  "<<i<<endl;
    }
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
