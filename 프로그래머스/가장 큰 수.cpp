#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numS;

    for (auto i : numbers)
        numS.push_back(to_string(i));
    sort(numS.begin(), numS.end(), cmp);

    if (numS[0] == "0") return "0";
    for (auto s : numS) answer += s;
    return answer;
}
