#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>*constructTree(vector<int> &preOrder,int start,int end){
    if(start>end){
        return NULL;
    }

    TreeNode<int>* root=new TreeNode<int>(preOrder[start]);
    int i=start+1;
    for(;i<=end;i++){
        if(preOrder[start]<preOrder[i]){
            break;
        }
    }

    root->left=constructTree(preOrder,start+1,i-1);
    root->right=constructTree(preOrder,i,end);

    return root;

}


TreeNode<int>* preOrderTree(vector<int> &preOrder){
    return constructTree(preOrder,0,preOrder.size()-1);
}