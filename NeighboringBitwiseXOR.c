// https://leetcode.com/problems/neighboring-bitwise-xor

#include <stdio.h>
#include <stdbool.h>
bool doesValidArrayExist(int* derived, int derivedSize) {
    int count = 0;
    for (int i = 0; i < derivedSize; i++){
        if (derived[i] == 1){
            count ++;
        }
    }
    if (count%2 == 0)return true;
    return false; 
}

int main(void){
    int derived[] = {1,1, 0};
    bool can = doesValidArrayExist(derived, 3);
    printf("%d\n", (int)can);
}