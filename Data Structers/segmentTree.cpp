/**
Ivo Karagyozov
Segment Tree
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 5;

struct node
{
    int value, left, right, lazy;
    node *leftNode, *rightNode;

    node()
    {
        value = 0;
        left = 0;
        right = 0;
        lazy = 0;
        leftNode = NULL;
        rightNode = NULL;
    }
};

int n, a[maxN], q, type, x, y, z;
node *root = new node();

void buildSegTree(node *currNode, int le, int ri)
{
    currNode->left = le;
    currNode->right = ri;

    if(le == ri)
    {
        currNode->value = a[le];
        return;
    }

    currNode->leftNode = new node();
    currNode->rightNode = new node();

    int mid = (le + ri) / 2;
    buildSegTree(currNode->leftNode, le, mid);
    buildSegTree(currNode->rightNode, mid + 1, ri);

    currNode->value = currNode->leftNode->value + currNode->rightNode->value;
}
void updateSegTree(node *currNode, int le, int ri, int newVal)
{
    if(currNode->lazy != 0)
    {
        currNode->value = (currNode->right - currNode->left + 1) * currNode->lazy;

        if(currNode->left != currNode->right)
        {
            currNode->leftNode->lazy += currNode->lazy;
            currNode->rightNode->lazy += currNode->lazy;
        }

        currNode->lazy = 0;
    }

    if(currNode->left >= le && currNode->right <= ri)
    {
        currNode->value += (currNode->right - currNode->left + 1) * newVal;

        if(currNode->left != currNode->right)
        {
            currNode->leftNode->lazy += newVal;
            currNode->rightNode->lazy += newVal;
        }

        return;
    }

    int leLeft = currNode->leftNode->left, leRight = currNode->leftNode->right, riLeft = currNode->rightNode->left, riRight = currNode->rightNode->right;
    if(leLeft <= ri && riLeft >= le) updateSegTree(currNode->leftNode, le, ri, newVal);
    if(riLeft <= ri && riLeft >= le) updateSegTree(currNode->rightNode, le, ri, newVal);

    if(currNode->leftNode->lazy != 0)
    {
        currNode->leftNode->value += (currNode->leftNode->right - currNode->leftNode->left + 1) * currNode->leftNode->lazy;

        if(currNode->leftNode->left != currNode->leftNode->right)
        {
            currNode->leftNode->leftNode->lazy += currNode->leftNode->lazy;
            currNode->leftNode->rightNode->lazy += currNode->leftNode->lazy;
        }

        currNode->leftNode->lazy = 0;
    }
    if(currNode->rightNode->lazy != 0)
    {
        currNode->rightNode->value += (currNode->rightNode->right - currNode->rightNode->left + 1) * currNode->rightNode->lazy;

        if(currNode->rightNode->left != currNode->rightNode->right)
        {
            currNode->rightNode->leftNode->lazy += currNode->rightNode->lazy;
            currNode->rightNode->rightNode->lazy += currNode->rightNode->lazy;
        }

        currNode->rightNode->lazy = 0;
    }


    currNode->value = currNode->leftNode->value + currNode->rightNode->value;
}
int query(node *currNode, int le, int ri)
{
    if(currNode->lazy != 0)
    {
        currNode->value += (currNode->right - currNode->left + 1) * currNode->lazy;

        if(currNode->left != currNode->right)
        {
            currNode->leftNode->lazy += currNode->lazy;
            currNode->rightNode->lazy += currNode->lazy;
        }

        currNode->lazy = 0;
    }

    if(currNode->left >= le && currNode->right <= ri) return currNode->value;

    int leLeft = currNode->leftNode->left, leRight = currNode->leftNode->right, riLeft = currNode->rightNode->left, riRight = currNode->rightNode->right, ans = 0;
    if(leLeft <= ri && leRight >= le) ans += query(currNode->leftNode, le, ri);
    if(riLeft <= ri && riRight >= le) ans += query(currNode->rightNode, le, ri);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    buildSegTree(root, 0, n - 1);

    cin>>q;
    for(int i = 0; i < q; i++)
    {
        cin>>type;

        if(type == 0)
        {
            cin>>z>>y>>z;
            updateSegTree(root, x, y, z);
        }
        else
        {
            cin>>x>>y;
            cout<<query(root, x, y)<<endl;
        }
    }

    return 0;
}
