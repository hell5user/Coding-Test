#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int scoring(vector<int> answers, vector<int> supoja) {
    int score = 0;
    int j = 0;
    for (int i = 0; i < answers.size(); i++) {
        j %= supoja.size();
        if (answers[i] == supoja[j]) score++;
        j++;
    }
    return score;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> result;
    vector<int> supoja1 = { 1, 2, 3, 4, 5 };
    vector<int> supoja2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> supoja3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    result.push_back(scoring(answers, supoja1));
    result.push_back(scoring(answers, supoja2));
    result.push_back(scoring(answers, supoja3));

    int max_score = *max_element(result.begin(), result.end());
    for (int i = 0; i < 3; i++)
        if (max_score == result[i]) answer.push_back(i + 1);
    return answer;
}
