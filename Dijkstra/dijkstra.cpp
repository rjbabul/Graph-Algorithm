#include<bits/stdc++.h>
using namespace std;

int parant[100004];
typedef  pair<int, int >  pi;
int main()
{
    freopen("dijkstra.txt", "r", stdin);
    int t ,n;
    int w, u , v;
    vector<int > dist(100000, 1000);
    cin>>n>>t;
    priority_queue<pi,vector<pi> , greater<pi> > q;
    vector< pair< int , int > > vt[100004];
    while(t-- && cin>>u>>v>>w)
    {
          vt[u].push_back(make_pair(v, w));
          vt[v].push_back(make_pair(u, w));

    }
    int s;
    cin>>s;

    dist[s]=0;
    parant[s]=s;
    q.push(make_pair(0, s));
    while(!q.empty())
    {
        s = q.top().second;
        int cost= q.top().first;
        q.pop();
        for(int i=0;i<vt[s].size();i++){
            v= vt[s][i].first;
            w= vt[s][i].second;

            if(cost+w <dist[v]){
                dist[v]= cost+w;
                q.push(make_pair(dist[v],v));
                parant[v]=s;
            }
        }


    }
    for(int i=1;i<=20;i++)
    {
        cout<<i<<setw(5)<<dist[i]<<setw(5);
        s = i;
        while(parant[s]!=s){
            cout<<s<<"-->";
            s=parant[s];
        }
        cout<<s<<endl;
    }

    return 0;
}
