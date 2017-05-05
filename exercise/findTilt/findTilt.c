#include <stdio.h>
#include<malloc.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

int node_substract(struct TreeNode* Node) {
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
	return 0;	
}
 
int findTilt(struct TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    else 
        return node_substract(root)+findTilt(root->left)+findTilt(root->right);
}
int main(){
	TreeNode *a,*b,*c,*d,*e;
	a = (TreeNode *)malloc(sizeof(TreeNode));
	b = (TreeNode *)malloc(sizeof(TreeNode));
	c = (TreeNode *)malloc(sizeof(TreeNode));
	d = (TreeNode *)malloc(sizeof(TreeNode));
	e = (TreeNode *)malloc(sizeof(TreeNode));
	a->left = b;
	a->right = c;
	b->right = d;
	c->left = e;
	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 4;
	e->val = 5;
	int tilt = findTilt(a);
	printf("%d", tilt);
	return 0;
}	
