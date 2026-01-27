#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;

struct Participant {
    string name;
    vector<int> scores;
    double average;
    int rank;
};

int main() {
    int n, m, k;
    cin >> n >> m;
    cin >> k;

    vector<Participant> participants(n);

    for (int i = 0; i < n; ++i) {
        cin >> participants[i].name;
        participants[i].scores.resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> participants[i].scores[j];
        }

        sort(participants[i].scores.begin(), participants[i].scores.end());
        vector<int> valid_scores(participants[i].scores.begin() + k, participants[i].scores.end() - k);

        double sum = 0;
        for (int score : valid_scores) sum += score;
        double avg = sum / valid_scores.size();

        participants[i].average = round(avg * 10) / 10.0;
    }

    vector<double> avg_scores;
    for (const auto& p : participants) avg_scores.push_back(p.average);
    sort(avg_scores.begin(), avg_scores.end(), greater<>());

    map<double, int> rank_map;
    int current_rank = 1;
    for (int i = 0; i < avg_scores.size(); ++i) {
        if (rank_map.find(avg_scores[i]) == rank_map.end()) {
            rank_map[avg_scores[i]] = current_rank;
        }
        current_rank++;
    }
    for (const auto& p : participants) {
        cout << rank_map[p.average] << " " << p.name << " ";
        cout << fixed << setprecision(1) << p.average << endl;
    }
}
