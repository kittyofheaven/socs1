#include <stdio.h>
#include <string.h>

struct account{
	char name[101];
	char pass[101];
	
};

void translate(char *string){
	int dif = 1;
	bool minus = true;
	int len =  strlen(string);
	
	for(int i = 0; i < len; i++){
		if(minus){
			string[i] -= dif;
			minus = false;
		} else{
			string[i] += dif;
			minus = true;
		}
		dif++;
	}
}

void merge(account acc[], int low, int mid, int high){
	int lsize = mid - low +1;
	int rsize = high - mid;
	account kiri[lsize], kanan[rsize];
	
	for(int i = 0; i < lsize; i++){
		kiri[i] = acc[low + i];
	}
	for(int i = 0; i < rsize; i++){
		kanan[i] = acc[mid + i +1];
	}
	for(int i = 0, j = 0, k = low; k <= high; k++){
		if((i < lsize && j >= rsize) || i < lsize && strcmp(kiri[i].pass, kanan[j].pass) < 0){
			acc[k] = kiri[i++];
		} else{
			acc[k] = kanan[j++];
		}
	}
	
}

void mergeSort(account acc[], int low, int high){
	int mid = (high-low)/2 +low;
	if(low < high){
		mergeSort(acc, low, mid);
		mergeSort(acc, mid+1, high);
		merge(acc, low, mid, high);
	}
}

int binSer(account acc[], int low, int high, char srch[]){
	// if(low <= high){
  //   int mid = (high-low)/2 + low;
	// 	if(strcmp(acc[mid].pass, srch) == 0){
	// 		return mid;
	// 	} else if(strcmp(acc[mid].pass, srch) > 0){
	// 		return binSer(acc, low, mid-1, srch);
	// 	} else if(strcmp(acc[mid].pass, srch) < 0){
	// 		return binSer(acc, mid+1, high, srch);
	// 	}
	// 	else return -1;	
	// }
  // while(low <= high){
  //   int mid = low + (high - low) / 2;
  //   int cmp = strcmp(srch,acc[mid].pass);

  //   if(cmp == 0){
  //     return mid;
  //   } else if(cmp > 0){
  //     low = mid + 1;
  //   } else if(cmp < 0){
  //     high = mid - 1;
  //   }
  // }
  // return -1;
  for(int i = 0; i<=high;i++){
    if(strcmp(srch,acc[i].pass) == 0){
      return i;
    }
  }
  return -1;
}



int main(){
	FILE *fp = fopen("testdata.in", "r");
	account acc[101];
	int n, t, idx;
	char srch[101];
	
	fscanf(fp, "%d\n", &n);
	for(int i = 0; i < n; i++){
		fscanf(fp, "%[^#]#%[^\n]\n", acc[i].name, acc[i].pass);
	}
	// mergeSort(acc, 0, n-1);
	fscanf(fp, "%d\n", &t);
	
	
	for(int i = 0; i < t; i++){
		idx = -1;
		fscanf(fp, "%[^\n]\n", srch);
		translate(srch);
		idx = binSer(acc, 0, n-1, srch);
		printf("%d\n", idx);
		if(idx >= 0){
			
			printf("Case #%d: %s\n", i+1, acc[idx].name);
		} else{
			printf("Case #%d: Not Found\n", i+1);
		}
	}
	
	fclose(fp);
	
//	printf("%d %d diff: %d\n", 'A', 'B', 'B'-'A');
//	printf("%d %d diff: %d\n", 'B', '@', '@'-'B');
//	printf("%d %d diff: %d\n", 'C', 'F', 'F'-'C');
//	printf("%d %d diff: %d\n", 'D', '@', '@'-'D');
//	printf("%d %d diff: %d\n", 'E', 'J', 'J'-'E');
//	printf("%d %d diff: %d\n", 'F', '@', '@'-'F');
//	printf("%d %d diff: %d\n", 'G', 'N', 'N'-'G');
	
	return 0;
}