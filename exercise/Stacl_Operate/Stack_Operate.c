#include <stdio.h>
#include <malloc.h>
#define maxSize  10

typedef struct {
    int *top;
    int *base;
    int Stack_Size;
} Stack;


void Stack_Create(Stack* S) {
    S->base = (int *)malloc(maxSize*sizeof(int));
    S->top = S->base;
    S->Stack_Size = maxSize;
}

void Stack_Push(Stack* S, int x) {
	if((S->top-S->base) >= S->Stack_Size)
	{
		printf("%s","overflow");
		return;
	}
	
	*(S->top) = x;
	S->top++;
}


void Stack_Pop(Stack* S) {
		if((S->top == S->base)){
			printf("%s","is empty");
			return;
		}
		S->top--;
}

int Stack_Top(Stack* S) {
  return(*(S->top));  
}



 int main()
{
	Stack* obj = (Stack *)malloc(sizeof(Stack));
	Stack_Create(obj);
	Stack_Push(obj,3);
	int p = Stack_Top(obj);
	printf ("%s", "Top element is: ");
	printf ("%d", p);
	return(0);
}
