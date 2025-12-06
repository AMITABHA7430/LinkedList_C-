
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=1;
        while(temp!=NULL){
            temp=temp->next;
            count++;

        }
        ListNode* ami=head;
        int result=count/2;
        if(count%2==0){
        
        
        for(int i=0;i<result-1;i++){
            ami=ami->next;

        }}
        else{
            
             
            for(int i=0;i<result;i++){
                ami=ami->next;

        }
        }
        return ami;
    }
};
