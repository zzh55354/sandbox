#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct listNode {
	char* first_name;
    char* last_name;
    char* number;
    char* id;
	struct listNode *next;
};

struct listNode* save_info(char *a, char *b, char *c, char*d,struct listNode* h);
void printList(struct listNode *h);
void write_in_file(struct listNode *node, FILE *pf);

int main(int argc, char *argv[]){
    char input[100];
    struct listNode *head = NULL;
    struct listNode *pointer = NULL;
    struct listNode *tail;
    char first[100];
    char last[100];
    char num[100];
    char id_str[100];
    int id_int = 0;
    char input_id[10];
    char ID[100];
    char FIRST_NAME[100];
    char LAST_NAME[100];
    char NUMBER[100];
    int p = 0;
    int q;
    int j;
    char a[100];
    int flag = 0;
    int flag1 = 0;
    FILE *fpointer;
    fpointer = fopen("customer.txt", "a+");
        while(!feof(fpointer)){
            struct listNode *node = malloc(sizeof(struct listNode));
            if (fgets(a,100,fpointer) == NULL) {
                break;
            };
            a[strlen(a)-1]=0;
            while(a[p] != '#'){
                if(p<strlen(a)-1){
                    p++;
                }
                else if(p>strlen(a)-1){
                    flag1 = 1;
                    break;
                }
            }
            if(flag1 == 1){
                flag1 = 0;
                continue;    
            }
            q = p+1;
            while(a[q] != ' '){
                if(q<strlen(a)-1){
                    q++;
                }
                else if(q>strlen(a)-1){
                    flag1 = 1;
                    break;
                }
            }
            if(flag1 == 1){
                flag1 = 0;
                continue;    
            }
            j = q+1;
            while(a[j] != '#'){
                if(j<strlen(a)-1){
                    j++;
                }
                else if(j>strlen(a)-1){
                    flag1 = 1;
                    break;
                }    
            }
            if(flag1 == 1){
                flag1 = 0;
                continue;    
            }
            strncpy(ID, a, p);
            strncpy(FIRST_NAME, a+p+1, q-p-1);
            strncpy(LAST_NAME, a+q+1, j-q-1);
            strncpy(NUMBER, a+j+1, strlen(a)-j-1);
            node->id = (char*)malloc((strlen(ID))*sizeof(char));
            node->first_name = (char*)malloc((strlen(FIRST_NAME))*sizeof(char));
            node->last_name = (char*)malloc((strlen(LAST_NAME))*sizeof(char));
            node->number = (char*)malloc((strlen(NUMBER))*sizeof(char));
            strncpy(node->id,ID, strlen(ID));
            strncpy(node->first_name,FIRST_NAME, strlen(FIRST_NAME));
            strncpy(node->last_name,LAST_NAME, strlen(LAST_NAME));
            strncpy(node->number,NUMBER, strlen(NUMBER));
            if(head == NULL){
                head = node;
                tail = node;
            }
            else{
                tail->next = node;
                tail = node;
            }
        }
    if(tail != NULL){
        id_int = strtol(tail->id, NULL, 10);    
    }     
    while(1){
        printf("1. insert\n");
        printf("2. inquire\n");
        printf("3. quit\n");
        printf(">>> ");
        fgets(input,100,stdin);
        input[strlen(input)-1]=0;
        if(strcmp(input, "3")==0){
            fclose(fpointer);
            break;
        }
        else if(strcmp(input, "1")==0){
            while(1){
                printf("Enter the first name of the customer: ");
                fgets(first,100,stdin);
                first[strlen(first)-1]=0;
                if(strcmp(first, "quit")==0){
                    break;
                }
                else
                    printf("Enter the last name of the customer: ");
                    fgets(last,100,stdin);
                    last[strlen(last)-1]=0;
                    if(strcmp(last, "quit")==0){
                        break;
                    }
                    else
                        printf("Enter the phone number of the customer: ");
                        fgets(num,100,stdin);
                        num[strlen(num)-1]=0;
                        if(strcmp(num, "quit")==0){
                            break;
                        }
                        id_int++;
                        sprintf(id_str, "%d", id_int);
                        head = save_info(first,last,num,id_str,head);
                        struct listNode *p = head;
                        while(p->next != NULL){
                            p = p->next;    
                        }
                        write_in_file(p, fpointer);
                        if(fflush(fpointer) != 0){
                            printf("File flush error");
                        }
            }
            printList(head);
            continue;
        }
        else if(strcmp(input, "2")==0){
            while(1){
                
                printf("Enter the number of the customer: ");
                fgets(input_id, 10, stdin);
                input_id[strlen(input_id)-1] = 0;
                if(strcmp(input_id, "quit")==0){
                    break;    
                }
                pointer = head;
                while(pointer != NULL){
                    if(strcmp(pointer->id, input_id)==0){
                        printf("The customer's name is: ");
                        printf("%s", pointer->first_name);
                        printf(" ");
                        printf("%s", pointer->last_name);
                        printf(" Phone numbers are: ");
                        printf("%s\n", pointer->number);
                        flag = 1;
                        break;
                    }
                    else
                        pointer = pointer->next;                        
                }
                if(flag == 0){
                    printf("id not found\n");
                    continue;    
                }
                flag = 0;
            }
            continue;
        }
        else
            continue;
        return 0;
    }
}    
struct listNode* save_info(char *a, char *b, char *c, char*d,struct listNode* h){
        struct listNode *p = h;
        struct listNode *node = malloc(sizeof(struct listNode));
        node->id = (char*)malloc((strlen(d))*sizeof(char));
        strncpy(node->id,d,strlen(d));
        node->first_name = (char*)malloc((strlen(a))*sizeof(char));
        strncpy(node->first_name,a,strlen(a));
        node->last_name = (char*)malloc((strlen(b))*sizeof(char));
        strncpy(node->last_name,b,strlen(b));
        node->number = (char*)malloc((strlen(c))*sizeof(char));
        strncpy(node->number,c,strlen(c));
        
        if(h == NULL){
            h = node;
        }
        else{
            while(p->next != NULL){
                p = p->next;    
            }
            p->next = node;
        }
    return h;
}

void printList(struct listNode *h) {
    struct listNode *p = h;
	while(p != NULL){
	    printf("%s", p->first_name);
        printf(" ");
        printf("%s", p->last_name);
        printf(" ");
        printf("%s\n", p->number);
        p = p->next;
    }	
}

void write_in_file(struct listNode *node, FILE *fp){
    fprintf(fp, "%s", node->id);
    fprintf(fp,"#");
    fprintf(fp, "%s", node->first_name);
    fprintf(fp," "); 
    fprintf(fp, "%s", node->last_name);
    fprintf(fp,"#");
    fprintf(fp, "%s\n", node->number);
}
