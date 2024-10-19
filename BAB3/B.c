#include <stdio.h>

int main(){
  // int T;
  // scanf("%d", &T); getchar();

  // int K[T], N[T], M[T];
  // for(int i = 0 ; i < T ; ++i){
  //   scanf("%d %d %d", &K[i], &N[i], &M[i]);
  // }

  // for(int i = 0 ; i < T ; ++i){
  //   K[i] < N[i] + M[i]  ? printf("Case #%d: yes\n", i+1) : printf("Case #%d: no\n", i+1);
  // }


	int t;
	int K, N, M;
	
	scanf("%d", &t); getchar();
	for(int i = 0 ; i < t ; i++)
	{
		scanf("%d %d %d", &K, &N, &M);
		printf ("Case #%d: ", i+1);
		if (K <= N+M)
			printf("yes\n");
		else
			printf("no\n");
	}

  return 0;

}
