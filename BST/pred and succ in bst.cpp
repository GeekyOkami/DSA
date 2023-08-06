#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pred=-1;
    int succ=-1;
    BinaryTreeNode<int>* temp=root;
    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }
        else if(temp->data<key){
            pred=temp->data;
            temp=temp->right;
        }
    }
    
    //pred
    BinaryTreeNode<int>* Node=temp->left;
    while(Node!=NULL){
        pred=Node->data;
        Node=Node->right;
    }
    //succ
    Node=temp->right;
    while(Node!=NULL){
        succ=Node->data;
        Node=Node->left;
    }
    pair<int,int> ans=make_pair(pred,succ);

    return ans;
}
