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
    
    int getcount(ListNode *head){
        int c = 0;
        ListNode *temp = head;
        
        while(temp != NULL){
            c++;
            temp = temp->next;
        }
        return c;
    }
    
    ListNode *getinsertingnode(int d , ListNode *head, ListNode *node){
        ListNode* curr1 = head;
        ListNode* curr2 = node;
        
        for(int i = 0; i < d; i++){
            curr1 = curr1->next;
        }
        
        while(curr1 && curr2){
            if(curr1 == curr2)
                return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        } 
        return NULL;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1 = getcount(headA);
        int c2 = getcount(headB);
                
        if(c1 > c2){
            return getinsertingnode(c1-c2, headA, headB);
        }
        else{
            return getinsertingnode(c2-c1, headB, headA);
        }
        return NULL;
    }
};