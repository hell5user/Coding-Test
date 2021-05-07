#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n + 1, 1);

    for (auto i : lost)
        student[i]--;
    for (auto i : reserve)
        student[i]++;

    for (int i = 1; i <= n; i++) {
        if (student[i] == 0) {
            if (i > 1 && student[i - 1] == 2) {
                student[i - 1]--;
                student[i]++;
            }
            else if (i < n && student[i + 1] == 2) {
                student[i + 1]--;
                student[i]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (student[i] != 0) answer++;
    return answer;
}
