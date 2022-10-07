#include<bits/stdc++.h>
using namespace std;
int parant[100004];
int fnd(int a)
{
    if(parant[a]==a)return a;
    else return parant[a]=fnd(parant[a]);
}

void unic(int a, int b)
{
    int x= fnd(a);
    int y= fnd(b);
    parant[y]=x;
}
int main()
{
    int a[10003], b[10004], w[10003];
    freopen("mst.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i]>>w[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<m-i-1;j++){
            if(w[j]>w[j+1])
            {
                swap(a[j], a[j+1]);
                swap(b[j], b[j+1]);
                swap(w[j], w[j+1]);
            }
        }
    }

    for(int i=1;i<=n;i++)parant[i]=i;
    int sum=0;
    for(int i=0;i<m;i++)
    {

        if(fnd(a[i]) != fnd(b[i]))
           {cout<<a[i]<<" -> "<<b[i]<<" = "<<w[i]<<endl;
               unic(a[i], b[i]);
               sum+= w[i];
           }
    }
    cout<<sum<<endl;

    return 0;
}
