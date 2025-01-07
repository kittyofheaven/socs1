#include <stdio.h>
#include <stdlib.h>


void print(char maze[10][10]){
	for(int i = 0 ;i < 10 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

void minimumStep(char maze[10][10] , int x_start , int y_start , int step, int *min_step)
{
	if(maze[x_start][y_start] == '#' || x_start < 0 || x_start > 9 || y_start < 0 || y_start > 9 || maze[x_start][y_start] == 'p') return;
	// print(maze);
	// Sleep(250);
	if(maze[x_start][y_start] == 'E') {
		if(step < *min_step) {
			*min_step = step;
		}
		printf("STEP : %d\n", step);
		// Sleep(500);
		// system("cls");
		return;
	}
	// system("clear");
	print(maze);
	printf("\n");
	char temp = maze[x_start][y_start];
	maze[x_start][y_start] = 'p';
	
	minimumStep(maze , x_start-1 , y_start , step+1 , min_step);
	minimumStep(maze , x_start , y_start+1 , step+1 , min_step);
	minimumStep(maze , x_start , y_start-1 , step+1 , min_step);
	minimumStep(maze , x_start+1 , y_start , step+1 , min_step);
	
	//if all fail go back or backtracking
	printf("Backkk |%c|\n", temp);
	maze[x_start][y_start] = temp;
}

int main()
{
	FILE *data;
	data = fopen("contohfile3.txt", "r");
	
	char maze[10][10];
	int x_start;
	int y_start;
	for(int i = 0 ; i < 10 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			fscanf(data , "%c", &maze[i][j]);
			if(maze[i][j] == 'S'){
				x_start = i;
				y_start = j;
			}
		}
		fscanf(data , "\n");
	}
	
	fclose(data);
	int min_step = 100;
	minimumStep(maze , x_start , y_start ,  0, &min_step);
	
	printf("%d\n", min_step );
	
	return 0;
	
	
}
