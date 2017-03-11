#include <stdio.h>
#include<malloc.h>

typedef struct ListNode {
      int val;
      struct ListNode *next;
	}ListNode;
struct ListNode* reverseList(struct ListNode* head) {
    ListNode *p,*q;
    p = head->next;
    q = p->next;
    p->next = NULL;
    while(p){
		p = q->next;
		q->next = head->next;
		head->next = q;
		q = p;
	}
	return(head);
}
int main(){
	ListNode *head, *a,*b,*c,*d;
	head = (ListNode *)malloc(sizeof(ListNode));
	a = (ListNode *)malloc(sizeof(ListNode));
	b = (ListNode *)malloc(sizeof(ListNode));
	c = (ListNode *)malloc(sizeof(ListNode));
	d = (ListNode *)malloc(sizeof(ListNode));
	head->next = a;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;
	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 4;
	
	ListNode *p;
	p = head->next;
	printf("Before reverse the linklist:");
	printf("\n");
	while(p){
	printf("%d ", p->val);
	p = p->next;
	}
	printf("\n");
reverseList(head);
	ListNode *k;
	k = head->next;
	printf("After reverse the linklist:");
	printf("\n");
	while(k){
	printf("%d ", k->val);
	k = k->next;
	}
	
	return(0);
	
}

