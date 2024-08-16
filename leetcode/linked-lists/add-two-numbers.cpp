// https://leetcode.com/problems/add-two-numbers

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
    void add(ListNode *l1, ListNode *l2, ListNode *res, int carry) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        auto *newnode = new ListNode(sum % 10);
        res->next = newnode;
        res = newnode;
        carry = sum / 10;
        if (l1 == nullptr && l2 == nullptr) {
            if (carry != 0) {
                auto *newnode = new ListNode(sum / 10);
                res->next = newnode;
                res = newnode;
            }
            return;
        }
        add(l1, l2, res, carry);
    }

  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto *res = new ListNode(0);
        add(l1, l2, res, 0);
        if (res->next != nullptr) {
            auto *newres = res->next;
            delete res;
            res = newres;
        }
        return res;
    }
};

int main() {
    return 0;
}
