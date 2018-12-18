#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
	};
	
	
int height(struct node *N)
{
	if(N==NULL)
	return 0;
	return (N->height);
}	

int balance(struct node *A)
{   if(A==NULL)
    return 0;
    else
	{
	int bal=(height(A->left)-height(A->right));
	return bal;}
}



struct node *newNode(int key)
{   cout<<"newNode"<<endl;
	struct node *temp=new node;
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	return temp;
}

struct node *rightRotate(struct node* H)
{
	//cout<<"right rotate";
	struct node *H_child=H->left;
	struct node *child=H_child->right;
	
	H_child->right=H;
	H->left=child;
	
	
	H_child->height=max(height(H_child->left),height(H_child->right))+1;
	H->height=max(height(H->left),height(H->right))+1;
	
	return H_child;	
	
}

struct node *leftRotate(struct node* H)
{
	cout<<"left rotate";
	struct node *H_child=H->right;
	struct node *child=H_child->left;
	
	H_child->left=H;
	H->right=child;
	
	H_child->height=max(height(H_child->left),height(H_child->right))+1;
	H->height=max(height(H->left),height(H->right))+1;
	
	return H_child;	
	
}

struct node *insert(struct node *root,int key)
{
	if(root==NULL)
	return newNode(key);
	
	else if(key<root->data)
	root->left=insert(root->left,key);
	
	else if(key>root->data)
	root->right=insert(root->right,key);
	
	root->height=1+max(height(root->left),height(root->right));

     int balancee=balance(root);
     cout<<balancee<<endl;
     
	
	if(balancee>1&&key<root->left->data)
	return rightRotate(root);
	
	if(balancee<-1&&key>root->right->data)
	return leftRotate(root);
	
	if(balancee>1&&key>root->left->data)
	{
	root->left=leftRotate(root->left);
	return rightRotate(root);}
	
	if(balancee<-1&&key<root->right->data)
	{root->right=rightRotate(root->right);
	  return leftRotate(root);
	}
	 
	return root;
	
}

void inorder(struct node* root)
{
	if(root)
	{
		
		inorder(root->left);
    	inorder(root->right);
		cout<<(root->data)<<endl;
		

		
	}
	
	
	
}
int main ()
{
	struct node *root=NULL;
	root=insert(root,500);
	root=insert(root,50);
    root=insert(root,510);
    root=insert(root,49);
    root=insert(root,48);
    root = insert(root, 15);
  root = insert(root, 14);
  root = insert(root, 40);
  root = insert(root, 50);
	inorder(root);
	return 0;	
	
	
}
