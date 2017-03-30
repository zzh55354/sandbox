#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// get a sub string from s, sub string's length is len
// the result is stored in substring
char* getSubStr(char *s, int len, char *substring) {
    for (int i = 0; i < len; i++) {
       substring[i] = s[i];
    }
    substring[len] = 0;
    return substring;
}

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

bool repeatedSubstringPattern(char* s) {
    char substring[10000];

    int max = strlen(s)/2;

    for (int i = 1; i < max; i ++) {
       getSubStr(s, i, substring);
       if (isRepeated(s, substring))
           return true;
    }

    return false;
}

int main() {
	char a[10]="abcabcab";
	bool p = repeatedSubstringPattern(a);
	printf("%d", p);

	return 0;	
}
