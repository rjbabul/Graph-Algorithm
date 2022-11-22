/*
* Priority Queue
* Binary Search tree(BST)
* Minimum Spanning Tree(MST)

    N:
    u v w

Input:

    11

    3 13 20
    1 2 5
    1 12 100
    2 5 6
    5 3 3
    3 4 10
    5 6 1
    6 7 2
    7 8 2
    6 11 0
    8 14 0

Output:

sourceNode--> Dis Node =  Cost

   6    -->    11   =     0
   8    -->    14   =     0
   5    -->    6    =     1
   6    -->    7    =     2
   7    -->    8    =     2
   5    -->    3    =     3
   1    -->    2    =     5
   2    -->    5    =     6
   3    -->    4    =     10
   3    -->    13   =     20
   8    -->    15   =     20
   1    -->    12   =     100

*/

#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v;
    struct Edge*child;
};

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Edge *ed=NULL;
};

Edge *push_edge(Edge *head, int u, int v)
{
    Edge *newnode = NULL;
    newnode= (struct Edge*)malloc(sizeof(struct Edge));
    newnode->u= u;
    newnode->v=v;
    newnode->child=NULL;

    if(head == NULL)
    {
        return newnode;
    }

    Edge *temp= head;
    while(temp->child !=NULL) temp= temp->child;
    temp->child= newnode;
    return head;
}

Node* get(Node* head, int data)
{
     if(head->left!=NULL  && head->data>data)
    {

        return get(head->left, data);
    }
    else if(head->right!=NULL  && head->data<data)
    {
        return get(head->right, data);
    }
    return head;
}


Node *push(Node *head , int w, int u, int v)
{
    Node *newnode = NULL;
    newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data= w;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->ed= NULL;
    newnode->ed= push_edge(newnode->ed, u, v);

    if(head==NULL)
    {
        return newnode;
    }

     Node* temp = get(head,w);

    if(temp->data==w)
    {
     temp->ed = push_edge(temp->ed, u,v);
    }
    else if(temp->data<w) temp->right= newnode;
    else temp->left= newnode;
    return head;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int n ,w, u,v;
    cin>>n;
    Node *node=NULL;
    node=(struct Node*)malloc(sizeof(struct Node));
    node=NULL;
    while(n-- && cin>>u>>v>>w)
    {
         node = push(node, w, u,v);
    }

    while(node)
    {
        Node *temp= node;
        Node *cur= node;

          if(node->left==NULL)
        {
             for(Edge* edge= node->ed; edge; edge= edge->child)
            {
                cout<<edge->u<<" -> "<<edge->v<<" = ";
                cout<<node->data<<endl;
            }
            node= node->right;
            continue;
        }

        while(cur->left->left) cur =cur->left;
        while(temp->left) temp = temp->left;

        for(Edge* edge= temp->ed; edge; edge= edge->child)
        {
            cout<<edge->u<<" -> "<<edge->v<<" = ";
            cout<<temp->data<<endl;
        }
        if(temp->data!=cur->data) cur->left= temp->right;
    }

    return 0;
}
