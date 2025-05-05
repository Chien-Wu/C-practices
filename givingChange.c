#include <stdio.h>

int main(void){
    int amount;
    int coins[] = {50,20,10,5,2,1};
    printf("Enter amount in cents: ");
    scanf("%d", &amount);

    if (amount < 0 || amount >99){
        printf("input invalid");
        return 0;
    }

    printf("The coins required to make %d cents are:\n", amount);

    int i=0;
    while(i<6){
        if (coins[i] <= amount){
            printf("give a %2dc coin\n", coins[i]);
            amount -= coins[i];
        }else{
            i++;
        }
    }

    printf("amount remaining: 0c\n");
    return 0;
}