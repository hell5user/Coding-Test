#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> pieces;

    sort(numbers.begin(), numbers.end());
    do {
        string tmp = "";
        for (auto s : numbers) {
            tmp += s;
            pieces.push_back(stoi(tmp));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    sort(pieces.begin(), pieces.end());
    pieces.erase(unique(pieces.begin(), pieces.end()), pieces.end());

    for (auto i : pieces)
        if (isPrime(i)) answer++;
    return answer;
}
