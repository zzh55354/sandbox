#include <stdio.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}

int node_substract(struct TreeNode* root) {
		if(root == NULL) {
        return 0;
    }
    else 
        return node_substract(root)+findTilt(root->left)+fideTile(root->right);
}
 
int findTilt(struct TreeNode* root) {
    if(Node->left == NULL && Node->right == NULL) {
        return 0;
    }
    else if(Node->left == NULL) {
        return Node->right->val;
    }
    else if(Node->right == NULL) {
        return Node->left->val;
    }
    if(Node->left->val >= Node->right->val) {
        return Node->left->val - Node->right->val;
    }
    else if(Node->left->val < Node->right->val) {
        return Node->right->val- Node->left->val;
    }
}
