#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool A(char *s1,char *s2) {
		int len_s1 = strlen(s1);
		int len_s2 = strlen(s2);
		int i = 0;
		while(i < len_s1) {
			for(int j = 0; j < len_s2; j++) {
				if(s2[j] != s1[i+j]) {
					return false;
				}
			}	
			i = i + len_s2;
		}
		return true;
}


int main() {
	char a[100] = "abcabccccabcabcccc";
	char b[100] = "abcabcccc";
	char *c = a;
	char *d = b;
	int p = A(c,d);
	printf("%d",p);
	return 0;
}
