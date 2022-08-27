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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head)
            return head;
        if (!head->next) 
            return NULL;
        auto s = head;
        auto f = head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        if (!s->next) {
            head->next = NULL;
        }else {
        *s=*s->next;
        }
        return head;
    }
};