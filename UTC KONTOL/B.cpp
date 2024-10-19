#include <stdio.h>
#include <string.h>

void jarum(int kasus){
	char flag[1002] = {0};
	char str[1001];
	char jarumStr[1001];
	scanf("%s %s", str, jarumStr); getchar();
	int len = strlen(str);
	int jarumLen = strlen(jarumStr);
	
	int count = 0;
	for(int i = 0; i <= len; ++i){
		
		char isValid = 1;
		for(int k = i; k < i + jarumLen; ++k){
			if (flag[i] == 1){
				isValid = 0;
				break;	
			} 
		}
		
		if(strncmp(jarumStr, str+i, jarumLen) == 0 && isValid){
			for(int j = i; j < i + jarumLen; ++j){
				flag[j] = 1;
			}
				
			count++;
		};
	}
	
	printf("Case #%d: %d\n", kasus, count);
	
}

int main(){
	int T;
	scanf("%d", &T); getchar();
	
	for(int i = 1; i <= T; ++i){
		jarum(i);
	}
}
