class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        bool ami=false;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                ami=true;
                break;
            }
            
        
        }
        if(!ami){
            return NULL;
        }
        
            slow=head;
            while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                   
                }
        
        return slow;
    }

};
