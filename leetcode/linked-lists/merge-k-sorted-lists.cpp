// https://leetcode.com/problems/merge-k-sorted-lists/

#include <functional>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
  public:
    ListNode *mergeKListsNaive(vector<ListNode *> &lists) {
        vector<ListNode *> allLists = lists;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        constexpr size_t sentinel = numeric_limits<size_t>::max();
        while (true) {
            int minVal = numeric_limits<int>::max();
            size_t minIdx = sentinel;
            for (size_t i = 0; i < allLists.size(); i++) {
                ListNode *&node = allLists[i];
                if (node == nullptr)
                    continue;
                if (node->val < minVal) {
                    minVal = node->val;
                    minIdx = i;
                }
            }
            if (minIdx == sentinel)
                break;
            ListNode *&node = allLists[minIdx];
            if (head == nullptr) {
                head = new ListNode(node->val);
                tail = head;
            } else {
                ListNode *next = new ListNode(node->val);
                tail->next = next;
                tail = next;
            }
            node = node->next;
        }
        return head;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return nullptr;
        if (lists.size() == 1)
            return lists.front();
        priority_queue<int, vector<int>, greater<int>> values;
        for (auto *node : lists) {
            while (node != nullptr) {
                values.push(node->val);
                node = node->next;
            }
        }
        ListNode *fakeHead = new ListNode;
        ListNode *tail = fakeHead;
        while (!values.empty()) {
            tail->next = new ListNode(values.top());
            tail = tail->next;
            values.pop();
        }
        ListNode *head = fakeHead->next;
        delete fakeHead;
        return head;
    }
};

int main() {
    return 0;
}
