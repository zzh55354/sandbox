#include <stdio.h>
#include<malloc.h>
typedef struct TreeNode {
	int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;
int max2(int a, int b) {
	if(a > b) {
		return a;
	}
	else 
		return b;
}

int max3(int a, int b, int c) {
	if(a>b && a>c) {
		return a;
	}
	else if(b>a && b>c) {
		return b;
	}
	else
		return c;
}
		
int Height(struct TreeNode* node) {
	if(node == NULL) {
		return 0;
	}
	if(node->left == NULL && node->right == NULL) {
		return 1;
	}
	else
		 return max2(Height(node->left), Height(node->right))+1;  
}

int Longest_path(struct TreeNode* node) {
	
	return(1+Height(node->left)+Height(node->right));
	
}

int diameterOfBinaryTree(struct TreeNode* root) {
    if(root == NULL) {
		return 0;
	}
	return(max3(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right),Longest_path(root)));
}

int main(){
	TreeNode *a,*b,*c,*d,*e,*f,*g,*h;
	a = (TreeNode *)malloc(sizeof(TreeNode));
	b = (TreeNode *)malloc(sizeof(TreeNode));
	c = (TreeNode *)malloc(sizeof(TreeNode));
	d = (TreeNode *)malloc(sizeof(TreeNode));
	e = (TreeNode *)malloc(sizeof(TreeNode));
	f = (TreeNode *)malloc(sizeof(TreeNode));
	g = (TreeNode *)malloc(sizeof(TreeNode));
	h = (TreeNode *)malloc(sizeof(TreeNode));
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	d->left = f;
	e->left = g;
	g->right = h;
	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 4;
	e->val = 5;
	f->val = 8;
	g->val = 6;
	h->val = 7;
	int diameter = diameterOfBinaryTree(a);
	printf("%d", diameter);
	return 0;
}	
