#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char kodeAkses[7];
  char norek[11];
  char nama[101];
  double saldo;
} Rekening;

typedef struct {
  char id[7];
  char pengirim[11];
  char penerima[11];
  double nominal;
} Mutasi;

Rekening listRekening[100];
int rekeningCount = 0;
Mutasi listMutasi[100];
int mutasiCount = 0;

int nowRekeningIndex = -1;

bool isLogin = false;

void clear(){
  system("clear");
}

void pause(){
  printf("Press enter to continue...");
  getchar();
}


bool confirmation(){
  char temp;
  while(1){
    printf("Do you wish to continue this action? (y/n): ");
    scanf("%c", &temp); getchar();
    if(tolower(temp) == 'y') return true;
    else if(tolower(temp) == 'n') return false;
    else{
      puts("Input between y / n");
    }
  }
}

void merge(Rekening *arr, int low, int mid, int high){
  int lLen = mid - low + 1;
  int rLen = high - mid;

  Rekening lTemp[lLen], rTemp[rLen];
  for(int i = 0; i < lLen; ++i) lTemp[i] =  arr[low + i];
  for(int i = 0; i < rLen; ++i) rTemp[i] =  arr[mid+1 + i];

  for(int i = 0, j = 0, k = low; k <= high; ++k){
    if((i < lLen && j >= rLen) || ((i < lLen) && strcmp(lTemp[i].nama, rTemp[j].nama) <= 0)) arr[k] = lTemp[i++];
    else arr[k] = rTemp[j++];
  }
}

void mergeSort(Rekening *arr, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

void printMenu(){
  puts("1. Lihat Saldo");
  puts("2. Transfer Rekening");
  puts("3. Lihat Mutasi");
  puts("4. Exit");
  printf(">> ");
}

void loadRekening(){
  FILE *fp = fopen("rekening.txt", "r");
  if(fp == NULL){
    puts("Load Rekening Failed");
    return;
  }
  while((fscanf(fp, "%[^#]#%[^#]#%[^#]#%lf\n", listRekening[rekeningCount].kodeAkses, listRekening[rekeningCount].norek, listRekening[rekeningCount].nama, &listRekening[rekeningCount].saldo)) != EOF){
    rekeningCount++;
  }
  fclose(fp);
}

void saveRekening(){
  FILE *fp = fopen("rekening.txt", "w");
  if(fp == NULL){
    puts("Save Rekening Failed");
    return;
  }
  for(int i = 0; i < rekeningCount; ++i){
    fprintf(fp, "%s#%s#%s#%.2lf\n", listRekening[i].kodeAkses, listRekening[i].norek, listRekening[i].nama, listRekening[i].saldo);
  }
}

void loadMutasi(){
  FILE *fp = fopen("mutasi.txt", "r");
  if(fp == NULL){
    puts("Load Mutasi Failed");
    return;
  }
  while((fscanf(fp, "%[^#]#%[^#]#%[^#]#%lf\n", listMutasi[mutasiCount].id, listMutasi[mutasiCount].pengirim, listMutasi[mutasiCount].penerima, &listMutasi[mutasiCount].nominal)) != EOF){
    mutasiCount++;
  }
  fclose(fp);
}

void saveMutasi(){
  FILE *fp = fopen("mutasi.txt", "w");
  if(fp == NULL){
    puts("Save Mutasi Failed");
    return;
  }
  for(int i = 0; i < mutasiCount; ++i){
    fprintf(fp, "%s#%s#%s#%.2lf\n", listMutasi[i].id, listMutasi[i].pengirim, listMutasi[i].penerima, listMutasi[i].nominal);
  }
}

void login(){
  isLogin = false;
  char code[7];
  while (1) {
    clear();
    printf("Input kode akses :");
    scanf("%[^\n]", code); getchar();

    bool found = false;
    for(int i = 0; i < rekeningCount; ++i){
      if(strcmp(code, listRekening[i].kodeAkses) == 0){
        nowRekeningIndex = i;
        found = true;
        break;
      }
    }

    if(found){
      isLogin = true;
      break;
    }
    puts("Kode akses salah!");
    pause();
  }
}

void lihatSaldo(){
  clear();
  printf("Nama : %s\n", listRekening[nowRekeningIndex].nama);
  printf("Rekening : %s\n", listRekening[nowRekeningIndex].norek);
  printf("Saldo : %.2lf\n", listRekening[nowRekeningIndex].saldo);
  pause();
}

void viewMutasi(){
  for(int i = 0; i < mutasiCount; ++i){
    printf("Id : %s\n", listMutasi[i].id);
    printf("Pengirim : %s\n", listMutasi[i].pengirim);
    printf("Penerima : %s\n", listMutasi[i].penerima);
    printf("Nominal: %.2lf\n", listMutasi[i].nominal);
    printf("Tipe : Masuk\n");
  }
  pause();
}

void viewRekening(){
  Rekening tempRekening[rekeningCount];
  for(int i = 0; i < rekeningCount; ++i){
    tempRekening[i] = listRekening[i];
  }

  mergeSort(tempRekening, 0, rekeningCount-1);

  puts("Daftar Norek :");
  for(int i = 0; i < rekeningCount; ++i){
    printf("%s %s\n", tempRekening[i].nama, tempRekening[i].norek);
  }
}

void createIdMutasi(char *target){
  sprintf(target, "TF-%03d", mutasiCount + 1);
}

void transferRekening(){
  if(listRekening[nowRekeningIndex].saldo <= 0){
    puts("Tidak ada saldo");
    pause();
    return;
  }

  if(rekeningCount <= 1){
    puts("Tidak ada rekening lain yang terdaftar");
    pause();
    return;
  }

  viewRekening();
  char tujuan[11];
  int tujuanIndex = -1;

  while(1){
    printf("Masukkan nomor rekening tujuan : ");
    scanf("%[^\n]", tujuan); getchar();
    
    tujuanIndex = -1;
    for(int i = 0; i < rekeningCount; ++i){
      if(strcmp(tujuan, listRekening[i].norek) == 0){
        tujuanIndex = i;
        break;
      }
    }

    if(tujuanIndex >= 0){
      break;
    } else {
      puts("Rekening tidak ditemukan, masukkan ulang!");
    }
  }

  puts("Detail rekening tujuan :");
  printf("Nama : %s\n", listRekening[tujuanIndex].nama);
  printf("Rekening : %s\n", listRekening[tujuanIndex].norek);

  double nominalTransfer = 0;
  while(1){
    nominalTransfer = 0;
    printf("Masukka nominal transfer: ");
    scanf("%lf", &nominalTransfer); getchar();
    
    if(nominalTransfer >= 1 && nominalTransfer <= listRekening[nowRekeningIndex].saldo){
      break;
    } else {
      printf("Masukkan saldo yang sesuai, saldomu sisa %.2lf\n", listRekening[nowRekeningIndex].saldo);
    }
  }

  if(confirmation()){
    createIdMutasi(listMutasi[mutasiCount].id);
    strcpy(listMutasi[mutasiCount].pengirim, listRekening[nowRekeningIndex].norek);
    strcpy(listMutasi[mutasiCount].penerima, listRekening[tujuanIndex].norek);
    listMutasi[mutasiCount].nominal = nominalTransfer;
    mutasiCount++;
    saveMutasi();

    listRekening[nowRekeningIndex].saldo -= nominalTransfer;
    listRekening[tujuanIndex].saldo += nominalTransfer;
    saveRekening();

  } else {
    puts("Transfer dibatalkan");
    pause();
    return;
  }
}

void lihatMutasi(){
  char norek[11];
  strcpy(norek, listRekening[nowRekeningIndex].norek);
  // printf("%d\n", mutasiCount);
  // pause();
  for(int i = 0; i < mutasiCount; ++i){
    // printf("woi woi woi\n");
    if(strcmp(listMutasi[i].penerima, norek) == 0){
      char namaPengirim[101] = "";
      for(int j = 0; j < rekeningCount; ++j){
        if(strcmp(listMutasi[i].pengirim, listRekening[j].norek) == 0){
          strcpy(namaPengirim, listRekening[j].nama);
          break;
        }
      }

      printf("Id : %s\n", listMutasi[i].id);
      printf("Pengirim : %s\n",namaPengirim);
      printf("Penerima : %s\n", listRekening[nowRekeningIndex].nama);
      printf("Nominal: %.2lf\n", listMutasi[i].nominal);
      printf("Tipe : Masuk\n");

    } else if (strcmp(listMutasi[i].pengirim, norek) == 0){

      char namaPenerima[101] = "";
      for(int j = 0; j < rekeningCount; ++j){
        if(strcmp(listMutasi[i].penerima, listRekening[j].norek) == 0){
          strcpy(namaPenerima, listRekening[j].nama);
          break;
        }
      }

      printf("Id : %s\n", listMutasi[i].id);
      printf("Pengirim : %s\n", listRekening[nowRekeningIndex].nama);
      printf("Penerima : %s\n", namaPenerima);
      printf("Nominal: %.2lf\n", listMutasi[i].nominal);
      printf("Tipe : Keluar\n");
    }
  }
  pause();
}

int main(){
  loadRekening();
  loadMutasi();
  while (1){
    clear();
    if(!isLogin){
      login();
    }

    int choice = -1;
    printMenu();
    scanf("%d", &choice); getchar();

    switch(choice){
      case 1:
        lihatSaldo();
        break;
      case 2:
        transferRekening();
        break;
      case 3:
        // viewMutasi();
        lihatMutasi();
        pause();
        break;
      case 4:
        pause();
        puts("Thankyou");
        return 0;
        break;

      default:
        puts("Please input valid number 1-4");
        pause();
    }
  }
  return 0;
}