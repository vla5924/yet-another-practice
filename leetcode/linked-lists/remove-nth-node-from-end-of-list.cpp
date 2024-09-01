// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *curr = head;
        ListNode *defer = head;
        int sz = 0;
        while (curr != nullptr) {
            sz++;
            curr = curr->next;
            if (sz > n + 1)
                defer = defer->next;
        }
        if (sz <= n)
            return head->next;
        defer->next = defer->next->next;
        return head;
    }
};

int main() { return 0; }
