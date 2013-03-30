// UvaOJ 127
// "Accordian Patience"
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS = 100;

char str[10];

char piles[LIMITS][LIMITS][10];
int top_piles[LIMITS];
int num_piles;

bool Match(char*, char*);
bool Move(int, int);

void Outputs();

int main() {
    while (scanf("%s", str)) {
        // Exit.
        if (str[0] == '#') {
            break;
        }
        // INIT.
        memset(piles, 0, sizeof(0));
        memset(top_piles, 0, sizeof(0));
        num_piles = 0;
        // Inputs.
        strcpy(piles[0][0], str);
        for (int i = 1; i < 52; ++i) {
            scanf("%s", piles[i][0]);
        }
        for (int i = 0; i < 52; ++i) {
            top_piles[i] = 1;
        }
        num_piles = 52;
        // Play the game.
        bool is_moved = true;
        while (is_moved) {
            is_moved = false;
            for (int i = 0; i < num_piles; ++i) {
                if (Move(i - 3, i) || Move(i - 1, i)) {
                    is_moved = true;
                    break;
                }
            }
        }
        // Outputs.
        Outputs();
    }

    return 0;
}

bool Match(char* card_1, char* card_2) {
    return card_1[0] == card_2[0]
        || card_1[1] == card_2[1];
}

bool Move(int pos_1, int pos_2) {
    int& top_1 = top_piles[pos_1];
    int& top_2 = top_piles[pos_2];
    // Avoid subscipt beyond bounds. 
    if (pos_1 < 0) {
        return false;
    }
    // Check up whether two cards is matching.
    if (!Match(piles[pos_1][top_1 - 1], piles[pos_2][top_2 - 1])) {
        return false;
    }
    // Exchange the positions of two cards.
    strcpy(piles[pos_1][top_1], piles[pos_2][top_2 - 1]);
    ++top_1;
    --top_2;
    // Move right piles if the pile is empty.
    if (!top_piles[pos_2]) {
        for (int i = pos_2; i < num_piles - 1; ++i) {
            top_piles[i] = top_piles[i + 1];
            for (int j = 0; j < top_piles[i]; ++j) {
                strcpy(piles[i][j], piles[i + 1][j]);
            }
        }
        --num_piles;
    }

    return true;
}

void Outputs() {
    printf("%d", num_piles);
    if (num_piles > 1) {
        printf(" piles remaining:");
    } else {
        printf(" pile remaining:");
    }
    for (int i = 0; i < num_piles; ++i) {
        printf(" %d", top_piles[i]);
    }
    printf("\n");
}
