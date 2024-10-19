#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    printf("Input your email : ");
    scanf("%s", text);
    char substring[50] = "@ti22.com";

    char temp[100];
    strcpy(temp, strstr(text, substring));
    printf("%s\n", temp);
    (strcmp(temp,substring) == 0) ? printf("%s is Valid\n", temp) : printf("%s is not Valid\n", temp);
    

    return 0;
}
