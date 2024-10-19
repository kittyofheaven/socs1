#include <stdio.h>

int main(){
	int j,n,s;
	
	scanf("%d %d %d", &n, &j, &s);
	
	for(int i = 1; i < n+s; i++){
		if(i < s){
			printf("%-3c ", ' ');
		}else{
      if(((i-1) % j)== 0){

      } else{
			  printf("%-3d ", i-s+1);
      }

		}
		if(i % j == 0){
			printf("\n");
		}
		
	}
	
	return 0;
}