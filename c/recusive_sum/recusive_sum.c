#include <stdio.h>
int recusive_sum(int n);
int sum(int n);
int main(){
	
	if(recusive_sum(10)==sum(10)){
	
		printf("The sum is: ");
		printf("%d", recusive_sum(10));
	}	
	
	return 0;
}

int recusive_sum(int n){
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	else
		return (n+recusive_sum(n-1));
	
}

int sum(int n){
	return (((n+1)*n/2));
}
