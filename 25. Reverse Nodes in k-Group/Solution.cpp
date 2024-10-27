//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prevGroupEnd = dummy;

    ListNode* current = head;
    int count = 0;
    while (current) {
        count++;
        current = current->next;
    }

    while (count >= k) {
        ListNode* groupStart = prevGroupEnd->next;
        current = groupStart;
        ListNode* prev = nullptr;
        
        for (int i = 0; i < k; ++i) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        
        prevGroupEnd->next = prev;
        groupStart->next = current;

        prevGroupEnd = groupStart;
        count -= k;
    }

    return dummy->next;
}