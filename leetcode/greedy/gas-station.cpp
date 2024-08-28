// https://leetcode.com/problems/gas-station/

#include <vector>

using namespace std;

class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sz = gas.size();
        int tank = 0;
        int start = 0;
        for (int i = 0; i < sz + start && i < sz * 2; i++) {
            tank += gas[i % sz];
            if (tank < cost[i % sz]) {
                tank = 0;
                start = i + 1;
                continue;
            }
            tank -= cost[i % sz];
        }
        return start < sz ? start : -1;
    }
};

int main() { return 0; }
