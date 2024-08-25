// https://leetcode.com/problems/accounts-merge/

#include <algorithm>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    class DisjointSet {
        vector<int> parent;
        vector<int> groupSize;

      public:
        DisjointSet(int capacity) {
            parent.resize(capacity + 1, 0);
            iota(parent.begin(), parent.end(), 0);
            groupSize.resize(capacity + 1, 1);
        }

        int find(int item) {
            if (parent[item] == item)
                return item;
            return parent[item] = find(parent[item]);
        }

        void unite(int item1, int item2) {
            int parent1 = find(item1);
            int parent2 = find(item2);
            if (parent1 == parent2)
                return;
            // Union-By-Size: merge group with less size into group with greater size
            if (groupSize[parent1] >= groupSize[parent2])
                swap(parent1, parent2);
            parent[parent1] = parent2;
            groupSize[parent2] += groupSize[parent1];
        }
    };

  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        DisjointSet dset(accounts.size());
        unordered_map<string, int> emails;
        for (int acc = 0; acc < accounts.size(); acc++) {
            for (int i = 1; i < accounts[acc].size(); i++) {
                string &email = accounts[acc][i];
                auto it = emails.find(email);
                if (it == emails.end()) {
                    emails[email] = acc;
                } else {
                    dset.unite(acc, it->second);
                }
            }
        }
        unordered_map<int, set<string>> groupedAccounts;
        for (auto &[email, i] : emails) {
            groupedAccounts[dset.find(i)].emplace(email);
        }
        vector<vector<string>> res;
        res.reserve(groupedAccounts.size());
        for (auto &[i, emailSet] : groupedAccounts) {
            res.emplace_back();
            res.back().emplace_back(accounts[i][0]);
            copy(emailSet.begin(), emailSet.end(), back_inserter(res.back()));
        }
        return res;
    }
};

namespace lazy {
class Solution {
    class DisjointSet {
        unordered_map<int, string> groups;
        map<string, int> emails;

      public:
        DisjointSet() = default;
        void singleton(const string &name, const string &email) {
            static int uid = 0;
            int currentId = uid++;
            groups[currentId] = name;
            emails[email] = currentId;
        }
        void unite(const string &email1, const string &email2) {
            int oldGroup = emails[email2];
            int newGroup = emails[email1];
            if (newGroup == oldGroup)
                return;
            for (auto &[email, group] : emails) {
                if (group == oldGroup)
                    group = newGroup;
            }
            groups.erase(oldGroup);
        }
        void strip() {
            set<int> allGroups;
            for (auto &[i, g] : groups)
                allGroups.insert(i);
            set<int> usedGroups;
            for (auto &[e, i] : emails)
                usedGroups.insert(i);
            vector<int> unusedGroups;
            set_difference(allGroups.begin(), allGroups.end(), usedGroups.begin(), usedGroups.end(),
                           back_inserter(unusedGroups));
            for (int i : unusedGroups)
                groups.erase(i);
        }
        vector<vector<string>> serialize() const {
            vector<vector<string>> res;
            unordered_map<int, int> normalizedIdx;
            res.reserve(groups.size());
            for (auto &[i, g] : groups) {
                normalizedIdx[i] = res.size();
                res.emplace_back();
                res.back().emplace_back(g);
            }
            for (auto &[e, i] : emails) {
                res[normalizedIdx[i]].push_back(e);
            }
            return res;
        }
    };

  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        DisjointSet emails;
        for (auto &acc : accounts) {
            for (int i = 1; i < acc.size(); i++) {
                emails.singleton(acc[0], acc[i]);
            }
        }
        for (auto &acc : accounts) {
            for (int i = 2; i < acc.size(); i++) {
                emails.unite(acc[1], acc[i]);
            }
        }
        emails.strip();
        return emails.serialize();
    }
};
} // namespace lazy

int main() { return 0; }
