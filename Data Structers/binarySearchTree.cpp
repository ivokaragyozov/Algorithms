#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct node
{
    int value;
    node *leftNode, *rightNode, *parent;

    node()
    {
        value = 0;
        leftNode = rightNode = parent = NULL;
    }
};
typedef node *link;

string query;
int value;
link root = new node;

void addNode(int value)
{
    if(root->value == 0)
    {
        root->value = value;
        return;
    }

    link currNode = root, newNode = new node;
    while(1)
    {
        if(currNode->value < value)
        {
            if(currNode->rightNode != NULL) currNode = currNode->rightNode;
            else
            {
                currNode->rightNode = newNode;
                newNode->value = value;
                newNode->parent = currNode;
                break;
            }
        }
        else
        {
            if(currNode->leftNode != NULL) currNode = currNode->leftNode;
            else
            {
                currNode->leftNode = newNode;
                newNode->value = value;
                newNode->parent = currNode;
                break;
            }
        }
    }
}
link findNode(int value)
{
    link currNode = root;

    while(1)
    {
        if(currNode->value == value) return currNode;
        else
        {
            if(currNode->value > value)
            {
                if(currNode->leftNode != NULL) currNode = currNode->leftNode;
                else return NULL;
            }
            else
            {
                if(currNode->rightNode != NULL) currNode = currNode->rightNode;
                else return NULL;
            }
        }
    }
}
link findMostLeftNode(link currNode)
{
    while(currNode->leftNode != NULL)
    {
        currNode = currNode->leftNode;
    }

    return currNode;
}
void deleteNode(int value)
{
    link deletedNode = findNode(value), parent = deletedNode->parent, child, swappingNode;

    if(deletedNode->leftNode == NULL && deletedNode->rightNode == NULL)
    {
        if(parent->leftNode == deletedNode) parent->leftNode = NULL;
        else parent->rightNode = NULL;
    }
    else if(deletedNode->leftNode == NULL && deletedNode->rightNode != NULL)
    {
        child = deletedNode->rightNode;

        if(parent->leftNode == deletedNode) parent->leftNode = child;
        else parent->rightNode = child;
        child->parent = parent;
    }
    else if(deletedNode->rightNode != NULL && deletedNode->rightNode == NULL)
    {
        child = deletedNode->leftNode;

        if(parent->leftNode == deletedNode) parent->leftNode = child;
        else parent->rightNode = child;
        child->parent = parent;
    }
    else
    {
        swappingNode = findMostLeftNode(deletedNode->rightNode);
        child = swappingNode->rightNode;

        if(swappingNode->parent->leftNode == swappingNode) swappingNode->parent->leftNode = child;
        else swappingNode->parent->rightNode = child;

        if(parent->leftNode == deletedNode) parent->leftNode = swappingNode;
        else parent->rightNode = swappingNode;
        swappingNode->parent = parent;
        swappingNode->leftNode = deletedNode->leftNode;
        swappingNode->rightNode = deletedNode->rightNode;
    }
}
void printTree(link currNode)
{
    if(currNode == root) cout<<"-------------------------------------------------"<<endl;

    cout<<currNode->value<<" ";
    if(currNode->leftNode != NULL) printTree(currNode->leftNode);
    if(currNode->rightNode != NULL) printTree(currNode->rightNode);

    if(currNode == root) cout<<endl<<"-------------------------------------------------"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        cin>>query;
        if(query == "break") break;

        if(query == "add")
        {
            cin>>value;
            addNode(value);
        }
        else if(query == "delete")
        {
            cin>>value;
            deleteNode(value);
        }
        else if(query == "print")
        {
            printTree(root);
        }
    }
    return 0;
}
