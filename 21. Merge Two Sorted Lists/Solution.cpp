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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    vector<int> vec;
    ListNode* newList = new ListNode(0);

    while (list1) {
        vec.push_back(list1->val);
        list1 = list1->next;
    }

    while (list2) {
        vec.push_back(list2->val);
        list2 = list2->next;
    }
    sort(vec.begin(), vec.end());
    for (auto number : vec)
        addNodeAtEnd(newList, number);
    newList = newList->next;
    
    return newList;
}
