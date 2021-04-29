#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    // 2번째 풀이
    vector<int> answer;
    for (int m = 0; m < commands.size(); m++) {
        vector<int> tmp = array;
        int i = commands[m][0] - 1;
        int j = commands[m][1];
        int k = commands[m][2] - 1;
        sort(tmp.begin() + i, tmp.begin() + j);
        answer.push_back(tmp[i + k]);
    }
    return answer;

    /*
    // 1번째 풀이
    vector<int> answer;
    for (auto i : commands) {
        vector<int> temp = vector<int>(array.begin() + i[0] - 1, array.begin() + i[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[i[2] - 1]);
    }
    return answer;
    */
}
