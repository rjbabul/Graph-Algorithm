#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    class Node * child;
};

class graph
{
 public:
    Node *node[10005];
};


Node* push(Node * head, int data)
{

    Node* temp = head;

    Node* newnode= new Node();
    newnode->child=NULL;
    newnode->data= data;

    if(head==NULL) return newnode;

    while(temp->child!=NULL)
        temp= temp->child;
    temp->child= newnode;

    return head;
}
void inorder(graph g, int s)
{
    if(g.node[s]->child==NULL)return ;

    Node * temp = g.node[s];

    while(temp)
    {
        cout<<temp->data<<" ";
        if(g.node[temp->data]!=NULL)
        inorder(g, temp->data);
        temp= temp->child;
    }
}

int main()
{
    freopen("input.txt","r", stdin);
    graph g ;
    int n, s;
    cin>>n>>s;
    int v, u;

    while(n--)
    {
        cin>>u>>v;
       g.node[u]= push(g.node[u],v);
    }

    cout<<s<<" ";
    inorder(g, s);

    return 0;
}
