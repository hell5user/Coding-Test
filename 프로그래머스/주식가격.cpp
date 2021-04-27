#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    // 2번째 풀이
    int size = prices.size();
    vector<int> answer(size);
    stack<int> idx_st;
    
    for (int i = 0; i < size; i++) {
        while (!idx_st.empty() && prices[idx_st.top()] > prices[i]) {
            answer[idx_st.top()] = i - idx_st.top();
            idx_st.pop();
        }
        idx_st.push(i);
    }
    while (!idx_st.empty()) {
        answer[idx_st.top()] = size - idx_st.top() - 1;
        idx_st.pop();
    }
    return answer;

    /*
    // 1번째 풀이
    vector<int> answer;

    for (int i = 0; i < prices.size(); i++) {
        int sec = 0;
        for (int j = i + 1; j < prices.size(); j++) {
            sec++;
            if (prices[i] > prices[j]) break;
        }
        answer.push_back(sec);
    }
    return answer;
    */
}
