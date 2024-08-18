// https://leetcode.com/problems/top-k-frequent-words

// I believe this one has O(n log(k)) time complexity and O(n) extra space

#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
    struct Comparator {
        bool operator()(const pair<int, string> &lhs, const pair<int, string> &rhs) const {
            if (lhs.first == rhs.first)
                return lhs.second < rhs.second;
            return lhs.first > rhs.first;
        }
    };

  public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> wordToFreq;
        set<pair<int, string>, Comparator> freqToWord;
        for (const string &word : words) {
            auto it = wordToFreq.find(word);
            if (it == wordToFreq.end()) {
                wordToFreq[word] = 0;
                freqToWord.emplace(0, word);
            } else {
                int oldFreq = it->second;
                it->second++;
                freqToWord.erase({oldFreq, word});
                freqToWord.emplace(oldFreq + 1, word);
            }
            if (freqToWord.size() > k) {
                freqToWord.erase(prev(freqToWord.end()));
            }
        }
        vector<string> topK;
        for (const auto &[freq, word] : freqToWord)
            topK.push_back(word);
        return topK;
    }
};

int main() { return 0; }
