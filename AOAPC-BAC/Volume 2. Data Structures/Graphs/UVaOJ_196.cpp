// UVaOJ 196
// Spreadsheet
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <cctype>

const int LIMITS = 1234;
const int LIMITS_NODE = 1000000;

int t;

struct Cell {
    int value;
    int index;
};

Cell spreadsheet[LIMITS][LIMITS];
int n, m;

struct Node {
    int x;
    int y;
    int succ;
};

Node node[LIMITS_NODE];
int num_node;

bool IsLetter(char ch);
void Process(int x, int y, char* str);
int GetValue(int x, int y);

int main() {
    scanf("%d", &t);
    while (t--) {
        // INIT.
        num_node = 0;
        // Inputs.
        scanf("%d%d", &n, &m);
        getchar();
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                char str[100];
                scanf("%s", str);
                Process(i, j, str);
            }
            getchar();
        }
        // Get the values of cells of the spreadsheet.
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (spreadsheet[i][j].index != -1) {
                    GetValue(i, j);
                }
            }
        }
        // Outputs.
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n - 1; ++j) {
                printf("%d ", spreadsheet[i][j].value);
            }
            printf("%d\n", spreadsheet[i][n]);
        }
    }

    return 0;
}

void Process(int x, int y, char* str) {
    if (str[0] != '=') {
        sscanf(str, "%d", &spreadsheet[x][y].value);
        spreadsheet[x][y].index = -1;
    } else {
        spreadsheet[x][y].index = num_node;
        int pos = 1;
        while (pos < strlen(str)) {
            if (isalnum(str[pos])) {
                Node& new_node = node[num_node];
                new_node.x = 0;
                new_node.y = 0;
                while (isalpha(str[pos])) {
                    new_node.y = new_node.y * 26 + str[pos] - 'A' + 1;
                    pos++;
                }
                while (isdigit(str[pos])) {
                    new_node.x = new_node.x * 10 + str[pos] - '0';
                    pos++;
                }
                
            }
            node[num_node].succ = num_node + 1;
            ++num_node;
            ++pos;
        }
        node[num_node - 1].succ = -1;
    }
}

int GetValue(int x, int y) {
    if (spreadsheet[x][y].index == -1) {
        return spreadsheet[x][y].value;
    } else {
        int sum = 0;
        int index = spreadsheet[x][y].index;
        while (index != -1) {
            sum += GetValue(node[index].x, node[index].y);
            index = node[index].succ;
        }
        spreadsheet[x][y].value = sum;
        spreadsheet[x][y].index = -1;
        return sum;
    }
}
