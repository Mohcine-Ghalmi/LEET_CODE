// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

void addNodeAtEnd(ListNode* &head, int value) {
    ListNode* newNode = new ListNode(value);
    
    if (head == nullptr)
        head = newNode;
    else {
        ListNode* tmp = head;
        while (tmp->next != nullptr) 
            tmp = tmp->next;
        tmp->next = newNode;
    }
}

int ListSize(ListNode* head) {
    ListNode *tmp = head;
    int size = 0;
    while (tmp) {
        tmp = tmp->next;
        size++;
    }
    return size;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *tmp = new ListNode(0);
    ListNode *holder = tmp;
    int listCounter = ListSize(head) - n;
    n = 0;

    while (head) {
        if (listCounter != n)
            addNodeAtEnd(tmp, head->val);
        head = head->next;
        n++;
    }
    holder = holder->next;
    return holder;
}
