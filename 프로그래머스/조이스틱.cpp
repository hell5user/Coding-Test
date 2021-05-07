#include <string>
#include <vector>
using namespace std;

int solution(string name) {
    int shift = name.length() - 1;  // 한쪽 방향만

    /* ◀ ▶ */
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 'A') {
            int target = i;
            while (target < name.length() && name[target] == 'A') target++;
            int left = (i == 0 ? 0 : i - 1);
            int right = name.length() - target;

            shift = min(shift, left + right + min(left, right));
        }
    }

    /* ▲ ▼ */
    for (auto c : name)
        if (c != 'A') shift += min(c - 'A', 'Z' - c + 1);

    return shift;
}
