// UVaOJ 133
// The Dole Queue
// by A Code Rabbit

#include <cstdio>

struct Node {
    Node* pred;
    int num;
    Node* succ;
};

int n, k, m;

Node* head;
Node* tail;
Node* official_1;
Node* official_2;
int num_people;

void MakeList();

void CountOff(Node*& p, int num, bool is_reverse);
void Delete(Node*& p, bool is_reverse);

int main() {
    while (scanf("%d%d%d", &n, &k, &m)) {
        // Exit.
        if (!n && !k && !m) {
            break;
        }
        // INIT.
        MakeList();
        official_1 = head;
        official_2 = tail;
        num_people = n;
        // Solving and outputs.
        while (num_people) {
            // Count off.
            CountOff(official_1, k - 1, false);
            CountOff(official_2, m - 1, true);
            // Send off.
            if (official_1 != official_2) {
                // Outputs.
                printf("%3d%3d", official_1->num, official_2->num);
                if (num_people != 2) {
                    printf(",");
                } else {
                    printf("\n");
                }
                // Delete.
                Delete(official_1, false);
                Delete(official_2, true);
                num_people -= 2;
            } else {
                // Outputs.
                printf("%3d", official_1->num);
                if (num_people != 1) {
                    printf(",");
                } else {
                    printf("\n");
                }
                // Delete.
                official_2 = official_2->pred;
                Delete(official_1, false);
                num_people--;
            }
        }
    }

    return 0;
}

void MakeList() {
    Node* p = new Node;
    head = p;
    for (int i = 0; i < n - 1; ++i) {
        p->num = i + 1;
        p->succ = new Node;
        p->succ->pred = p;
        p = p->succ;
    }
    tail = p;
    tail->num = n;
    tail->succ = head;
    head->pred = tail;
}

void CountOff(Node*& p, int num, bool is_reverse) {
    while (num--) {
        p = is_reverse ? p->pred : p->succ;
    }
}

void Delete(Node*& p, bool is_reverse) {
    // Connect pred and succ.
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    // NOTE: Official_1 is maybe deleted when delete offcial_2.
    if (is_reverse && official_2 == official_1)  {
        official_1 = official_1->succ;
    }
    // Delete.
    Node* temp = is_reverse ? p->pred : p->succ;
    delete p;
    p = temp;
}

