#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isRepeated(char *s1,char *s2) {
		int len_s1 = strlen(s1);
		int len_s2 = strlen(s2);

        if (len_s1 <= len_s2 || len_s2 == 0)
            return false;
 
		int i = 0;
		while(i < len_s1) {
			for(int j = 0; j < len_s2; j++) {
				if(s2[j] != s1[i+j]) {
					return false;
				}
			}
			i = i + len_s2;
		}

        if (len_s1 == i)
			return true;
        else
			return false;
}


int main() {
	//char a[100] = "abcabccccabcabcccc";
    char a[100] = "abcabccccabcabccc";
    //char a[100] = "";
	//char b[100] = "abcabcccc";
    char b[100] = "";
	int p = isRepeated(a,b);
	printf("%d",p);
	return 0;
}
