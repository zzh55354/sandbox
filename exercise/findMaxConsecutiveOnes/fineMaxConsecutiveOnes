int findMaxConsecutiveOnes(int* nums, int numsSize) {

    int count = 1;
	int max = 1;
	for(int i = 0; i < numsSize; i++){
		if(nums[i] == nums[i+1]){
			count++;
			if(max < count){
				max = count;
			}
		}
		else if(nums[i] != nums[i+1]){
			count = 1;
		}
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
