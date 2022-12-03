/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head->next)
            return;
        auto slow = head;
        auto fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto ptr = slow->next;
        slow->next = nullptr;
        auto ptr2 = ptr->next;
        ptr->next = nullptr;
        while (ptr && ptr2) {
            auto temp = ptr2->next;
            ptr2->next = ptr;
            ptr = ptr2;
            ptr2 = temp;
        }
        ptr2 = ptr;
        ptr = head;
        while (ptr && ptr2) {
            auto temp = ptr->next;
            auto temp2 = ptr2->next;
            ptr->next = ptr2;
            ptr2->next = temp;
            ptr = temp;
            ptr2 = temp2;
        }
    }
};