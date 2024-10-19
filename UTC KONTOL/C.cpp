/*


*/
#include <stdio.h>

int main(){
	int bulan, start;
	scanf("%d %d", &bulan, &start);
	
	
	printf("Mo|Tu|We|Th|Fr\n");
	printf("--+--+--+--+--\n");
	int count; // count adalah mulai tanggal di hari seninnya berapa
	if(start == 6){
		count = 3; // jika di 6 maka hari senin mulai dari tanggal 3
	} else if (start == 7) {
		count = 2; // jika start di 7 maka hari mulai dari 2
	} 
	else{
		count = 1;
	}
	char printingCount = 1;
	
	if((bulan == 1 && start == 6 ) || (bulan == 1 && start == 7 ) || (bulan == 2 && start == 6 )){ // ini if else buat yang tidak ke print sama sekali
		printf("%2c|%2c|%2c|%2c|", ' ',' ',' ',' '); // jadinya pagernya doang yang ke print
	} else {
		for(int i = 1 ; i <= bulan+start; ++i){ // looping dari i ke bulan + startnya berapa
		
			if((i % 5) -1 == 0){
				if (count != 1 && (start != 6 || count != 3) && (start != 7 || count != 2) )count+=2;
				if (i!=1)printf("\n");
			} else{
				printf("|");
			}
			
			if(i < start && start != 6 && start != 7){
				printf("%2c", ' ');
			}
			else if (count != bulan){
				if (printingCount) printf("%2d",count++);
				else{
					printf("%2c",' ');
				}
				if(count > bulan) printingCount = 0;
				if((i % 5) == 0 && printingCount == 0) break;
			}
		}	
	}
	printf("\n");
}
