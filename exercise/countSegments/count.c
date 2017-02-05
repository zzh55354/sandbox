int countSegments(char* s) {
    int n = strlen(s);
    int count = 0;
    for (int i = 0; i < n; ++i){
        if ((s[i] != ' ' && s[i+1] == ' ') || (s[i] != ' ' && s[i+1] == '\0') )
			count++;	
		
    }    
    return (count);   
}
