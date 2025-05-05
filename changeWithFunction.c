#include <stdio.h>

int round_to_5(int n);
int try_one_coin(int *cents, int coin);
void print_change(int ncoins, int cents);

int main(void){

    int coins[6] = {200, 100, 50, 20, 10, 5};

    int amount_payable;
    printf("Enter amount in cents: ");
    scanf("%d", &amount_payable);

    amount_payable = round_to_5(amount_payable);

    int count;
    for(int i = 0; i<6; i++){
        count = try_one_coin(&amount_payable, coins[i]);
        print_change(count, coins[i]);
        if (amount_payable == 0){
            return 0;
        }
    }
}


int try_one_coin(int *amount_payable, int coin){

    int count = 0;

    // while(*amount_payable >= coin){
    //     *amount_payable -= coin;
    //     count ++;
    // }
    *amount_payable = *amount_payable % coin;
    count += amount_payable / coin;
    
    return count;
}

void print_change(int ncoins, int cents){
    printf("give %d %3d-cent coins\n", ncoins, cents);
}

int round_to_5(int n){
    int rest = n%5;
    n -= rest;

    if (rest>2){
        n +=5;
    }

    return n;
}
