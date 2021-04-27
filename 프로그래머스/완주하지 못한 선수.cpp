#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    // 3번째 풀이
    unordered_map<string, int> participants;

    for (auto s : participant)
        participants[s]++;
    for (auto s : completion)
        participants[s]--;
    for (auto m : participants)
        if (m.second == 1) return m.first;

    /*
    // 2번째 풀이
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int i = 0;
    while (i < completion.size()) {
        if (completion[i] != participant[i]) {
            cout << participant[i] << endl;
            return participant[i];
        }
        i++;
    }
    cout << participant.back() << endl;
    return participant.back();
    */
    /*
    // 1번째 풀이
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    vector<string> result(participant.size() + completion.size());
    auto iter = set_difference(participant.begin(), participant.end(), completion.begin(), completion.end(), result.begin());
    result.erase(iter, result.end());

    //cout << result.front() << endl;
    answer += result.front();
    return answer;
    */
}
