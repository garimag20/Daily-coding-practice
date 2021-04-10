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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* temp = head;
        ListNode* prev = dummy;
        while(temp){
            while(temp->next && temp->val == temp->next->val)
                temp = temp->next;
            if(prev->next == temp)
                prev = prev->next;
            else
                prev->next = temp->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};