/* Break the input up into a sequence of words, and only report
 * the unique ones.  
 * Figure 7.14, PPSAA words.c - Alistair Moffat, October 2013 
 * (c) University of Melbourne*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXCHARS 10      /* Max chars per word */
#define MAXWORDS 1000    /* Max distinct words */

typedef char word_t[MAXCHARS+1];
int getword(char W[], int limit);

int
main(int argc, char *argv[]) {
	word_t one_word, all_words[MAXWORDS];
	int numdistinct = 0, totwords = 0;
	while (getword(one_word, MAXCHARS) != EOF) {
		totwords = totwords + 1;
		/* linear search in array of previous words... */
		int found = 0;
		for (int i = 0; i < numdistinct && !found; i++) {
			found = (strcmp(one_word, all_words[i]) == 0);
		}
		if (!found && numdistinct < MAXWORDS) {
			strcpy(all_words[numdistinct], one_word);
			numdistinct += 1;
		}
		/* NB - program silently discards words after
		   MAXWORDS distinct ones have been found */
	}
	printf("%d words read\n", totwords);
	for (int i = 0; i < numdistinct; i++) {
		printf("word #%2d is %s\n", i, all_words[i]);
	}
	return 0;
}

/* Extract a single word out of the standard input, of no more than limit
 * characters. Argument array W must be size limit+1 characters or larger.
 * Returns length of word stored into W, or EOF (-1) if there was no word.
 * (getword.c page 121, Alistair Moffat) */
int
getword(char W[], int limit) {
    int c, len = 0;
    /* first, skip over any non alphabetics */
    while ((c = getchar()) != EOF && !isalpha(c)) {
        /* do nothing more */
    }
    if (c == EOF) {
        return EOF;
    }
    /* ok, first character of next word has been found */
    W[len++] = c;
    while (len < limit && (c = getchar()) != EOF && isalpha(c)) {
        /* another character to be stored */
        W[len++] = c;
    }
    /* now close off the string */
    W[len] = '\0';
    return 0;
}