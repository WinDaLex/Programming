// UVaOJ 10194
// Football(aka Soccer)
// by A Code Rabbit

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string ToLower(string);

struct Team {
    string name;
    int point;
    int game;
    int win, tie, loss;
    int scored, against, difference;
    void Init() {
        point = game = win = tie = loss = scored = against = difference = 0;
    }
    bool operator<(Team another) const {
        if (this->point != another.point)
            return this->point > another.point;
        else if (this->win != another.win)
            return this->win > another.win;
        else if (this->difference != another.difference)
            return this->difference > another.difference;
        else if (this->scored != another.scored)
            return this->scored > another.scored;
        else if (this->game != another.game)
            return this->game < another.game;
        else
            return ToLower(this->name) < ToLower(another.name);
    }
};

string tournament;
int t;
Team team[32];
int g;
string team_name_1, team_name_2;
int goals1, goals2;

void Analyze(string team1, string team2, int goal1, int goal2);

int main() {
    int tot_case;
    cin >> tot_case;
    cin.get();
    while (tot_case--) {
        // Input.
        getline(cin, tournament);
        cin >> t;
        cin.get();
        for (int i = 0; i < t; i++) {
            team[i].Init();
            getline(cin, team[i].name);
        }
        cin >> g;
        cin.get();
        // Input data and analyze data.
        for (int i = 0; i < g; i++) {
            getline(cin, team_name_1, '#');
            cin >> goals1;
            cin.get();
            cin >> goals2;
            cin.get();
            getline(cin, team_name_2);
            Analyze(team_name_1, team_name_2, goals1, goals2);
        }
        // Rank.
        sort(team, team + t);
        // Output.
        printf("%s\n", tournament.c_str());
        for (int i = 0; i < t; i++) {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                i + 1, team[i].name.c_str(), team[i].point, team[i].game,
                team[i].win, team[i].tie, team[i].loss, team[i].difference,
                team[i].scored, team[i].against);
        }
        printf("%s", tot_case ? "\n" : "");
    }

    return 0;
}

string ToLower(string str) {
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
    return str;
}

void Analyze(string team_name_1, string team_name_2, int goal1, int goal2) {
    Team* team1;
    Team* team2;
    for (int i = 0; i < t; i++) {
        if (team[i].name == team_name_1)
            team1 = &team[i];
        if (team[i].name == team_name_2)
            team2 = &team[i];
    }
    
    if (goal1 > goal2) {
        team1->point += 3; 
        team1->win++;
        team2->loss++;
    } else
    if (goal1 < goal2) {
        team1->loss++;
        team2->win++;
        team2->point += 3;
    } else
    if (goal1 == goal2) {
        team1->point++;
        team1->tie++;
        team2->point++;
        team2->tie++;
    }
    
    team1->game++;
    team1->scored += goal1;
    team1->against += goal2;
    team1->difference = team1->scored - team1->against;
    
    team2->game++;
    team2->scored += goal2;
    team2->against += goal1;
    team2->difference = team2->scored - team2->against;
}
