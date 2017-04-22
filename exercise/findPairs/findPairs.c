#include <stdio.h>

int get_min( int a, int b);
int is_save(int *c, int d, int pos);

int findPairs(int* nums, int numsSize, int k) {
	if(k < 0){
		return 0;
	}	
    int answer = 0;
    int p = 0;
    int q = 0;
    int min_array[10000];
    while(p < numsSize-1) {
		q = p + 1;
		while(q < numsSize) {
			if(nums[p]-nums[q] == k || nums[q]-nums[p] == k){
				int min = get_min(nums[p], nums[q]);
				if(is_save(min_array, min, answer) == 1) { 
					answer++;
				}	
			}
			q++;
		}
		p++;	
	}
	return answer;
}

int get_min( int a, int b) {
	if(a <= b) {
		return a;
	}
	else
		return b;	
}	

int is_save(int *c, int d, int pos) {
	for(int i = 0; i < pos; i++) {
		if(c[i] == d) {
			return 0;
		}		
	}
	c[pos] = d;
	return 1;
}

int main() {
	
int a[5]={1,2,3,4,5}; 	
int b = findPairs(a,5,1);

printf("%d",b);

return 0;

}
