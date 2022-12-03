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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(INT_MIN);
        ListNode* list = ans;
        bool flag = true;
        int min_head = 0;
        while (min_head != INT_MAX) {
            min_head = INT_MAX;
            int min_index;
            ListNode* head;
            for (int i = 0; i < lists.size(); i++) {
                auto h = lists[i];
                if (h) {
                    if (h->val < min_head) {
                        head = h;
                        min_head = h->val;
                        min_index = i;
                    }
                }
            }
            if (min_head != INT_MAX) {
                list->next = head;
                lists[min_index] = lists[min_index]->next;
                list = list->next;
                list->next = nullptr;
            }
        }
        
        return ans->next;
    }
};