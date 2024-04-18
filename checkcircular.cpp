/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* runner = head;
        while (runner && runner->next) {
            runner = runner->next->next;
            head = head->next;
            if (runner == head)
                return 1;
        }
        return 0;
    }
};