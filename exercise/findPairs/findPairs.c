#include <stdio.h>


int findPairs(int* nums, int numsSize, int k) {
    int answer = 0;
    int p = 0;
    int q = 0;
    while(p != numsSize-1) {
		q = p + 1;
		while(q != numsSize) {
			if(nums[p]-nums[q] == k || nums[q]-nums[p] == k){
				answer++;
			}
			q++;
		}
		p++;	
	}
	return answer;
}


int main() {
	
int a[5]={3,1,4,1,5}; 	
int b = findPairs(a,5,2);

printf("%d",b);

return 0;

}
