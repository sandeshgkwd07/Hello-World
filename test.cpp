/* CPP program to print levels 
line by line */
#include <bits/stdc++.h> 
using namespace std; 

// A Binary Tree Node 
struct node 
{ 
	struct node *left; 
	int data; 
	struct node *right; 
}; 

void printLevelOrder(node *root)  
{  
    // Base Case  
    if (root == NULL) return;  
  
    // Create an empty queue for level order tarversal  
    queue<node *> q;  
  
    // Enqueue Root and initialize height  
    q.push(root);  
  
    while (q.empty() == false)  
    {  
        int nodeCount = q.size();  
        int arr[nodeCount];
        while (nodeCount > 0) 
        {  
            node *node = q.front();  
            //cout << node->data << " "; 
            //cout << node->data;
            arr[nodeCount] = node->data;
            cout << arr[nodeCount];
            
            q.pop();  
            if (node->left != NULL)  
                q.push(node->left);  
            if (node->right != NULL)  
                q.push(node->right);  
            nodeCount--;  
        }  
        int i=0;
        for(i=0; i<nodeCount; i++){
            cout << arr[i];
        }
        cout << endl;  
    }  
}  

node* newNode(int data) 
{ 
	node *temp = new node; 
	temp->data = data; 
	temp->left = NULL; 
	temp->right = NULL; 
	return temp; 
} 

void fillTheMissingNodes(struct node *root){

    if (root == NULL){
        return ;
    }

    if (root->left == NULL && root->right == NULL){
        root->left = newNode(0);
        root->right = newNode(0);
        return ;
    }

    if(root->left == NULL && root->right != NULL){
         root->left = newNode(0);
    }
    if(root->right == NULL && root->left != NULL){
         root->right = newNode(0);
    }
    if (root->left != NULL && root->right != NULL){
        fillTheMissingNodes(root->left);
        fillTheMissingNodes(root->right);
    }
}
// Driver program to test above 
// functions 
int main() 
{ 
	
	struct node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->right->right = newNode(1);
    root->left->left->left = newNode(9);
    root->right->right->left = newNode(4);
    root->right->right->right = newNode(6);

    fillTheMissingNodes(root);
    //printTreeInLevelOrder(root);

	printLevelOrder(root); 
	return 0; 
} 

