#include <stdio.h>

int main (){
    int subjectCount, count=1, total=0;
    printf("how many subject you have? ");
    scanf("%d", &subjectCount);
    while(count <= subjectCount)
    {
        int currScore;
        printf("what's the score for subject %d: ", count);
        scanf("%d", &currScore);
        total = total + currScore;
        count++;
    }
    printf("your average score for %d subjects is: %d\n", subjectCount, total/subjectCount);
    return 0;
}