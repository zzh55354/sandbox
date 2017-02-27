#include <stdio.h>
int findMaxConsecutiveOnes(int* nums, int numsSize) {

    int i = 0;
	while(i < numsSize){
		if(nums[i] == 1){
			break;
		}
		else if (i == numsSize-1){
			return(0);
		}
		i++;
	}		
	int start = i;
	int end = start;
	int max = 0;
	while(i < numsSize){
		while(nums[end] != 0 && end < numsSize){
			end++;
		}
		if(max < end - start){
			max = end - start;
		}
		while(nums[end] != 1 && end < numsSize){
			end++;
		}
		start = end;
		i = end;	
	}
	return(max);

}

int main(){
	int a[] = {1,0,1};
	int numsSize = 3;
	int *nums = a;
	int p = findMaxConsecutiveOnes(nums, numsSize);
	printf("%d\n", p);
}
