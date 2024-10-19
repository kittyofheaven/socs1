#include <stdio.h>
int main() {
    int T;
    scanf("%d", &T); getchar();

    for (int t = 0; t < T; t++) {
        int len;
        scanf("%d", &len); getchar();
        
        int arr[len];
        for (int i = 0; i < len; i++) {
            scanf("%d", &arr[i]); getchar();
        }

        int coolFactor = 0;
        for (int i = 0; i < len; i++) {
            int isCount = 0;
            for (int j = 0; j < len; j++) {
                if (i == j) continue;
                for (int k = 0; k < len; k++) {
                    if (i == k || j == k) continue;
                    if (arr[i] == arr[j] + arr[k]) {
                        coolFactor++;
                        isCount = 1;
                        break;
                    }
                }
                if (isCount) break;
            }
        }

        printf("Case #%d: %d\n", t + 1, coolFactor);
    }

    return 0;
}