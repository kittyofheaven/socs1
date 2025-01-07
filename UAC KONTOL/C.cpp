#include <stdio.h>
#include <string.h>

typedef struct{
	char enkripsi[101];
	char asli[101];
} Encrypt;

// 0 1 0 1 0 1
void translate(char *dst, char *src){
	int diff = 0;
	int len = strlen(src);
	
	for(int i = 0; i < len; ++i){
		dst[i] = src[i] - diff;	
		diff = (diff == 0) ? 1 : 0;
	}
	dst[len] = '\0';	
}

int main(){
	
//	printf("%d %d diff: %d\n", 'f', 'e', 'f'-'e');
//	printf("%d %d diff: %d\n", 'n', 'n', 'n'-'n');
//	printf("%d %d diff: %d\n", 'o', 'n', 'o'-'n');
//	printf("%d %d diff: %d\n", 'i', 'i', 'i'-'i');
//	printf("%d %d diff: %d\n", 'f', 'e', 'f'-'e');
//	printf("\n");
//	printf("%d %d diff: %d\n", 'T', 'T', 'T'-'T');
//	printf("%d %d diff: %d\n", '{', 'z', '{'-'z');
//	printf("%d %d diff: %d\n", 'u', 'u', 'u'-'u');
//	printf("%d %d diff: %d\n", 'z', 'y', 'z'-'y');
//	printf("%d %d diff: %d\n", 'u', 'u', 'u'-'u');
	
	FILE *fp = fopen("testdata.in", "r");
	
	int N;
	fscanf(fp, "%d\n", &N);
	
	Encrypt arr[100];
	
	for(int i = 0; i < N; ++i){
		fscanf(fp, "%[^\n]\n", arr[i].enkripsi);
	}
	
	for(int i = 0; i < N; ++i){
//		printf("%s\n", arr[i].enkripsi);
		translate(arr[i].asli, arr[i].enkripsi);
	}
	
	char search[101];
	fscanf(fp, "%[^\n]\n", search);
	
	bool found = false;
	for(int i = 0; i < N; ++i){
//		printf("%s\n", arr[i].asli);
		if(strcmp(arr[i].asli, search) == 0){
			found = true;
			printf("Yes\n");
			break;
		}		
	}
	
	if(!found){
		printf("No\n");
	}
	
	fclose(fp);
	return 0;
}
