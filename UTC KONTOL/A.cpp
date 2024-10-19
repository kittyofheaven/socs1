#include <stdio.h>

void pindah(char input, int *x, int *y){
	
}

int main(){
	int x, y, N;
	scanf("%d %d", &x, &y); getchar();
	scanf("%d", &N); getchar();
	char str[N];
	scanf("%s", str); getchar();
	
	for(int i = 0; i <= N; ++i){
		int yMin = y - 1;
		int xMin = x - 1;
//		printf("%d %d %d %d\n", x, y, xMin, yMin);
		switch(str[i]){
			case 'W':
				y+= 1;
				break;
			case 'A':
				if((xMin) >= 0){
//					printf("a dilakukan\n");
					x -= 1;			
				}
				break;
			case 'S':
				
				if((yMin) >= 0){
//					printf("s dilakukan\n");
					y -= 1;
				}
				break;
			case 'D':
				x += 1;
				break;
		}
	}
	
	printf("Hov final coordinate is (%d, %d).\n", x, y);
}
