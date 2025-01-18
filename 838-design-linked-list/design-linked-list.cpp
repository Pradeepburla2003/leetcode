class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* head = new ListNode(); // Dummy head node
    ListNode* temp = head;

    MyLinkedList() {}

    int get(int index) {
        ListNode* curr = head->next; // Start from the first actual node
        while (index > 0 && curr) {
            curr = curr->next;
            index--;
        }
        if (!curr) return -1;
        return curr->val;
    }

    void addAtHead(int val) {
        head->next = new ListNode(val, head->next);
    }

    void addAtTail(int val) {
        ListNode* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new ListNode(val);
    }

    void addAtIndex(int index, int val) {
        ListNode* curr = head;
        while (index > 0 && curr) {
            curr = curr->next;
            index--;
        }
        if (!curr) return; // Index out of bounds
        curr->next = new ListNode(val, curr->next);
    }

    void deleteAtIndex(int index) {
        ListNode* curr = head;
        while (index > 0 && curr->next) {
            curr = curr->next;
            index--;
        }
        if (!curr->next) return; // Index out of bounds
        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
    }
};
