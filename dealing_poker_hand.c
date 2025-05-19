#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX_POKER_NUM 13
#define MAX_POKER_PAT 4
#define MAX_POKER_DECK MAX_POKER_NUM*MAX_POKER_PAT
#define PLAYER_PER_GAME 4
#define CARD_PER_PLAYER 5

static const char *RANKS[MAX_POKER_NUM] = {"Ac","2","3","4","5","6","7","8","9","10","Ja","Qu","Ki"};
static const char *SUITS[MAX_POKER_PAT] = {"S","H","D","C"};

typedef struct {
    int num;
    int pat;
} Card;

typedef struct {
    Card hand[CARD_PER_PLAYER];
} Player;

typedef struct {
    Card   deck[MAX_POKER_DECK];
    int    deck_pos;
    Player players[PLAYER_PER_GAME];
} PokerGame;

void generate_shuffled_deck(Card deck[]){
    for (int i = 0; i<MAX_POKER_NUM; i++){
        for (int j = 0; j<MAX_POKER_PAT; j++){
            deck[i*MAX_POKER_PAT + j].num = i;
            deck[i*MAX_POKER_PAT + j].pat = j;
        }
    }
    for (int i = MAX_POKER_DECK - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
}

void print_card(Card *card){
    printf("%2s-%1s ", RANKS[card->num], SUITS[card->pat]);
}

void print_game(PokerGame game){
    for (int p = 0; p < PLAYER_PER_GAME; p++){
        printf("Player %d: ", p);
        for (int c = 0; c < CARD_PER_PLAYER; c++){
            print_card(&game.players[p].hand[c]);
        }
        printf("\n");
    }
}

int main(void){
    srand((unsigned)time(NULL));

    PokerGame game;
    generate_shuffled_deck(game.deck);
    game.deck_pos = 0;

    for (int c = 0; c < CARD_PER_PLAYER; c++){
        for (int p = 0; p < PLAYER_PER_GAME; p++){
            game.players[p].hand[c] = game.deck[game.deck_pos];
            game.deck_pos++;
        }
    }
    print_game(game);
}