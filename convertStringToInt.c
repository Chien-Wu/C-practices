#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int power(int a, int n){
    int ans = 1;
    for(int i = 0; i < n; i++){
        ans *= a;
    }
    return ans;
}

int calculate_value(char S[], int n){
    int result = 0;

    for (int i = 0; i < n; i++){
        result += ((int)S[i] - 48) * power(10, n-i-1);
    }
    return result;
}

int my_atoi(char S[]){
    int max = strlen(S);
    int start_index = -1;
    int i;

    for (i = 0; i < max; i++){

        if(isdigit(S[i]) != 0 && start_index == -1){
            start_index = i;
        }

        if(isdigit(S[i]) == 0 && start_index != -1){
            break;
        }
    }

    if (start_index == -1){
        return 0;
    }

    int result = calculate_value(&S[start_index], i - start_index);

    if (S[start_index-1] == '-'){
        result *= -1;
    }

    return result;
}


int main(void){
    char S[] = "132";
    printf("%d\n", my_atoi(S));
}