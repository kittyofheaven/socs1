#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);
	
	for(int i = 1 ; i <= T ; ++i){
		int N, A, B, C, D;
		scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);
		
		int count = 0;
		for(int j = 1 ; j <= N ; ++j){
			if(j % A == 0){
				count++;   
			} else if (j % B == 0){
				count++;
			} else if (j % C == 0){
				count++;
			} else if (j % D == 0){
				count++;
			}
		}
		
		printf("Case #%d: %d\n",i, count);
	}
	
	return 0;
}