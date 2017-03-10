#include <stdio.h>
void moveZeroes(int* nums, int numsSize) {
	int i = 0;
	while(i < numsSize){
		 if(nums[i] == 0){
		    int j = i;
		    while(j < numsSize){
		        if(nums[j] != 0){
					int temp;
					temp = nums[i];
		            nums[i] = nums[j];
		            nums[j] = temp;
		            break;
		        }
		        j++;
		    }	    
		}
	    i++;	
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
