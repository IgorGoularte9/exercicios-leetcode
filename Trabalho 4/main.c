struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) {
        return NULL;
    }

    struct ListNode* ficHead = (struct ListNode*)malloc(sizeof(struct ListNode));      
    struct ListNode* currentNode = ficHead;

    while (1) {
        int minIndex = -1;
        int minValue = 10001;

        for (int i = 0; i < listsSize; i++) {
            if (lists[i] != NULL && lists[i]->val < minValue) {
                minValue = lists[i]->val;
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            break;
        }

        currentNode->next = lists[minIndex];
        currentNode = currentNode->next;
        lists[minIndex] = lists[minIndex]->next;
    }

    currentNode->next = NULL;

    return ficHead->next;
}