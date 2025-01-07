#include <stdio.h>
#include <string.h>

int isPalindrome(char arr[], int min, int max) {
    int isPalindrome = 1;
    while(min < max){
        if(arr[min] != arr[max]){
            isPalindrome = 0;
        }
        min++;
        max--;
    }
    return isPalindrome;
}

void palindrome(int kasus) {
    char S[1001];
    scanf("%s", S);
    int min = 0;
    int max = strlen(S) -1;  // max harusnya index terakhir jadi di -1

    if (isPalindrome(S, min, max)) {
        printf("Case #%d: yes\n", kasus);
    } else {
        printf("Case #%d: no\n", kasus);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; ++i) {
        palindrome(i);
    }

    return 0;
}
