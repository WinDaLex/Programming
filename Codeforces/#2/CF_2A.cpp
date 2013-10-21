// CF 2A
// Winner
// by A Code Rabbit

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int MAXN = 1002;

struct result {
    string name;
    int total_score;
};

int N;

vector<result> results;
map<string, int> players;

int main() {
    cin >> N;

    players.clear();
    results.clear();
    for (int i = 0; i < N; i++) {
        string name; int score;
        cin >> name >> score;
        players[name] += score;
        results.push_back((result){name, players[name]});
    }

    int max_score = 0;
    for (map<string, int>::iterator it = players.begin(); it != players.end(); ++it)
        max_score = max(max_score, it->second);

    for (int i = 0; i < N; i++) {
        string name = results[i].name;
        if (players[name] == max_score && results[i].total_score >= max_score) {
            cout << name << endl;
            break;
        }
    }

    return 0;
}
