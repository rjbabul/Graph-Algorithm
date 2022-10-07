#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("bicolor.txt", "r", stdin);
    int n,u,v,m;
    cin>>n>>m;
    vector<int > color(10000,-1);
    vector<int> node[100004];
    int nn=n;
    while(m-- && cin>>u>>v)
    {
        node[u].push_back(v);
        node[v].push_back(u);

    }
    int s;
    cin>>s;
    queue<int> q;
    q.push(s);
    color[s]=1;
    bool flag= true;
    while(!q.empty() && flag)
    {
        s= q.front();
        q.pop();
        for(int i=0; i<node[s].size(); i++)
        {
            if(color[node[s][i]]==-1)
            {
                color[node[s][i]]= color[s]^1;
                q.push(node[s][i]);
            }
            else if(color[color[node[s][i]]]!= color[s])
                continue;
            else
                flag=false;
        }
    }
    for(int i=1; i<=nn; i++)
        cout<<color[i]<<" "<<i<<endl;
    if(flag)
        cout<<"yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
