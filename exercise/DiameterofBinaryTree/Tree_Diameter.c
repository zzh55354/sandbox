#include <stdio.h>
#include<malloc.h>
typedef struct TreeNode {
	int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;
int max(int a, int b) {
	if(a > b) {
		return a;
	}
	else 
		return b;
}		
int Depth(struct TreeNode* node) {
	if(node == NULL) {
		return 0;
	}
	if(node->left == NULL && node->right == NULL) {
		return 1;
	}
	else
		 return max(Depth(node->left), Depth(node->right))+1;  
}


int diameterOfBinaryTree(struct TreeNode* root) {
    if(root == NULL) {
		return 0;
	}
	if(root->right == NULL && root->left == NULL) {
			return 0;
	}
	
	else 
		return Depth(root->left)+Depth(root->right);
}

int main(){
	TreeNode *a,*b,*c,*d,*e,*f;
	a = (TreeNode *)malloc(sizeof(TreeNode));
	b = (TreeNode *)malloc(sizeof(TreeNode));
	c = (TreeNode *)malloc(sizeof(TreeNode));
	d = (TreeNode *)malloc(sizeof(TreeNode));
	e = (TreeNode *)malloc(sizeof(TreeNode));
	f = (TreeNode *)malloc(sizeof(TreeNode));
	a->left = b;
	//a->right = c;
	b->left = d;
	b->right = e;
	e->right = f;
	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 4;
	e->val = 5;
	f->val = 6;
	int diameter = diameterOfBinaryTree(a);
	printf("%d", diameter);
	return 0;
}	
