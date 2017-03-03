#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int i = 0;
    int zero_count = 0;
	while(nums[i]){
		if(nums[i] == 0){
			zero_count++;
		}
		else if(nums[i] != 0){
		   int j = i;
		   for(; j > 0; j--){
		       if(nums[j-1] != 0 || j == 0){
		           nums[j] = nums[i];
		       }
		   }
		   
		}
	   i++;	
	}
	while(zero_count > 0){
	   nums[numsSize-zero_count] = 0;
	   zero_count--;
	}
}
	
	
int main(){
	int a[] = {0,1,0,3,12};
	int numsSize = 5;
	int *nums = a;
	moveZeroes(nums, numsSize);
	int i = 0;
	for(; i < numsSize; i++){
		printf("%d\n", nums[i]);
	}	
}
