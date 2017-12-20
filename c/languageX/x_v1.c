#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct listNode {
	char var;
	int value;
	struct listNode *next;
};

void printList(struct listNode *h);

int main(){
	printf("%s", "Letter(a-zA-z)=Number(0-9)\n");
	
	struct listNode *head = NULL;
	
	
	char a[100];
	while(1){
		printf(">");
		scanf("%s",a);
		if(strcmp(a, "quit")==0){
			break;
		}	
	
	//printf("%d\n", sizeof(a));
	
	
	
		if(a[0] <= 'z' && a[0] >='a'){
				if(a[1] == '='){
						if(a[2] <= '9' && a[2] >= '0'){
							
							struct listNode *node = malloc(sizeof(struct listNode)); 
							node->var = a[0];
							node->value = a[2];
							node->next = NULL;
							if(head == NULL){
								head = node;
							}
							else{
								node->next = head;
								head = node;
							}	
						}
				}
		}
	}
	printf("debug\n");
	printList(head);
	//printf("%c", head->var);
	//printf("%c", head->value);

	
	return 0;	
}

void printList(struct listNode *h) {
	//struct listNode *p = h;
	while(h != NULL){
		printf("%c", h->var);
		printf("%c",'=');
		printf("%c\n", h->value);
		h = h->next;
	}	
}
