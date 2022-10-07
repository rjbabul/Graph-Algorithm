#include<bits/stdc++.h>
using namespace std;

/// Create graph using Struct
struct
{
    int w, u,v,n;
    int *child;

    call(int x)
    {
        int *ptr;
        ptr= (int *)calloc(n, sizeof(int));
        for(int i=0; i<n; i++)
            ptr[i]=child[i];
        child= (int *)calloc(x, sizeof(int));
        for(int i=0; i<n; i++)
            child[i]=ptr[i];
        n=x;
    }

} node[1000005];


int visit[100004];
int qu[1000003];
int frnt=0, size_=0;

/// Queue start
void enqueue(int x)
{
    qu[size_]=x;
    size_ = size_+1;
}
int dequeue()
{
    frnt=frnt+1;
    return qu[frnt-1];
}

///  -----------------Queue End -----------

int main()
{
    freopen("topsort.txt", "r", stdin);

    /// initialization
    for(int i=0; i<10005; i++)
    {
        node[i].n=0;
    }
    memset(visit, 0, sizeof(visit));
    /// end Initialization


    int n_node, n_edge;

    int v, u;
    cin>>n_node>>n_edge;
    /// edge insert into Graph

    for(int i=0; i<n_edge; i++)
    {
        cin>>u>>v;
        node[u].call(node[u].n+1);
        node[u].child[node[u].n-1]=v;
    }

    int s,n=n_node;
    int vt[n_node+1];
    /// Processing Topological short
    for(int s_node=1; s_node<=n_node; s_node++)
    {
        if(visit[s_node])
            continue;
        frnt=size_=0;
        visit[s_node]=1;
        enqueue(s_node);
        int stack_[n_node+1],top=0;
        while(frnt<size_)
        {
            s=dequeue();

            stack_[top]=s;
            top++;
            for(int i=0; i<node[s].n; i++)
            {

                v =node[s].child[i];
                if(!visit[v])
                {
                    visit[v]=1;
                    enqueue(v);
                }
            }
        }

        while(top)
        {
            vt[n]=stack_[top-1];
            n--;
            top--;
        }
    }
    /// Ending topological short

    /// Output result
    for(int i=1; i<=n_node; i++)
        cout<<(char)(vt[i]+64)<<" ";
    cout<<endl;

    return 0;
}
