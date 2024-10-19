#include <stdio.h>
#include <string.h>

void nominalDalamKata(int kasus){
	char satuan[20][101] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh"};
	char belasan[20][101] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas", "sepuluh"};
	char skala[20][101] = {"", "puluh", "ratus"};
	char str[4];
	
	scanf("%s", str);
	printf("Case #%02d: ", kasus);
	int angkaLen = strlen(str); // 99
	
	if(angkaLen == 3){
		int angka1 = str[0] - '0'; // '9' != 9
		int angka2 = str[1] - '0';
		int angka3 = str[2] - '0';
		
//		printf("%d %d %d", angka1, angka2, angka3);
		
		if(angka1 == 1){
			if(angka2 == 1) {
				printf("seratus %s", belasan[angka3]);
				
			} else {
				
				if(angka2 == 0 && angka3==0) {
					printf("seratus");
				} else {
					if(angka2 == 0){					
						printf("seratus %s", satuan[angka3]);
					} else {
						printf("seratus %s %s %s", satuan[angka2], skala[1], satuan[angka3]);
					}
				}
				
			}
		} else {
			// bukan seratus
			if(angka2 == 1) {
				printf("%s %s %s",satuan[angka1], skala[2], belasan[angka3]);
				
			} else {
				
				if(angka2 == 0 && angka3==0) {
					printf("%s %s", satuan[angka1], skala[2]);
				} else {
					if(angka2 == 0){					
						printf("%s %s %s", satuan[angka1], skala[2], satuan[angka3]);
					} else {
						printf("%s %s %s %s %s", satuan[angka1], skala[2], satuan[angka2], skala[1], satuan[angka3]);
					}
				}
				
			}
		}
		
		

		
		
	} else if(angkaLen == 2){
		int angka1 = str[0] - '0';
		int angka2 = str[1] - '0';
		
		if(angka1 == 1) {
			printf("%s", belasan[angka2]);
		} else {
			printf("%s %s %s", satuan[angka1], skala[1], satuan[angka2]);
		}
		
		
	} else if(angkaLen == 1){
		int angka1 = str[0] - '0';
		printf("%s", satuan[angka1]);
	}
	
	printf("\n");
}

int main(){
	int T;
	scanf("%d", &T); getchar();
	
	for(int i = 1; i <= T; ++i){
		nominalDalamKata(i);
	}
}
