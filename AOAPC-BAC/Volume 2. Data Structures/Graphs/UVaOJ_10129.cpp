// UVaOJ 10129
// Play on Words
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS = 2000;

int t;

char word[LIMITS];
int n;

bool graph[30][30];
bool is_existing[30];
int difference[30]; // It means the in_order minus the out_order.

bool is_visited[30];

void Process(char* word);
bool MatchCondition();
int Search(int pos);

int main() {
    scanf("%d", &t);
    while (t--) {
        // INIT.
        memset(difference, 0, sizeof(difference));
        memset(graph, false, sizeof(graph));
        memset(is_existing, false, sizeof(is_existing));
        memset(is_visited, false, sizeof(is_visited));
        // Inputs and count.
        scanf("%d", &n);
        getchar();
        while (n--) {
            gets(word);
            // Processing string.
            Process(word);
        }
        // Compete the number of letters.
        int num_letters = 0;
        for (int i = 0; i < 26; ++i) {
            if (is_existing[i]) {
                ++num_letters;
            }
        }
        // Judge whether in_order and out_order match condition.
        bool can_order = MatchCondition();   
        // Judge whether the graph without direction is a connected graph.
        if (can_order) {
            for (int i = 0; i < 26; ++i) {
                if (is_existing[i]) {
                    if (num_letters != Search(i)) {
                        can_order = false;
                    }
                    break;
                }
            }
        }
        // Outputs.
        printf("%s\n", can_order ? "Ordering is possible." : "The door cannot be opened.");
    }

    return 0;
}

void Process(char *word) {
    int first = word[0] - 'a';
    int last = word[strlen(word) - 1] - 'a';
    ++difference[first];
    --difference[last];
    graph[first][last] = true;
    graph[last][first] = true;
    is_existing[first] = true;
    is_existing[last] = true;
}

bool MatchCondition() {
    int num_nonzero = 0;
    int num[26];
    for (int i = 0; i < 26; ++i) {
        if (difference[i]) {
            num[num_nonzero++] = difference[i];
        }
    }
    if (num_nonzero == 0) {
        return true;
    }
    if (num_nonzero != 2) {
        return false;
    }
    if ((num[0] == -1 && num[1] ==  1) || 
        (num[0] ==  1 && num[1] == -1))
    {
        return true;
    } else {
        return false;
    }
}

int Search(int pos) {
    if (is_visited[pos]) {
        return 0;
    }
    is_visited[pos] = true;
    int sum = 1;
    for (int i = 0; i < 26; ++i) {
        if (graph[pos][i]) {
            sum += Search(i);
        }
    }
    return sum;
}
