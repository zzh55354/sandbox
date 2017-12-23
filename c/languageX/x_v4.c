#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct listNode {
	char var;
	int value;
	struct listNode *next;
};

struct listNode* varible_already_exist(struct listNode *h, char c);
void printList(struct listNode *h);
void printvalue(struct listNode *h, char c);
int main(){
	printf("%s", "Letter(a-zA-z)=Number(0-9)\n");
	
	struct listNode *head = NULL;
	struct listNode *p = NULL;
	char a[100];
	
	
	while(1){
		printf(">>>");
		fgets(a,100,stdin);
		a[strlen(a)-1]=0;
		if(strcmp(a, "quit")==0){
			break;
		}	
			
		else if(strncmp(a, "print ", 6)==0){
			char c = a[6];
			printvalue(head,c);
		}	
		
		else if(a[0] <= 'z' && a[0] >='a'){
				if(a[1] == '='){
					p = varible_already_exist(head,a[0]);
					if(p!=NULL && a[2] <= '9' && a[2] >= '0'){
							p->value = a[2]-'0';
						}
					else if(a[2] <= '9' && a[2] >= '0'){
						if(a[3]==0){
							struct listNode *node = malloc(sizeof(struct listNode)); 
							node->var = a[0];
							node->value = a[2]-'0';
							node->next = NULL;
							if(head == NULL){
								head = node;
							}
							else{
								node->next = head;
								head = node;
							}
						}	
						else
							printf("Error, only save 0-9\n");
					}
					
					else
							printf("not such sytax\n");
				}
				else
					printf("not such sytax\n");
		}
		else
			printf("not such sytax\n");
	}
	printList(head);
	return 0;	
}

void printList(struct listNode *h) {
	//struct listNode *p = h;
	while(h != NULL){
		printf("%c", h->var);
		printf("%c",'=');
		printf("%d\n", h->value);
		h = h->next;
	}	
}

struct listNode* varible_already_exist(struct listNode *h, char c){
	while(h != NULL){
		if(h->var == c){
			return h;
		}
		h=h->next;
	}
	return NULL;	
}

void printvalue(struct listNode *h, char c){
	while(h != NULL){
		if(h->var == c){
			printf("%d\n", h->value);
			return;
		}
		h=h->next;
	}
	printf("No such varible\n");
}	
	
		
		
	
