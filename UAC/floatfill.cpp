#include <stdio.h>

void printImg(char img[100][100], int WIDTH, int HEIGHT){
	for(int i =0; i < HEIGHT; ++i){
		for(int j = 0; j < WIDTH; ++j){
			printf("%c ", img[i][j]);
		}
		printf("\n");
	}
}

void touchPaint(char img[100][100], int WIDTH, int HEIGHT, int x, int y, int *count){
	
	if(img[y][x] == '*') {
		return;
	}
	
	if(x >=0 && x < WIDTH && y >= 0 && y < HEIGHT){
		img[y][x] = '*'; // ini mulai ngecat
		(*count)++;
		
		// ke tetangga anjay
		//atas
		touchPaint(img, WIDTH, HEIGHT, x, y-1, count);
		//bawah
		touchPaint(img, WIDTH, HEIGHT, x, y+1, count);
		//kiri
		touchPaint(img, WIDTH, HEIGHT, x+1, y, count);
		//kanan
		touchPaint(img, WIDTH, HEIGHT, x-1, y, count);
	}	
}


int main(){
	
//	char img[HEIGHT][WIDTH] = {
//		'1','0','*','0','0','0','*','2','0','0',
//		'0','0','*','0','0','0','*','0','0','0',
//		'0','0','*','0','0','0','*','0','0','0',
//		'*','*','*','0','0','0','*','0','0','0',
//		'0','0','0','0','0','0','*','0','0','0',
//		'0','0','0','0','0','0','*','0','0','0',
//	};
	int WIDTH, HEIGHT;
	scanf("%d %d", &WIDTH, &HEIGHT); getchar();
	char img[100][100];
	
	for(int i =0; i < HEIGHT; ++i){
		for(int j = 0; j < WIDTH; ++j){
			scanf("%c", &img[i][j]);
		}
		getchar();
	}
	
	printImg(img, WIDTH, HEIGHT);
	puts("");
	
	int count = 0;
	for(int i =0; i < HEIGHT; ++i){
		for(int j = 0; j < WIDTH; ++j){
			if(img[i][j] != '*' && img[i][j] != '0'){
				touchPaint(img, WIDTH, HEIGHT, j, i, &count);
			}
		}
	}
	
//	int x,y;
//	scanf("%d %d", &x, &y);
//	touchPaint(img, x, y, &count);
	printImg(img, WIDTH, HEIGHT);
	printf("%d", count);
	
	
	return 0;
}
