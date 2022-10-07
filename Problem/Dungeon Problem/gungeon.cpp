#include<bits/stdc++.h>
using namespace std;
int main()
{
    char node[100][100];
    freopen("gungeon.txt", "r", stdin);
    int r, c;
    while(cin>>r>>c)
    {
        int rs, cs;
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                cin>>node[i][j];
                if(node[i][j]=='S')
                    rs=i,cs=j;

            }
        }
        queue<pair<int, int > > vt;
        int  visit[100][100];
        memset(visit, 0, sizeof(visit));
        vt.push(make_pair(rs, cs));

        int v, u;
        bool flag=false;
        while(!vt.empty())
        {
            u=vt.front().first;
            v= vt.front().second;
            vt.pop();
            if(u<1 || u>r || v<1 || v>c)
                continue;
            if(node[u][v]=='E')
            {
                flag=true;
                break;
            }
            if(node[u][v]=='#')
                continue;


            visit[u][v]=1;

            if(visit[u][v+1]==0)
                vt.push(make_pair(u,v+1));
            if(visit[u][v-1]==0)
                vt.push(make_pair(u,v-1));
            if(visit[u+1][v]==0)
                vt.push(make_pair(u+1,v));
            if(visit[u-1][v]==0)
                vt.push(make_pair(u-1,v));



        }
        if(flag)
        {
            cout<<"Find at "<<u<<" , "<<v<<endl;
        }
        else
            cout<<"Not reached"<<endl;

    }
    return 0;
}










