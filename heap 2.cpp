#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
     Node(int val){
        data=val;
        left=NULL;
        right=NULL;

     }
   

};
int countNodes( Node*root){
if(root==NULL)
return 0;
int ans = 1+countNodes(root->left) +countNodes(root->right);
return ans;

}
bool isCBT(Node*root,int index,int cnt){
    if(root==NULL)
    return true;
    if(index>=cnt)
    return false;
    else{
        bool left = isCBT(root->left,2*index+1,cnt);
        bool right= isCBT(root->right,2*index+2,cnt);
      return(left&&right);
    }

}
bool isMaxorder(Node*root){
    if(root->left=NULL && root->right==NULL){
        return true;

    }
    if(root->right==NULL){
        return(root->data>root->left->data);

    }
    else{
         bool left =isMaxorder(root->left);
        bool right= isMaxorder(root->right);
        if ( left && right && (root->data>root->left->data &&root->data>root->right->data)){
return true;
        }
        else{
            return false;
            
        }

    }
   

}
bool isheap( Node*root){
    int index=0;
    int totalcount=countNodes(root);

    if(isCBT(root,index,totalcount)&& isMaxorder(root) ){
        return true;

    }

    else 
    return false;

}
int main(){
    return 0;
}