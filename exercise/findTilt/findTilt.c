#include <stdio.h>
#include<malloc.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

int sum(struct TreeNode* Node) {
	if (Node == NULL) {
		return 0;
	}
	else 
		return Node->val + sum(Node->right) + sum(Node->left);
}		

int nodetilt(struct TreeNode *Node) {

	int sum_right = sum(Node->right);
	int sum_left = sum(Node->left);
	if(sum_right >= sum_left) {
		return sum_right - sum_left;
	}
	else 
		return sum_left - sum_right;
} 


int findTilt(struct TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    else 
        return nodetilt(root)+findTilt(root->left)+findTilt(root->right);
}
int main(){
	TreeNode *a,*b,*c,*d,*e;
	a = (TreeNode *)malloc(sizeof(TreeNode));
	b = (TreeNode *)malloc(sizeof(TreeNode));
	c = (TreeNode *)malloc(sizeof(TreeNode));
	d = (TreeNode *)malloc(sizeof(TreeNode));
	e = (TreeNode *)malloc(sizeof(TreeNode));
	a->left = b;
	b->left = c;
	c->left = d;
	d->left = e;
	
	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 4;
	e->val = 5;
	
	int findtilt = findTilt(a);
	printf("%d", findtilt);
	return 0;
}	
