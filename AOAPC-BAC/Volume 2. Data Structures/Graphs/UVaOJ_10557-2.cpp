// UVaOJ 10557
// XYZZY
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS_NUM_ROOM = 120;
const int LIMITS_QUEUE = 1000000;
const int LIMITS_ENERGY_NEED = 100000;

struct Room {
    int energy;
    int doorways[LIMITS_NUM_ROOM];
    int num_doorways;
    int last_energy;
};

Room room[LIMITS_NUM_ROOM];
int n;

struct Status {
    int pos;
    int energy;
};

Status queue[LIMITS_QUEUE];
int head, tail;
bool is_found;

void BFS();
void INIT();
void Search(int pos, int energy);

int main() {
    while (scanf("%d", &n), n != -1) {
        // Inputs and INIT status of rooms.
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &room[i].energy, &room[i].num_doorways);
            for (int j = 0; j < room[i].num_doorways; ++j) {
                scanf("%d", &room[i].doorways[j]);
            }
            room[i].last_energy = 0;
        }
        // BFS.
        BFS();
        // Outputs.
        printf("%s\n", is_found ? "winnable" : "hopeless");
    }

    return 0;
}

void BFS() {
    INIT();
    Search(1, 100);
    while (head < tail) {
        // Judge whether searching fall into loops.
        if (queue[head].energy > LIMITS_ENERGY_NEED)
            break;
        int pos_room = queue[head].pos;
        for (int i = 0; i < room[pos_room].num_doorways; ++i) {
            int pos_room_new = room[pos_room].doorways[i];
            Search(pos_room_new, queue[head].energy + room[pos_room_new].energy);
        }
        ++head;
    }
}

void INIT() {
    head = 0;
    tail = 0;
    is_found = false;
}

void Search(int pos, int energy) {
    // Exit.
    if (is_found) {
        return;
    }
    if (energy <= 0) {
        return;
    }
    // Judge whether this is target.
    if (pos == n) {
        is_found = true;
        return;
    }
    // Update last energy of this room.
    if (energy > room[pos].last_energy) {
        room[pos].last_energy = energy;
    } else {
        return;
    }
    // Push.
    queue[tail].pos = pos;
    queue[tail].energy = energy;
    ++tail;
}
