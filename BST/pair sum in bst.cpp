#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

void inOrderTraversal(BinaryTreeNode<int> *root,vector<int> &inorder){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left,inorder);
    inorder.push_back(root->data);
    inOrderTraversal(root->right,inorder);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> inorder;
    inOrderTraversal(root,inorder);
    int i=0;
    int j=inorder.size()-1;
    while(i<j){
        if(inorder[i]+inorder[j]==k){
            return true;
        }
        else if(inorder[i]+inorder[j]>k){
            j--;
        }
        else{
            i++;
        }
    }

    return false;
}