// https://leetcode.com/problems/top-k-frequent-elements/

#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> valueToFreq;
        for (int num : nums) {
            auto it = valueToFreq.find(num);
            if (it == valueToFreq.end())
                valueToFreq[num] = 0;
            else
                it->second++;
        }
        multimap<int, int, greater<int>> freqToValue;
        for (auto [value, freq] : valueToFreq)
            freqToValue.emplace(freq, value);
        vector<int> topK;
        auto it = freqToValue.begin();
        for (int i = 0; i < k; i++, ++it)
            topK.push_back(it->second);
        return topK;
    }
};

int main() { return 0; }
