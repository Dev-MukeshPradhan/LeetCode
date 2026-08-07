class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (tempA != NULL) {
            lenA++;
            tempA = tempA->next;
        }
        while (tempB != NULL) {
            lenB++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;

        if (lenB > lenA) {
            int lenD = lenB - lenA;
            for (int i = 1; i < lenD + 1; i++) {
                tempB = tempB->next;
            }
            while (tempB != NULL) {
                if (tempA == tempB) {
                    return tempA;
                }
                tempA=tempA->next;
                tempB=tempB->next;
            }

        } else {
            int lenD = lenA - lenB;
            for (int i = 1; i < lenD + 1; i++) {
                tempA = tempA->next;
            }
            while (tempA != NULL) {
                if (tempA == tempB) {
                    return tempA;
                }
                tempA=tempA->next;
                tempB=tempB->next;
            }
        }

        return NULL;
    }
};