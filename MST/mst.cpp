#include<bits/stdc++.h>
using namespace std;
int par[20000];
int parant[200005];
typedef pair< int, pair< int , int > >   pi;
int fnd(int a){


   if(parant[a]==a) return   a;
   return parant[a]=  fnd(parant[a]);

}
void union_(int a, int b){

  int xa= fnd(a);
  int xb=fnd(b);
  parant[xb]=xa;

}
void init_parant(int n)
{
    for(int i=1;i<=n;i++) parant[i]=i;
}
int main()
{
    freopen("mst.txt","r", stdin);


    int n ,u,v,w,m;
    priority_queue< pi, vector<pi>  , greater<pi> > q;
    cin>>n>>m;
     init_parant(n);
    while(m-- && cin>>u>>v>>w){
          //q.push({w, {u,v} });
          q.push(make_pair(w, make_pair(u,v)));
          q.push(make_pair(w, make_pair(v,u)));
          //q.push({w, {v,u} });
    }
    int sum =0;
    while(!q.empty())
    {
        w= q.top().first;
        u= q.top().second.first;
        v= q.top().second.second;
        if(fnd(u)!=fnd(v))
        {
            cout<<u<<" -> "<<v<<" = "<<w<<endl;
            sum+=w;
            union_(u,v);
        }
    q.pop();
    }
    cout<<sum<<endl;

    return 0;
}
