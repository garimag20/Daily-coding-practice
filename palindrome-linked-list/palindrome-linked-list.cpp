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
    bool isPalindrome(ListNode* head) {
        //base case
        if(head == NULL || head->next == NULL)
            return true;
        
        //find middle of LL
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //reverse 2nd half
        //1->2->2->2->1 converts to 1->2->2<-2<-1
        //1->2->2->1 converts to 1->2->2<-1
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* after = slow;
        
        while(curr != NULL){
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        
        //comparing both the halves
        
        ListNode* p = head;
        ListNode* q = prev;
        
        while(p != q){
            if(p->val != q->val)
                return false;
            if(p->next == q)
                return true;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};