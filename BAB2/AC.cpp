#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    // 1 adalah desimal yang akan di shift
    // LL adalah tipe data long long
    // << N artinya menggeser 1 bit kekiri sebanyak N kali
    // sehingga setiap digeser akan bertambah pangkatnya sesuai bit dengan 2^0 2^1 2^2
    long long favorable_outcomes = (1LL << N) - 1; 

    printf("%lld\n", favorable_outcomes);
    return 0;
}
