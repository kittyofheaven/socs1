#include <stdio.h>
#include <string.h>

typedef struct video {
  char title[1001];
  char artist[1001];
  int views;
} Video;

void merge(Video *arrVid, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  Video lTemp[lLen];
  Video rTemp[rLen];

  for(int i = 0 ; i < lLen ; ++i) lTemp[i] = arrVid[low + i]; 
  for(int i = 0 ; i < rLen ; ++i) rTemp[i] = arrVid[mid + 1 + i];

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || (i < lLen && lTemp[i].views >= rTemp[j].views)){

      if((lTemp[i].views == rTemp[j].views) && (strcmp(lTemp[i].title, rTemp[j].title) <= 0)) arrVid[k] = lTemp[i++];
      else if ((lTemp[i].views == rTemp[j].views) && (strcmp(lTemp[i].title, rTemp[j].title) > 0)) arrVid[k] = rTemp[j++];
      else arrVid[k] = lTemp[i++];

    } else arrVid[k] = rTemp[j++];
  }

}

void mergeSort(Video *arrVid, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(arrVid, low, mid);
    mergeSort(arrVid, mid+1, high);
    merge(arrVid, low, mid, high);
  }
}

int main(){
  FILE *fptr;
  fptr = fopen("testdata.in", "r");

  if(fptr == NULL){
    printf("Failed to open the file\n");
    return 1;
  }

  Video arrVid[100];
  int vidCount = 0;

  while (fscanf(fptr, "%[^#]#%[^#]#%d\n", arrVid[vidCount].title, arrVid[vidCount].artist, &arrVid[vidCount].views) != EOF) {
    vidCount++;
  }

  mergeSort(arrVid, 0, vidCount - 1);
  
  for(int i = 0; i < vidCount; ++i){
    printf("%s by %s - %d\n", arrVid[i].title, arrVid[i].artist, arrVid[i].views);
  }
  fclose(fptr);
  return 0;
}