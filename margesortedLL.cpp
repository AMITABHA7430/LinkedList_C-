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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);          // ✅ Properly created node
        ListNode* tail = &dummy;   // ✅ Tail always points to last node

        ListNode* temp = list1;
        ListNode* lemp = list2;

        while (temp != NULL && lemp != NULL) {

            if (temp->val <= lemp->val) {   // ✅ Compare VALUES
                tail->next = temp;
                temp = temp->next;
            } 
            else {
                tail->next = lemp;
                lemp = lemp->next;
            }

            tail = tail->next;   // ✅ Move tail forward
        }

        // ✅ Attach remaining nodes
        if (temp != NULL)
            tail->next = temp;
        else
            tail->next = lemp;

        return dummy.next;  // ✅ Correct merged head
    }
};
