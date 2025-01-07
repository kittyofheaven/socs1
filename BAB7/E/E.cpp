#include <stdio.h>
#include <string.h>

char ascTemp(double temp1, char unit1, double temp2, char unit2){
  if(unit1 == 'F'){
    temp1 = (temp1 - 32) * 5 / 9;
  }
  if(unit2 == 'F'){
    temp2 = (temp2 - 32) * 5 / 9;
  }

  if(temp1 < temp2) return 1;
  else if(temp1 > temp2) return 0;
  else if(temp1 == temp2) return 2;
  
  return 3;
}


typedef struct city{
  char name[1001];
  double temp;
  char unit;
} City;

void merge(City *cityArr, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  City lTemp[lLen];
  City rTemp[rLen];

  for(int i = 0; i < lLen; ++i) lTemp[i] = cityArr[low + i];
  for(int i = 0; i < rLen; ++i) rTemp[i] = cityArr[mid + 1 + i];

  for(int i = 0, j = 0, k = low; k <= high; ++k)
{
  if((i < lLen && j >= rLen) || (i < lLen && (ascTemp(lTemp[i].temp, lTemp[i].unit, rTemp[j].temp, rTemp[j].unit) == 1))) cityArr[k] = lTemp[i++];
  else if((i < lLen && j >= rLen) || (i < lLen && (ascTemp(lTemp[i].temp, lTemp[i].unit, rTemp[j].temp, rTemp[j].unit) == 2))) {
    if(strcmp(lTemp[i].name, rTemp[i].name) <= 0) cityArr[k] = lTemp[i++];
    else cityArr[k] = rTemp[j++];
  }
  else cityArr[k] = rTemp[j++];
}
}

void mergeSort(City *cityArr, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(cityArr, low, mid);
    mergeSort(cityArr, mid+1, high);
    merge(cityArr, low, mid, high);
  }
}

int main(){
  FILE *fptr;
  fptr = fopen("testdata.in", "r");

  City cityArr[101];
  int cityCount = 0;

  while ((fscanf(fptr, "%[^#]#%lf#%c\n", cityArr[cityCount].name, &cityArr[cityCount].temp, &cityArr[cityCount].unit)) != EOF)
  {
    cityCount++;
  }

  mergeSort(cityArr, 0, cityCount-1);

  for(int i = 0; i < cityCount; ++i){
    printf("%s is %.2lf%c\n", cityArr[i].name, cityArr[i].temp, cityArr[i].unit);
  }
  // printf("%d", ascTemp(30, 'F', 30, 'F'));
  
  return 0;
}