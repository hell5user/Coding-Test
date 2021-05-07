#include <string>
#include <vector>
using namespace std;

void dfs(int n, vector<vector<int>> &computers, int x, vector<bool> &check) {
    check[x] = true;
    for (int i = 0; i < n; i++)
        if(!check[i] && computers[x][i] == 1)
            dfs(n, computers, i, check);
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> check(n);

    for (int i = 0; i < n; i++) {
        if(!check[i]) {
            dfs(n, computers, i, check);
            answer++;
        }
    }
    return answer;
}
