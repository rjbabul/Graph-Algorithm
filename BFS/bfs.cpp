#include<bits/stdc++.h>
using namespace std;
int level[200004],visit[200005];
int parant[200004];
vector<int > node[200005];
void bfs(vector<int> vt[], int s){
   queue<int>  q;
   q.push(s);
   memset(visit, 0, sizeof(visit));
   memset(parant, 0 , sizeof(parant));
   level[s]=0;

   visit[s]=1;
   parant[s]=s;
   int u,v;
   while(!q.empty())
   {
       s= q.front();
       q.pop();
       for(int i=0;i<vt[s].size();i++){
        v=vt[s][i];
        if(visit[v]==0)
            {
             q.push(v);
             visit[v]=1;
             parant[v]=s;
             level[v]= level[s]+1;

            }
       }
   }
   cout<<"Node"<<"   "<<"level"<<"   "<<"path"<<endl;
   for(int i=1;i<=20;i++)
   {
       s=i;

        cout<<setw(2)<<i<<"  "<<setw(6)<<level[i]<<setw(6)<<"";
       while(parant[s]!=s){
        cout<<s<<"-->";
        s= parant[s];
       }
       cout<<s<<endl<<endl;
   }

}
int main()
{
    freopen("input.txt", "r", stdin);
    int n,u,v,m;
    cin>>n>>m;
    while(m-- && cin>>u>>v){
         node[u].push_back(v);
         node[v].push_back(u);
    }
    bfs(node, 1);
    return 0;
}
