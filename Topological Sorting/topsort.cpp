#include<bits/stdc++.h>
using namespace std;
int order[200003];
int visit[200004];
stack<int> st;
void dfs(int s ,vector<int>&temp, vector<int>node[])
{
   int u;
   while(!st.empty())
   {
       u= st.top();
       bool flag=false;

       for(int i=0;i<node[u].size();i++){
          if(visit[node[u][i]]==0)
          {
              visit[node[u][i]]=1;
              flag=true;
              st.push(node[u][i]);
              break;
          }
       }
         if(!flag)
          {

              temp.push_back(u);
              st.pop();
          }
   }

}
int main()
{
    freopen("topsort.txt","r", stdin);
    int n,u,v,m;
    cin>>n>>m;

    vector<int > node[n+1];

    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        node[u].push_back(v);
    }

    memset(order, 0, sizeof(order));
    memset(visit, 0, sizeof(visit));
    vector<int>temp;
    for(int i=1;i<=n;i++){
         if(!visit[i])
         {

             st.push(i);
             visit[i]=1;
             dfs(i,temp, node);
         }
    }
    reverse(temp.begin(), temp.end());
    for(int i=0;i<temp.size();i++)cout<<(char)(temp[i]+64)<<" ";cout<<endl;

    return 0;
}
