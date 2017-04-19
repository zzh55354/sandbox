#include <stdio.h>

struct Set {
	int data[10000];
    int count;
};

int setContains(int x, struct Set *s) {
	int i;
    for (i=0; i < s->count; i++) {
        if (s->data[i] == x) return 1;
    }

    return 0;
}

void addToSet(int x, struct Set *s) {
    s->data[s->count] = x;
    s->count++;
}

int findPairs(int* nums, int numsSize, int k) {
	struct Set s;
	s.count = 0;
    int answer = 0;

	if (k < 0) return 0;

    int p = 0;
    int q = 0;
    while(p <= numsSize-1) {
		q = p + 1;
		while(q < numsSize) {
			if (nums[p]-nums[q] == k || nums[q]-nums[p] == k) {
				printf("pair: %d, %d\n", nums[p], nums[q]);
				int t = (nums[p] < nums[q]) ? nums[p] : nums[q];
				if (!setContains(t, &s)) {
					answer++;
					addToSet(t, &s);
				}
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

	printf("%d\n",b);
}
