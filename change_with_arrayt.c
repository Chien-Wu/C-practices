#include <stdio.h>

int main(void){
    printf("Enter amount in cents: ");
    int rest;
    scanf("%d", &rest);
    printf("The coins required to make %d cents are:\n", rest);
    int coins[] = {50, 20, 10, 5, 2, 1};
    int n = sizeof(coins)/ sizeof(coins[0]);
    for (int i = 0; i < n; i ++){
        while(rest >= coins[i]){
            rest -= coins[i];
            printf("give a %dc coin\n", coins[i]);
        }
    }
    printf("amount remaining: %dc\n", rest);
}