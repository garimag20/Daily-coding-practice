/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void createll(Node* head){
        Node* old = head;
        
        while(old != NULL){
            Node* temp = new Node(old->val);
            temp->next = old->next;
            old->next = temp;
            old = old->next->next;
        }
    }
    
    void assignrandom(Node* head){
        Node* old = head;
        Node* newh = head->next;
        while(old != NULL){
            if(old->random != NULL)
                newh->random = old->random->next;
            else
                newh->random = NULL;
            if(newh->next != NULL)
                newh = newh->next->next;
            old = old->next->next;
        }
    }
    
    Node* restore(Node* head){
        Node* old = head;
        Node* temp = head->next;
        Node* newh = temp;
        
        old->next = old->next->next;
        old = old->next;
        
        while(old){
            temp->next = old->next;
            temp = temp->next;
            old->next = old->next->next;
            old = old->next;
        }
        
        return newh;
    }
    
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        //step 1 create a new ll 
        createll(head);
        //step 2 assign random
        assignrandom(head);
        //step 3 restore
        return restore(head);
    }
};