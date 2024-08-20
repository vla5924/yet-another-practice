// https://leetcode.com/problems/ransom-note/

#include <string>

using namespace std;

class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        int counter[26] = {0};
        for (int i = 0; i < magazine.size(); i++)
            counter[magazine[i] - 'a']++;
        for (int i = 0; i < ransomNote.size(); i++)
            if (counter[ransomNote[i] - 'a']-- == 0)
                return false;
        return true;
    }
};

int main() { return 0; }
