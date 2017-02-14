int lengthOfLastWord(char* s) {
 int n = strlen(s);
    if(n == 0){
		return 0;
	}	
    int i = (n-1);
    while(s[i] == ' '){
		i--;
	}	
	int count = 0;
	while(s[i] != ' ' && (i+1) != 0){
		count++;
		i--;
	}
	return (count);	
    

