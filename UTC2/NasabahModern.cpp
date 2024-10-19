#include <stdio.h>
#include <string.h>

char satuan[11][21] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh"};
char skala[11][21] = {"", "Belas", "Puluh", "Ratus", "Ribu", "Juta", "Milliar", "Triliun", "Kuadriliun", "Kuintiliun"};
char belas[11][21] = {"", "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};

void Ratusan(char angkaRatusan[]){
  printf(" %s\n", angkaRatusan);
  if(strlen(angkaRatusan) == 1){
    int angka0 = angkaRatusan[0] - '0';
    printf(" %s", satuan[angka0]);
    return;
  } else if (strlen(angkaRatusan) == 2){
    int angka0 = angkaRatusan[0] - '0';
    int angka1 = angkaRatusan[1] - '0';
    if(angka0 == 1) {
      if (angka1 == 0) printf(" Sepuluh");
      else {
        printf(" %s", belas[angka1]);
      }
    }
    else {
      printf(" %s %s", satuan[angka0], skala[2]);

      if(angka1 == 1) printf(" Satu");
      else printf(" %s", satuan[angka1]);
    }
    return;
  }

  int angka0 = angkaRatusan[0] - '0';
  int angka1 = angkaRatusan[1] - '0';
  int angka2 = angkaRatusan[2] - '0';
  
  if(angka0 == 1 && strcmp(angkaRatusan, "000") != 0) printf(" Seratus");
  else printf(" %s %s", satuan[angka0], skala[3]);

  if(angka1 == 1 && strcmp(angkaRatusan, "000") != 0) {
    if (angka2 == 0) printf(" Sepuluh");
    else {
      printf(" %s", belas[angka2]);
    }
  }
  else {
    printf(" %s %s", satuan[angka1], skala[2]);

    if(angka2 == 1) printf(" Satu");
    else printf(" %s", satuan[angka2]);
  }
}

int main(){
  char uang[21];
  char bagiUang[21][5];
  scanf("%s", uang); getchar();

  int lenUang = strlen(uang);
  int panjangPertama = lenUang % 3;

  if(panjangPertama == 0) panjangPertama = 3;

  strncpy(bagiUang[0], uang, panjangPertama);
  bagiUang[0][panjangPertama] = '\0';

  int panjangSisa = lenUang - panjangPertama;
  int banyakSisaArr = panjangSisa / 3;

  for(int i = 0; i < banyakSisaArr; i++){
    strncpy(bagiUang[i+1], uang + panjangPertama + (i * 3) , 3);
    bagiUang[i+1][3] = '\0';
  }

  
  int banyakTiga = (lenUang % 3 == 0) ? (lenUang / 3) - 1 : lenUang/3;
  printf("%s.", bagiUang[0]);
  for(int i = 0; i <= banyakSisaArr; i++){
    // printf("%s.", bagiUang[i]);
    Ratusan(bagiUang[i]);

    if(i < banyakSisaArr){
      if(strcmp(bagiUang[i+1], "000") != 0){
        printf(" %s", skala[banyakTiga + 3]);
      }
      banyakTiga--;
    }
  }
}