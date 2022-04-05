#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<std::pair<int, int>> passing;
    queue<int> waiting;
    int index = 1;
    int outindex = 0;
    
    int totalWeight = truck_weights[0];
    
    int lastin = 1;
    int lastout = bridge_length + 1;
    
    passing.push(make_pair(1, bridge_length + 1));
            // printf("new totalWeight: %d, lastout: %d\n", totalWeight, lastout);
    while (!passing.empty() && index < truck_weights.size())
    {
        // printf("index: %d\n", index);
        if (totalWeight + truck_weights[index] <= weight)
        {
            // printf("totalWeight: %d, truck_weights[index]: %d\n", totalWeight, truck_weights[index]);
            passing.push(make_pair(++lastin, lastin + bridge_length));
            lastout = lastin + bridge_length;
            totalWeight += truck_weights[index++];
            // printf("new totalWeight: %d, lastin:%d, lastout: %d\n", totalWeight, lastin, lastout);
        }
        else
        {
            totalWeight -= truck_weights[outindex++];
            std::pair<int, int> passingTop = passing.front();
            if (passingTop.second > lastin)
                lastin = passingTop.second - 1;
            // printf("Popping passing\n    now totalWeight: %d, outindex: %d\n    popping at = %d\n", totalWeight, outindex, lastin + 1);
            passing.pop();
            if (passing.empty() && index < truck_weights.size())
            {
                passing.push(make_pair(lastout, lastout + bridge_length));
                lastin = lastout;
                lastout += bridge_length;
                totalWeight += truck_weights[index++];
                // printf("    new totalWeight: %d, lastin:%d, lastout: %d\n", totalWeight, lastin, lastout);
            }
        }        
    }
    return lastout;
}
