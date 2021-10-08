#include<iostream>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* getNode(int x)
{
    BstNode* newNode = new BstNode;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
    if(root == NULL)
    {
        root = getNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }

    return root;
}

bool Search(BstNode* root, int data)
{
    if(root == NULL)
    return false;
    else if(root->data == data)
    return true;
    else if(data <= root->data)
    return Search(root->left, data);
    else
    return Search(root->right, data);

}

void max(BstNode* root)
{
    if(root == NULL)
    {
        cout<<"\nThe Tree is empty!"<<endl;
        return;
    }
    BstNode* ptr = root;
    while(ptr->right!=NULL)
    {
        ptr = ptr->right;
    }
    cout<<"\nThe max element is : "<<ptr->data<<endl;
}

int recmax(BstNode* root)
{
    if(root == NULL)
    {
        cout<<"\nError : The Tree is Empty!"<<endl;
        return -1;
    }
    else if(root->right == NULL)
    {
        return root->data;
    }
    else
    return recmax(root->right);
}

void min(BstNode* root)
{
    if(root == NULL)
    {
        cout<<"\nThe Tree is empty!"<<endl;
        return;
    }
    BstNode* ptr = root;
    while(ptr->left!=NULL)
    {
        ptr = ptr->left;
    }
    cout<<"\nThe min element is : "<<ptr->data<<endl;
}

int recmin(BstNode* root)
{
    if(root == NULL)
    {
        cout<<"\nError : The Tree is Empty!"<<endl;
        return -1;
    }
    else if(root->left == NULL)
    {
        return root->data;
    }
    else
    return recmin(root->left);
}

int main()
{
    BstNode* root = NULL;
    int n,i,j,num,find,m1,m2;
    cout<<"\nEnter the number of entries in the tree : ";
    cin>>n;
    cout<<"\n";
    for(i=0;i<n;i++)
    {   cout<<"Value : ";
        cin>>num;
        root = Insert(root, num);
    }
    max(root);
    min(root);
    m1 = recmax(root);
    cout<<"\nThe max value is : "<<m1<<endl;
    m2 = recmin(root);
    cout<<"\nThe min value is : "<<m2<<endl;
    cout<<"\nEnter the value to be searched : ";
    cin>>find;
    if(Search(root, find))
    cout<<"\nFound"<<endl;
    else
    cout<<"\nNot Found!"<<endl;

}