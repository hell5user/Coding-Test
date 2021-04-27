#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    // 2번째 풀이
    unordered_map<string, int> hash;
    for (int i = 0; i < phone_book.size(); i++) {
        string s = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            s += phone_book[i][j];
            hash[s]++;
        }
    }
    for (auto s : phone_book)
        if (hash[s] >= 2) return false;
    return true;

    /*
    // 1번째 풀이
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++)
        if (phone_book[i + 1].compare(0, phone_book[i].size(), phone_book[i]) == 0)
            return false;
    return true;
    */
}
