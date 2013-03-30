// UVaOJ 101
// The Blocks Problem
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS = 100;

struct Node {
    Node* pred;
    int val;
    Node* succ;
};

int n;
char command[100];
char first_word[20];
char second_word[20];
int a, b;

Node* head[LIMITS];
Node* block[LIMITS];
int pos[LIMITS];

void INIT();

void ReturnOriginalPos(Node *p);
void Connect(Node* a, Node* b);

void MoveAOntoB(Node* a, Node* b);
void MoveAOverB(Node* a, Node* b);
void PileAOntoB(Node* a, Node* b);
void PileAOverB(Node* a, Node* b); 

void Outputs();

int main() {
    while (scanf("%d", &n) != EOF) {
        getchar();
        // INIT.
        INIT();
        // Inputs and operating.
        while (scanf("%s", first_word)){
            if (strcmp(first_word, "quit") == 0) {
               break;
            }
            gets(command);
            sscanf(command, "%d%s%d", &a, second_word, &b);
            if (pos[a] != pos[b]) {
                if (strcmp(first_word, "move") == 0) {
                    if (strcmp(second_word, "onto") == 0) {
                        MoveAOntoB(block[a], block[b]);
                    } else
                    if (strcmp(second_word, "over") == 0) {
                        MoveAOverB(block[a], block[b]);
                    }
                } else
                if (strcmp(first_word, "pile") == 0) {
                    if (strcmp(second_word, "onto") == 0) {
                        PileAOntoB(block[a], block[b]);
                    } else
                    if (strcmp(second_word, "over") == 0) {
                        PileAOverB(block[a], block[b]);
                    }
                }
            }
        }
        // Outputs.
        Outputs();
        // Release all pointers.
        for (int i = 0; i < n; ++i) {
            delete block[i];
            delete head[i];
        }
    }

    return 0;
}

void INIT() {
    for (int i = 0; i < n; ++i) {
        head[i]  = new Node;
        block[i] = new Node;
        head[i]->pred = NULL;
        head[i]->val = -1;
        head[i]->succ = block[i];
        block[i]->pred = head[i];
        block[i]->val = i;
        block[i]->succ = NULL;
        pos[i] = i;
    }
}

void ReturnOriginalPos(Node* p) {
    if (p == NULL) {
        return;
    }
    ReturnOriginalPos(p->succ);
    p->pred = head[p->val];
    p->succ = NULL;
    head[p->val]->succ = p;
    pos[p->val] = p->val; 
}

void Connect(Node* a, Node* b) {
    a->pred->succ = NULL;
    a->pred = b;
    b->succ = a;
    pos[a->val] = pos[b->val];
}

void MoveAOntoB(Node* a, Node* b) {
    ReturnOriginalPos(a->succ);
    ReturnOriginalPos(b->succ);
    a->succ = NULL;
    Connect(a, b);
}

void MoveAOverB(Node* a, Node* b) {
    ReturnOriginalPos(a->succ);
    a->succ = NULL;
    Node* b_tail = b;
    while (b_tail->succ != NULL) {
        b_tail = b_tail->succ;
    }
    Connect(a, b_tail);
}

void PileAOntoB(Node* a, Node* b) {
    ReturnOriginalPos(b->succ);
    Connect(a, b);
    Node* p = a->succ;
    while (p != NULL) {
        pos[p->val] = pos[b->val];
        p = p->succ;
    }
}

void PileAOverB(Node* a, Node* b) {
    Node* b_tail = b;
    while (b_tail->succ != NULL) {
        b_tail = b_tail->succ;
    }
    Connect(a, b_tail);
    Node* p = a->succ;
    while (p != NULL) {
        pos[p->val] = pos[b->val];
        p = p->succ;
    }
}

void Outputs() {
    for (int i = 0; i < n; ++i) {
        printf("%d:", i);
        Node* p = head[i]->succ;
        while (p != NULL) {
            printf(" %d", p->val);
            p = p->succ;
        }
        printf("\n");
    }
}
