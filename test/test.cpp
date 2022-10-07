#include<bits/stdc++.h>
using namespace std;


struct {
 int w, u ,v,n;
 int *child;

 call(int x)
 {
     int *ptr;
     ptr= (int *)calloc(n, sizeof(int));
     for(int i=0;i<n;i++)ptr[i]=child[i];
     child= (int *)calloc(x, sizeof(int));
     for(int i=0;i<n;i++)child[i]=ptr[i];
     n=x;
 }

}node[1000005];


int visit[100004];
int parant[100004];
int qu[1000003];
int frnt=0, size_=0;

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



int main()
{
    freopen("test.txt", "r", stdin);
    for(int i=0;i<10005;i++)
    {
        node[i].n=0;

        parant[i]=i;
    }
    memset(visit, 0, sizeof(visit));

    int n_node, n_edge;

     int v, u;
     cin>>n_node>>n_edge;
     for(int i=0;i<n_edge;i++)
     {
         cin>>u>>v;
         node[u].call(node[u].n+1);
         node[u].child[node[u].n-1]=v;
     }
      int s;
     vector< int> vt;
     for(int s_node=1;s_node<=n_node;s_node++)
    {
         if(visit[s_node])continue;
         frnt=size_=0;
         visit[s_node]=1;
         enqueue(s_node);
         stack<int> st;
         while(frnt<size_)
         {
             s=dequeue();
             st.push(s);

             for(int i=0;i<node[s].n;i++)
             {

                 v =node[s].child[i];
                 if(!visit[v])
                 {
                    visit[v]=1;
                    parant[v]=s;
                    enqueue(v);
                 }
             }
        }
        while(!st.empty())
        {vt.push_back(st.top()); st.pop();}
    }

    reverse(vt.begin(), vt. end());
    for(int i=0;i<vt.size(); i++)cout<<(char)(vt[i]+64)<<" ";
    cout<<endl;

    return 0;
}
