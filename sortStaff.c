// Scaffold - Exercise 6.9
#include <stdio.h>
#define MAXSTAFF    10

// Definitions from Figure 8.5 on Page 133 of the textbook
// (also found in nested.c on Page 9 of ch08.pdf)
#define NAMESTRLEN 40
typedef char namestr[NAMESTRLEN+1];

typedef struct {
	namestr     given, others, family;
} fullname_t;

typedef struct {
	int         yy, mm, dd;
} date_t;

typedef struct {
	fullname_t  name;
	int         employeenumber;
	date_t      dob;
	date_t      datecommenced;
	int         status;
	int         annualsalary;
} staff_t;

void sort_staff_by_number(staff_t staff[], int nstaff);

void swap(staff_t *n1, staff_t *n2){
    staff_t temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void
sort_staff_by_number( staff_t staff[], int nstaff ) {
    int count = 0;
    int is_sort = 0;
    while(!is_sort){
        is_sort = 1;
        for (int i = 0; i < nstaff-count-1; i++){
            if (staff[i].employeenumber > staff[i+1].employeenumber){
                swap(&staff[i], &staff[i+1]);
                is_sort = 0;
            }
        }
    count ++;
    }
}


// (You can ignore the rest of this)

int
main(int argc, char *argv[]) {
    staff_t all_staff[MAXSTAFF] = {
        { .employeenumber=753 },
        { .employeenumber=637 },
        { .employeenumber=181 },
        { .employeenumber=33 },
        { .employeenumber=191 },
        { .employeenumber=815 },
        { .employeenumber=290 },
        { .employeenumber=559 },
        { .employeenumber=797 },
        { .employeenumber=392 }
    }; // yes, there's no information about the staff
    int nstaff = 10;
    
    /* Set employee ids of staff and display. */
    printf("IDs before sorting:");
    for( int i = 0; i < nstaff; i++ ) {
        printf(" %d", all_staff[i].employeenumber);
    }
    printf("\n");
    
    /* Sort staff by employee ids. */
    sort_staff_by_number(all_staff, nstaff);

    /* Display order after sorting. */
    printf("IDs after sorting:");
    for( int i = 0; i < nstaff; i++ ) {
        printf(" %d", all_staff[i].employeenumber);
    }
    printf("\n");

	return 0;
}