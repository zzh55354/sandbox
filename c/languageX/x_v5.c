#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT ">>>"

struct listNode {
	char var;
	int value;
	char* str;
	int type;
	struct listNode *next;
};


struct listNode *p = NULL;
struct listNode* X_language_execute(char* a, struct listNode *h);
struct listNode* varible_already_exist(struct listNode *h, char c);
void printList(struct listNode *h);
void printvalue(struct listNode *h, char c);
void clear_all(struct listNode*h);
int total_nodes(struct listNode *h);

int main(int argc,char** argv){
	
	struct listNode *head = NULL;
	char a[100];
	
	if(argv[1] == NULL){
		while(1){
			printf(PROMPT);
			fgets(a,100,stdin);
			a[strlen(a)-1]=0;
			if(strcmp(a, "quit")==0){
				printList(head);
				clear_all(head);
				break;
			}	
			else 
				head = X_language_execute(a, head);			
		}	
		return 0;
	}	
	
	else{ 
		FILE * fpointer;
		fpointer = fopen(argv[1], "r");
		while(!feof(fpointer)){
			fgets(a,100,fpointer);
			if(a[strlen(a)-1]=='\n'){
				a[strlen(a)-1]=0;//remove return char '\n'
			}
			if(strcmp(a, "quit")==0){
				fclose(fpointer);
				printList(head); 
				clear_all(head);
				break; 
			} else {
				head = X_language_execute(a, head);
			}
		}
		return 0;
					
	}
	
}

void printList(struct listNode *h) {
	struct listNode *count = h;
	int total = total_nodes(count);
	//int count = 0;
	while(h != NULL){
		if(h->type == 0){
			printf("%c", h->var);
			printf("=");
			printf("%d\n", h->value);
			h = h->next;
			//count = count+1;
		}
		else if(h->type == 1){
			printf("%c", h->var);
			printf("=");
			printf("%s\n", h->str);
			free(h->str);
			h = h->next;
			//count = count+1;	
		}	
	}
	printf("Total node(s): ");
	printf("%d",total);	
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
			if(h->type == 0){
				printf("%d\n", h->value);
				return;
			}
			else if(h->type == 1){
				printf("%s\n", h->str);
				return;	
			}	
		}
		h=h->next;
	}
	printf("No such varible\n");
}	
	
void clear_all(struct listNode*h){
    struct listNode* c;
    while(h!=NULL)
    {
        c = h;
        h=h->next;
        c->next=NULL;
        free(c);
        c = NULL;
    }
}

int total_nodes(struct listNode *h){
	if(h != NULL){
		return(1+total_nodes(h->next));
	}
	else
		return 0;
}

struct listNode* X_language_execute(char* a, struct listNode *h){
		if(strncmp(a, "print ", 6)==0){
			char c = a[6];
			printvalue(h,c);
		}	
		else if(a[0] <= 'z' && a[0] >='a'&& a[1] == '='){
			p = varible_already_exist(h,a[0]);
			if(p!=NULL && a[2] <= '9' && a[2] >= '0' && a[3]==0){
					if(p->str!=NULL){
						free(p->str);
					}
					p->value = a[2]-'0';
					p->type = 0;
			}
			else if(p!=NULL && a[2] =='"' && a[strlen(a)-1] =='"'){
					if(p->str!=NULL){
						free(p->str);
					}
					p->str = (char*)malloc((strlen(a)-4)*sizeof(char));
					strncpy(p->str,a+3,strlen(a)-4);
					p->type = 1;
			}
			else if(a[2] <= '9' && a[2] >= '0' && a[3]==0){
				struct listNode *node = malloc(sizeof(struct listNode)); 
				node->var = a[0];
				node->value = a[2]-'0';
				node->next = NULL;
				node->type = 0;
				if(h == NULL){
					h = node;
				}
				else{
					node->next = h;
					h = node;
				}
			}
			else if(a[2] =='"' && a[strlen(a)-1] =='"'){
				struct listNode *node = malloc(sizeof(struct listNode)); 			
				node->var = a[0];
				node->str = (char*)malloc((strlen(a)-4)*sizeof(char));
				strncpy(node->str,a+3,strlen(a)-4);
				node->type = 1;
				node->next = NULL;
				if(h == NULL){
					h = node;
				}
				else{
					node->next = h;
					h = node;
				}
			}	
			else
				printf("Error, not such sytax\n");
		}		
		else
			printf("Error, not such sytax\n");
			
		return h;	
}		

		
		
	
