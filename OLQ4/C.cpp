#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; ++i){
        int N, M;
        scanf("%d %d", &N, &M);

        int seen[N+1];
        for(int j = 0; j <= N; ++j){
            seen[j] = 0;
        }

        int count = 0;
        for(int j = 0; j < M; ++j){
            int temp;
            scanf("%d", &temp);

            if(seen[temp]){
                count++;
            } else {
                seen[temp] = 1;
            }
        } 

        printf("Case #%d: %d\n", i, count);
    }

    return 0;
}
