#include <stdio.h>
#include <string.h>

int main(){
	int x;
	char n[100001];
	
	scanf("%d", &x); getchar();
	
	for(int i=0; i<x; i++){
		scanf("%[^\n]", n); getchar();
		int a = 0;
		int b = 0;
		for (int j=0; j<strlen(n); j++){
			if(j%2 == 0) a+=n[j]-48;		
			else b+=n[j]-48;			
		}		
		if ((a-b)%11 == 0) printf("Case #%d: Yeah\n", i+1);
		else printf("Case #%d: Nah\n", i+1);
	}
	
	return 0;
}