#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool repeatedSubstringPattern(char* s) {
    char substring[10000];
    substring[0] = s[0];
    int len = strlen(s);
    int substring_len = 1;
    int i = 0;
	AA:while(i < len) {
		if(substring_len > len/2) { 
			return false;
		}
		for(int j = 0; j < substring_len; j++) {
			if(s[i+j] != substring[i]) {
				substring[substring_len] = s[substring_len];
				substring_len++;
				i = substring_len;
				goto AA;
			}			
		}
		i = i + substring_len;
	}
	return true;
}
int main() {
	
char a[10]="abcabcabc";
char *s = a;
bool p = repeatedSubstringPattern(s);
printf("%d", p);

return 0;	
}













