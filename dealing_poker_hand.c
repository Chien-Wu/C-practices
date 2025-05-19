#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define MAX_POKER_NUM      13
#define MAX_POKER_PAT       4
#define MAX_POKER_DECK  (MAX_POKER_NUM * MAX_POKER_PAT)
#define PLAYER_COUNT        4
#define CARDS_PER_PLAYER    5
#define SIMULATIONS    100000

//–– Card & Player Types
typedef struct {
    int rank;   // 0..12 (Ace..King)
    int suit;   // 0..3  (Spades, Hearts, Diamonds, Clubs)
} Card;

typedef struct {
    Card hand[CARDS_PER_PLAYER];
} Player;

//–– Full Deck and Game State
typedef struct {
    Card  deck[MAX_POKER_DECK];
    int   next_card;           // index of next card to deal
    Player players[PLAYER_COUNT];
} PokerGame;

//–– Hand Rankings
typedef enum {
    RANK_STRAIGHT_FLUSH,
    RANK_FOUR_OF_A_KIND,
    RANK_FULL_HOUSE,
    RANK_FLUSH,
    RANK_STRAIGHT,
    RANK_THREE_OF_A_KIND,
    RANK_NONE,
    RANK_COUNT
} HandRank;

static const char *RANK_NAMES[RANK_COUNT] = {
    "Straight Flush",
    "Four of a Kind",
    "Full House",
    "Flush",
    "Straight",
    "Three of a Kind",
    "Nothing"
};

//–– Helpers for Printing
static const char *RANK_STRINGS[MAX_POKER_NUM] = {
    "Ac","2","3","4","5","6","7","8","9","10","Ja","Qu","Ki"
};
static const char *SUIT_STRINGS[MAX_POKER_PAT] = {"S","H","D","C"};

void print_card(const Card *c) {
    printf("%2s-%1s ", RANK_STRINGS[c->rank], SUIT_STRINGS[c->suit]);
}

void print_player(const Player *p, int player_no) {
    printf("Player %d:", player_no + 1);
    for (int i = 0; i < CARDS_PER_PLAYER; i++) {
        printf(" ");
        print_card(&p->hand[i]);
    }
    putchar('\n');
}

//–– Deck Setup & Shuffle (Fisher–Yates)
void init_deck(Card deck[]) {
    for (int r = 0; r < MAX_POKER_NUM; r++)
        for (int s = 0; s < MAX_POKER_PAT; s++)
            deck[r * MAX_POKER_PAT + s] = (Card){ .rank = r, .suit = s };
}

void shuffle_deck(Card deck[]) {
    for (int i = MAX_POKER_DECK - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
}

//–– Deal
void deal_hands(PokerGame *g) {
    g->next_card = 0;
    for (int c = 0; c < CARDS_PER_PLAYER; c++) {
        for (int p = 0; p < PLAYER_COUNT; p++) {
            g->players[p].hand[c] = g->deck[g->next_card++];
        }
    }
}

//–– Hand Evaluation Helpers
static void sort_ints(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

static void count_ranks(const Player *p, int cnt[MAX_POKER_NUM]) {
    for (int i = 0; i < MAX_POKER_NUM; i++) cnt[i] = 0;
    for (int i = 0; i < CARDS_PER_PLAYER; i++)
        cnt[p->hand[i].rank]++;
}

bool is_flush(const Player *p) {
    int s = p->hand[0].suit;
    for (int i = 1; i < CARDS_PER_PLAYER; i++)
        if (p->hand[i].suit != s) return false;
    return true;
}

bool is_straight(const Player *p) {
    int r[CARDS_PER_PLAYER];
    for (int i = 0; i < CARDS_PER_PLAYER; i++)
        r[i] = p->hand[i].rank;
    sort_ints(r, CARDS_PER_PLAYER);

    // normal straight
    bool seq = true;
    for (int i = 1; i < CARDS_PER_PLAYER; i++)
        if (r[i] != r[0] + i) { seq = false; break; }
    if (seq) return true;

    // wheel A-2-3-4-5: ranks {0,1,2,3,12}
    return (r[0]==0 && r[1]==1 && r[2]==2 && r[3]==3 && r[4]==12);
}

HandRank evaluate_hand(const Player *p) {
    int cnt[MAX_POKER_NUM];
    count_ranks(p, cnt);

    bool flush = is_flush(p);
    bool straight = is_straight(p);

    if (flush && straight) return RANK_STRAIGHT_FLUSH;
    for (int r = 0; r < MAX_POKER_NUM; r++)
        if (cnt[r] == 4) return RANK_FOUR_OF_A_KIND;

    bool has3 = false, has2 = false;
    for (int r = 0; r < MAX_POKER_NUM; r++) {
        if (cnt[r] == 3) has3 = true;
        if (cnt[r] == 2) has2 = true;
    }
    if (has3 && has2)            return RANK_FULL_HOUSE;
    if (flush)                   return RANK_FLUSH;
    if (straight)                return RANK_STRAIGHT;
    if (has3)                    return RANK_THREE_OF_A_KIND;
    return RANK_NONE;
}

//–– Simulation & Tally
void simulate(int sims, double out_probs[RANK_COUNT]) {
    // zero counts
    int counts[RANK_COUNT] = {0};
    PokerGame game;

    for (int i = 0; i < sims; i++) {
        init_deck(game.deck);
        shuffle_deck(game.deck);
        deal_hands(&game);

        // evaluate each player's hand
        for (int p = 0; p < PLAYER_COUNT; p++) {
            HandRank hr = evaluate_hand(&game.players[p]);
            counts[hr]++;
        }
    }
    // convert to probabilities
    double total_hands = sims * PLAYER_COUNT;
    for (int r = 0; r < RANK_COUNT; r++)
        out_probs[r] = counts[r] / total_hands * 100.0;
}

//–– Entry Point
int main(void) {
    srand((unsigned)time(NULL));

    double probs[RANK_COUNT];
    simulate(SIMULATIONS, probs);

    printf("Empirical probabilities after %d deals (×%d hands):\n",
           SIMULATIONS, PLAYER_COUNT);
    for (int r = 0; r < RANK_COUNT; r++) {
        printf("  %-18s : %6.4f%%\n",
               RANK_NAMES[r], probs[r]);
    }
    return 0;
}
