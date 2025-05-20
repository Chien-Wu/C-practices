#include <stdio.h>
#include <stdlib.h>

int
subsetsum(int A[], int n, int k, int path[]) {
	if (k==0) {
		return 1;
	} else if (n==0) {
		return 0;
	} else if (subsetsum(A, n-1, k-A[n-1], path)){
        path[n-1] = 1;
        return 1;
    } else if (subsetsum(A, n-1, k, path)){
        path[n-1] = 0;
        return 1;
    }
    return 0;
}

int
main(int argc, char *argv[]) {
	int A[] = {
	     34,  38,  39,  43,  55,  66,  67,  84,  85,  91,
	    101, 117, 128, 138, 165, 168, 169, 182, 184, 186,
	    234, 238, 241, 276, 279, 288, 386, 387, 388, 389,
	    413, 444, 487, 513, 534, 535, 616, 722, 786, 787
	};

	int n=20, k=2000;
    int path[40] = {0};

    if (subsetsum(A, n, k, path)){
        printf("n=%d, k=%d, subsetsum = 1\n", n, k);
    } else {
        printf("n=%d, k=%d, subsetsum = 0\n", n, k);
    }
    for (int i = 0; i < 40; i++){
        if (path[i]){
            printf("%d ", A[i]);
        }
    }
    printf("\n");
	return 0;
}

