// https://leetcode.com/problems/k-closest-points-to-origin/

#include <deque>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    struct GreaterDistance {
        bool operator()(const vector<int> &lhs, const vector<int> &rhs) const {
            return sqrt(double(lhs[0] * lhs[0] + lhs[1] * lhs[1])) > sqrt(double(rhs[0] * rhs[0] + rhs[1] * rhs[1]));
        }
    };

  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<vector<int>, deque<vector<int>>, GreaterDistance> closest;
        for (int i = 0; i < points.size(); i++)
            closest.push(points[i]);
        vector<vector<int>> kclosest;
        for (int i = 0; i < k; i++) {
            kclosest.push_back(closest.top());
            closest.pop();
        }
        return kclosest;
    }
};

int main() { return 0; }
