#include <queue>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 1번째 풀이
    int answer = 0;
    int next_truck = 0;  // 대기 트럭 중 맨 앞 트럭의 인덱스
    int weight_sum = 0;  // 다리 위 트럭의 무게 합
    queue<int> on_bridge;  // 다리 위 트럭

    for (int i = 0; i < bridge_length; i++)
        on_bridge.push(0);

    while (!on_bridge.empty()) {
        answer++;
        weight_sum -= on_bridge.front();
        on_bridge.pop();

        if (next_truck < truck_weights.size()) {
            if (weight_sum + truck_weights[next_truck] <= weight) {
                weight_sum += truck_weights[next_truck];
                on_bridge.push(truck_weights[next_truck]);
                next_truck++;
            } else {
                on_bridge.push(0);
            }
        }
    }
    
    return answer;
}
