#include <stdio.h>
int baris = 0, kolom = 0;

void flood(char map[50][51], int koorBaris, int koorKolom, char patokan){
	if(koorBaris >= 0 && koorBaris < baris && koorKolom >= 0 && koorKolom < kolom && map[koorBaris][koorKolom] != '#' && map[koorBaris][koorKolom] != 'z' && map[koorBaris][koorKolom] <= patokan){
//		patokan = map[koorBaris][koorKolom];
		map[koorBaris][koorKolom] = '#';
		flood(map, koorBaris - 1, koorKolom, patokan);
		flood(map, koorBaris + 1, koorKolom, patokan);
		flood(map, koorBaris, koorKolom - 1, patokan);
		flood(map, koorBaris, koorKolom + 1, patokan);
	}
}
int count = 0;
void hitung(char map[50][51], int kb, int kk){
	if(kb >= 0 && kb < baris && kk >= 0 && kk < kolom && map[kb][kk] != '#'){
		count++;
		map[kb][kk] = '#';
		hitung(map, kb - 1, kk);
		hitung(map, kb + 1, kk);
		hitung(map, kb, kk - 1);
		hitung(map, kb, kk + 1);
	}
}

void printMap(char map[50][51]){
	for(int i = 0; i < baris; i++){
		for(int j = 0; j < kolom; j++) printf("%c ", map[i][j]);
		printf("\n");
	}
}

int main(){
	scanf("%d %d", &baris, &kolom);
	getchar();
	
	char map[51][51];
	
	for(int i = 0; i < baris; i++){
		for(int j = 0; j < kolom; j++){
			scanf("%c", &map[i][j]); getchar();
		}
		
	}
//	printf("\n");
//	printMap(map);
//	getchar();
	int b,k;
	scanf("%d %d", &b, &k);
	getchar();
//	printf("%d %d\n", b, k);
	char patokan = map[b][k];
	flood(map, b, k, patokan);
	int counter = 0;
	for(int i = 0; i < baris; i++){
		for(int j = 0; j < kolom; j++){
			if(map[i][j] == 'E'){
				hitung(map, i, j);
				if(counter < count) counter = count;
				count = 0;
			}
		}
	}
	printf("%d\n", counter);
	
	return 0;
}
