#include<bits/stdc++.h>
using namespace std;
int visit[100005];
int level[100006];

struct Node
{
    int data;
    struct Node* child;
};

Node * push(Node* head, int data)
{
    Node* temp= head;

    Node *newnode = NULL;
    newnode=(struct Node*) malloc(sizeof(struct Node));
    newnode->child=NULL;
    newnode->data= data;
    if(head==NULL) return newnode;

    while(temp->child) temp= temp->child;
    temp->child = newnode;
    return head;
}

Node *push_st(Node *head, int data)
{
    Node * newnode= NULL;
    newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->child= NULL;

    if(head==NULL)return newnode;

    newnode->child= head;
    return newnode;
}

Node* dq(Node* head)
{
    return head;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n, m;
    int u, v;
    int s;


    while(cin>>n>>m)
    {
        struct Node* graph[100005];

        for(int i=1;i<=100004;i++) graph[i]= NULL;
        memset(visit, 0,sizeof(visit));
        memset(level ,0, sizeof(level));
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            graph[u]= push(graph[u], v);
            graph[v]= push(graph[v], u);
        }
        Node *st;
        st = (struct Node*)malloc(sizeof(struct Node));
        cin>>s;
        st= push_st(st, s);
        visit[s]=1;
        level[s]=1;
        cout<<s<<" ";
        while(st->child)
        {
            Node *temp = dq(st);
            bool flag= false;
            u = temp->data;
            for(Node *edge = graph[u] ; edge; edge= edge->child)
            {
                v = edge->data;

                if(!visit[v])
                {
                    cout<<v<<" ";

                    flag=true;
                    level[v]= level[u]+1;
                    visit[v]=1;
                    st= push_st(st , v);
                 break;
                }
            }
            if(!flag) st= st->child;
        }
        cout<<endl;
        for(int i=1;i<=n;i++) cout<<i<<"\t"<<level[i]<<endl;

    }
    return 0;
}
