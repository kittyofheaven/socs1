#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
int main(){
	int a, b;
	char jarum[11];
	scanf("%d %d %s", &a, &b, jarum);
	
	char apakah[11]; 
	int count = 0;
	for(int i = a; i <= b; ++i){
		sprintf(apakah, "%d", i);
		if(strstr(apakah, jarum) != NULL) count++;
	}
	printf("%d\n", count);
}
