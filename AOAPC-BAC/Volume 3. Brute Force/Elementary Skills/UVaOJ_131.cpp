// UVaOJ 131
// The Psychic Poker Player
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

struct Poker {
    char value;
    char suit;
};

const int NUM_CARD = 5;
const int LIMITS_VALUES = 15;

const char str_write[][20] = {
    "highest-card",
    "one-pair",
    "two-pairs",
    "three-of-a-kind",
    "straight",
    "flush",
    "full-house",
    "four-of-a-kind",
    "straight-flush",
};

enum Type {
    HIGHEST_CARD,
    ONE_PAIR,
    TWO_PAIRS,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH,
};

char ch;

map<char, int> int_value;

Poker hand[NUM_CARD];
Poker deck[NUM_CARD];
Type type_max;

int count_value[LIMITS_VALUES];
int count_value_same[NUM_CARD];

bool IsSameSuit(Poker card[]);
bool IsOrder(Poker card[]);
Type JudgeType(Poker card[]);

void Search(int x);

int main() {
    // Make map.
    int_value['A'] = 1;
    for (int i = 2; i < 10; ++i) {
        int_value['0' + i] = i;
    }
    int_value['T'] = 10;
    int_value['J'] = 11;
    int_value['Q'] = 12;
    int_value['K'] = 13;

    // Let's start the game!
    while (scanf("%c%c%c", &hand[0].value, &hand[0].suit, &ch) != EOF) {
        // Inputs.
        for (int i = 1; i < NUM_CARD; ++i) {
            scanf("%c%c%c", &hand[i].value, &hand[i].suit, &ch);
        }
        for (int i = 0; i < NUM_CARD; ++i) {
            scanf("%c%c%c", &deck[i].value, &deck[i].suit, &ch);
        }
        // Search.
        type_max = HIGHEST_CARD;
        for (int i = 0; i < 1 << NUM_CARD; ++i) {
            Search(i);
        }
        // Outputs.
        printf("Hand: ");
        for (int i = 0; i < NUM_CARD; ++i) {
            printf("%c%c ", hand[i].value, hand[i].suit);
        }
        printf("Deck: ");
        for (int i = 0; i < NUM_CARD; ++i) {
            printf("%c%c ", deck[i].value, deck[i].suit);
        }
        printf("Best hand: %s\n", str_write[type_max]);
    } 
    return 0;
}

bool IsSameSuit(Poker card[]) {
    for (int i = 1; i < NUM_CARD; ++i) {
        if (card[i].suit != card[0].suit) {
            return false;
        }
    }
    return true;
}

bool IsOrder(Poker card[]) {
    memset(count_value, 0, sizeof(count_value));
    for (int i = 0; i < NUM_CARD; ++i) {
        ++count_value[int_value[card[i].value]]; 
        if (card[i].value == 'A') {
            ++count_value[14];
        }
    }
    int num = 0;
    for (int i = 0; i < LIMITS_VALUES && num < 5; ++i) {
        if (count_value[i]) {
            ++num;
        } else {
            num = 0;
        }
    }
    if (num == 5) {
        return true;
    } else {
        return false;
    }
}

Type JudgeType(Poker card[]) {
    memset(count_value, 0, sizeof(count_value));
    memset(count_value_same, 0, sizeof(count_value_same));
    for (int i = 0; i < NUM_CARD; ++i) {
        ++count_value[int_value[card[i].value]];
    }
    for (int i = 1; i <= 13; ++i) {
        ++count_value_same[count_value[i]];
    }

    if (IsSameSuit(card) && IsOrder(card)) {
        return STRAIGHT_FLUSH;
    } else
    if (count_value_same[4]) {
        return FOUR_OF_A_KIND;
    } else
    if (count_value_same[3] && count_value_same[2]) {
        return FULL_HOUSE;
    } else
    if (IsSameSuit(card)) {
        return FLUSH;
    } else
    if (IsOrder(card)) {
        return STRAIGHT;
    } else
    if (count_value_same[3]) {
        return THREE_OF_A_KIND;
    } else
    if (count_value_same[2] == 2) {
        return TWO_PAIRS;
    } else
    if (count_value_same[2] == 1) {
        return ONE_PAIR;
    } else {
        return HIGHEST_CARD;
    }
}

void Search(int x) {
    Poker card[NUM_CARD];
    int top = 0;
    for (int i = 0; i < NUM_CARD; ++i) {
        if (x & (1 << i)) {
            card[top++] = hand[i];
        }
    }
    for (int i = 0; i < NUM_CARD && top < 5; ++i) {
        card[top++] = deck[i];
    }
    Type type = JudgeType(card);
    type_max = type > type_max ? type : type_max;
}
