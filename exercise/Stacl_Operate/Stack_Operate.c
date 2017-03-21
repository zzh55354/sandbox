#include <stdio.h>
#include <malloc.h>
#define maxSize  5
#define sizeIncrease 2
typedef struct {
    int *top;
    int *base;
    int *move;
    int *min;
    int Stack_Size;
}Stack;


void Stack_Create(Stack* S) {
    S->base = (int *)malloc(maxSize*sizeof(int));
    S->top = S->base;
    S->Stack_Size = maxSize;
}

int Stack_Push(Stack* S, int x) {
	if((S->top-S->base) >= S->Stack_Size)
	{
		S->base = (int *)realloc(S->base,(S->Stack_Size+sizeIncrease)*sizeof(int));
		S->top = S->base+S->Stack_Size;
		S->Stack_Size = S->Stack_Size+sizeIncrease;
	}
	
	*(S->top) = x;
	S->top++;
	return *(S->top-1);
}

/*
int Stack_Pop(Stack* S) 
{
	if((S->top == S->base))
	{
		printf("%s","The stack is empty");
		return 0;
	}
	S->top--;
	return (*(S->top));
}

int Stack_Top(Stack* S) {
  if(S->top == S->base)
  {
	  printf("%s","The stack is empty, there is not top element");
  }
  return (*(S->top-1));  
}
*/
int Stack_Min(Stack* S) {
	S->move = S->base;
    S->min = S->base;
	while(S->move <= S->top-1){
		if(*(S->min) > *(S->move)){
			S->min = S->move;
		}
		S->move++;
	}
	return (*(S->min));
}


 int main()
{
	Stack* obj = (Stack *)malloc(sizeof(Stack));
	Stack_Push(obj, 3);
	Stack_Push(obj, 4);
	Stack_Push(obj, 1);
	Stack_Push(obj, 6);
	Stack_Push(obj, 2);
	Stack_Push(obj, 1);
	int m = Stack_Min(obj);
	printf ("%s", "Min element is: ");
	printf ("%d", m);
	
	return(0);
}
