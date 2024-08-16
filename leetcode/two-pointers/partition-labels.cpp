// https://leetcode.com/problems/partition-labels/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> partitionLabels(string s) {
        vector<int> partSizes;
        unordered_map<char, int> lastIdx;
        for (int i = 0; i < s.size(); i++) {
            lastIdx[s[i]] = i;
        }
        int i = 0;
        while (i < s.size()) {
            int iLast = lastIdx[s[i]];
            for (int j = i + 1; j < iLast; j++) {
                int jLast = lastIdx[s[j]];
                if (lastIdx[s[j]] > iLast)
                    iLast = jLast;
            }
            partSizes.push_back(iLast - i + 1);
            i = iLast + 1;
        }
        return partSizes;
    }
};

int main() {
    return 0;
}
