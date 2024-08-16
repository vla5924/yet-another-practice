// https://leetcode.com/problems/linked-list-cycle/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
  public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *first = head;
        ListNode *second = head;
        do {
            if (first == nullptr || second == nullptr)
                return false;
            first = first->next;
            if (second->next == nullptr)
                return false;
            second = second->next->next;
        } while (first != second);
        return true;
    }
};

int main() {
    return 0;
}
