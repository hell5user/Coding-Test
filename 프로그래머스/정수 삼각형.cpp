#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> sum(size, vector<int> (size));

    sum[0][0] = triangle[0][0];
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0)
                sum[i][j] = sum[i - 1][j] + triangle[i][j];
            else if (j == i)
                sum[i][j] = sum[i - 1][j - 1] + triangle[i][j];
            else
                sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + triangle[i][j];
        }
    }
    answer = *max_element(sum[size - 1].begin(), sum[size - 1].end());
    return answer;
}
