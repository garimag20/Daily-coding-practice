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
    
    ListNode* midpoint(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* a, ListNode* b){
        if(a == NULL)
            return b;
        if(b == NULL)
            return a;
        ListNode* c;
        if(a->val <= b->val){
            c = a;
            c->next = merge(a->next, b);
        }
        else{
            c = b;
            c->next = merge(a, b->next);
        }
        return c;
    }
    
    ListNode* sortList(ListNode* head) {
        //base case
        if(head == NULL || head->next == NULL)
            return head;
        
        //find mid point
        ListNode* mid = midpoint(head);
        
        //break at the mid
        ListNode* a = head;
        ListNode* b = mid->next;
        mid->next = NULL;
        
        //call sortlist for both sublists
        a = sortList(a);
        b = sortList(b);
        
        //merge function
        return merge(a,b);
    }
};