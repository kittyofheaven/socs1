#include <stdio.h>

int fibo(int A,int B){
	if(A == B) return 1;
	else if(A % 2 == 1) return fibo(A * 3 + 1, B);
	else if(A % 2 == 0) return fibo(A / 2, B);
	else if(A == 1) return 0;
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0; i<T; i++){
		int result = 0;
		int A ,B;
		scanf("%d %d",&A,&B); getchar();
		result = fibo(A,B);
		printf("Case #%d: ",i + 1);
		if(result == 1){
			printf("YES\n");
		} else{
			printf("NO\n");
		}
	}
	
	return 0;
}