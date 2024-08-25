// https://leetcode.com/problems/middle-of-the-linked-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *middleNode(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *each = head;
        ListNode *cherez1 = head;
        while (cherez1) {
            if (cherez1->next == nullptr)
                break;
            cherez1 = cherez1->next->next;
            each = each->next;
        }
        return each;
    }
};

int main() { return 0; }
