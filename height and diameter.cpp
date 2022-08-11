#include <iostream>
using namespace std;
struct Node{
    int data;
     struct Node*left;
     struct Node* right;
     Node(int val){
         data=val;
         left=NULL;
         right=NULL;


     }


};
int calcheight(Node*root){
    if (root==NULL){
        return 0;

    }
    int lheight= calcheight(root->left);
    int rheight=calcheight(root->right);
     return max(lheight,rheight) + 1;

}
int calcdiameter(Node*root){
    if (root==NULL){
        return 0;

    }
    int lheight= calcheight(root->left);
    int rheight=calcheight(root->right);
    int currdiameter=lheight+rheight+1;
    int ldiameter=calcdiameter(root->left);
    int rdiameter=calcdiameter(root->right);
    return max(currdiameter,max(ldiameter,rdiameter));



}

int main(){
    Node*root=new Node(1);
     root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<< calcheight(root)<<" ";
    cout<<calcdiameter(root)<<" ";

     return 0; 

}