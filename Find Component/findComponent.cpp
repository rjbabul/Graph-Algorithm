#include<bits/stdc++.h>
using namespace std;
int visit[100003];
vector<int > component(1000000, -1);
void dfs(int cnt, int s, vector<int> vt[])
{
    for(int i=0; i<vt[s].size(); i++)
    {
        if(visit[vt[s][i]]==0){
            visit[vt[s][i]]=1;
            component[vt[s][i]]=cnt;
            dfs(cnt,vt[s][i], vt);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("findComponent.txt", "r", stdin);
    int n, u, v,m;
    cin>>n>>m;
    vector<int> vt[100000], edge;
    memset(visit, 0, sizeof(visit));
    int cnt =0;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;

        vt[u].push_back(v);
        vt[v].push_back(u);
    }

    for(int i=0;i<18; i++){
        if(visit[i]==0){
            cnt++;
            component[i]=cnt;
            visit[i]=1;
            dfs(cnt,i, vt);
        }
    }
  for(int i=0;i<18;i++)cout<<i<<" "<<component[i]<<endl;
    cout<<"Total Region of graph is: " <<cnt<<endl;


    return 0;
}
