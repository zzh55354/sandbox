#define sizeIncrease 5

 struct {
    int *top;
    int *base;
    int *move;
    int *min;
    int Stack_Size;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *S = malloc(sizeof(MinStack));
    S->base = (int *)malloc(maxSize*sizeof(int));
    S->top = S->base;
    S->Stack_Size = maxSize;
    return S;
}

void minStackPush(MinStack* S, int x) {
    if((S->top-S->base) >= S->Stack_Size)
	{
		S->base = (int *)realloc(S->base,(S->Stack_Size+sizeIncrease)*sizeof(int));
		S->top = S->base+S->Stack_Size;
		S->Stack_Size = S->Stack_Size+sizeIncrease;
	}
	
	*(S->top) = x;
	S->top++;
}

void minStackPop(MinStack* S) {
    if((S->top == S->base))
	{
		return 0;
	}
    S->top--;
}

int minStackTop(MinStack* S) {
    if(S->top == S->base){
        return 0;
    }
    return (*(S->top-1)); 
}

int minStackGetMin(MinStack* S) {
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

void minStackFree(MinStack* S) {
    free(S->base);
	S->base = NULL;
	S->top = NULL;
}
//f2 return int
int f2() {
    // finally we fix the bug
	return 3;// always return 3
}

int f1() {
    /* always return 0 */
    // part 1 of the fix
    // part 2 of the fix
    return 0;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
