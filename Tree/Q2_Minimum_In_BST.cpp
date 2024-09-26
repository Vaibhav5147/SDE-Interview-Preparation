
#include<iostream>
using namespace std;

/*
Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.
*/

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution {
  public:
    int minValue(Node* root) {
        if(root==nullptr)
         return -1 ;
         
        while(root->left != nullptr)
            root = root->left ;
            
       return root->data;        
    }
};