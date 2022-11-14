#include<bits/stdc++.h>
using namespace std;
int visit[100005], level[100005];
struct Node
{
    int data;
    struct Node *child;
};


Node* push(Node* head, int data)
{

    Node* temp= head;
    Node* newnode=NULL;
    newnode= (struct Node*)malloc(sizeof(struct Node));

    newnode->data= data;
    newnode->child= NULL;

    if(head==NULL)
        return newnode;
    while(temp->child!=NULL) temp= temp->child;

    temp->child= newnode;

    return head;
}

Node * dq(Node* head)
{

    return head;
}

int main()
{
     Node *node[100005];

    freopen("input.txt", "r", stdin);

    int n , s,u,v,m;
    cin>>n>>m;
    for(int i=1; i<=m;i++)
    {
        cin>>u>>v;
        node[u]= push(node[u], v);
        node[v]= push(node[v],u);
    }

    cin>>s;
    Node *q= NULL;

    q = push(q, s);

    level[s]=0;
    visit[s]=1;
   cout<<"Visited Nodes :"<<s<<" ";
   while(q)
    {
        Node* temp = dq(q);
        q=q->child;
        u= temp->data;

        for(Node* edge=node[u];edge;edge=edge->child)
        {
            s= edge->data;

            if(!visit[s])
            {
                cout<<s<<" ";
                visit[s]= 1;
                q= push(q, s);
                level[s]= level[u]+1;
            }
        }
    }

    cout<<endl<<"Level of all nodes :\n\nNode   Level\n\n";
    for(int i=1;i<=n;i++)
        cout<<setw(2)<<i<<"\t"<<level[i]<<endl;


}
