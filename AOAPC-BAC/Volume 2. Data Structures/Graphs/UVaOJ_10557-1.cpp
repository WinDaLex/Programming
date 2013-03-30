// UVaOJ 10557
// XYZZY
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS = 120;

struct Room {
    int energy;
    int doorways[LIMITS];
    int num_doorways;
    int last_energy;
};

Room room[LIMITS];
int n;

bool is_visited[LIMITS];

bool CanArrive(int pos);
bool Search(int pos, int energy);

int main() {
    while (scanf("%d", &n), n != -1) {
        // Inputs and INIT status of rooms.
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &room[i].energy, &room[i].num_doorways);
            for (int j = 0; j < room[i].num_doorways; ++j) {
                scanf("%d", &room[i].doorways[j]);
            }
            room[i].last_energy = -1;
            /* -1 means that the room is never visited. */
        }
        // Outputs.
        printf("%s\n", Search(1, 100) ? "winnable" : "hopeless");
    }

    return 0;
}

bool Search(int pos, int energy) {
    // Exit.
    if (energy <= 0) {
        return false;
    }
    // Judge whether this is target.
    if (pos == n) {
        return true;
    }
    // If enter this room secondly.
    if (room[pos].last_energy != -1) {
        if (energy > room[pos].last_energy) {
           /* ? */ memset(is_visited, false, sizeof(is_visited));
            if (CanArrive(pos)) {
                return true;
            }
        }
        return false;
    };
    // Continue.
    room[pos].last_energy = energy;
    for (int i = 0; i < room[pos].num_doorways; ++i) {
        int pos_room_new = room[pos].doorways[i];
        if (Search(pos_room_new, energy + room[pos_room_new].energy)) {
            return true;
        }
    }
    return false;
}


bool CanArrive(int pos) {
    // Exit.
    if (is_visited[pos]) {
        return false;
    }
    // Judge whether this is target.
    if (pos == n) {
        return true;
    }
    // Continue.
    is_visited[pos] = true;
    for (int i = 0; i < room[pos].num_doorways; ++i) {
        if (CanArrive(room[pos].doorways[i])) {
            return true;
        }
    }
    return false;
}
