#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        std::unordered_map<Node*, Node*> m;

        // 1) create copy nodes and map old->new (for all nodes)
        Node* newHead = new Node(head->val);
        m[head] = newHead;

        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        while (oldTemp != nullptr) {
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // 2) set random pointers using the map
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != nullptr) {
            if (oldTemp->random != nullptr)
                newTemp->random = m[oldTemp->random];
            else
                newTemp->random = nullptr;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
