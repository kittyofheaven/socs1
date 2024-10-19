#include <stdio.h>

void Emergency(int kasus){
	int N, K;
	scanf("%d %d", &N ,&K);
	char maze[N+1];
	scanf("%s", maze);
	
	int front = 0;
	int back = 0;
	int frontIndex = -1, backIndex =-2;
	for(int i = 0 ; i < N; ++i){
		front++;
		if(maze[i] == '1'){
			frontIndex = i;
			break;
		}
	}
	
	for(int i = N-1 ; i > 0; --i){
		back++;
		if(maze[i] == '1') {
			backIndex = i;
			break;	
		}
	}
	if(frontIndex == backIndex){
		(K>=N) ? printf("Case #%d: Alive\n", kasus) : printf("Case #%d: Dead\n", kasus);
	}
	else if(front <= K && back <= K){
		printf("Case #%d: Alive\n", kasus);
	} else {
		printf("Case #%d: Dead\n", kasus);
	}
	
}

int main(){
	int T;
	scanf("%d", &T);
	
	for(int i = 1; i <= T; ++i){
		Emergency(i);
	}
	
	return 0;
}
