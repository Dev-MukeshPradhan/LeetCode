class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        int len = 0;
        ListNode* s = head;   // Will point to kth node from the beginning
        ListNode* f = head;

        // Move s to the kth node from the beginning
        for (int i = 1; i < k; i++) {
            s = s->next;
        }

        // Find the length of the linked list
        while (f != NULL) {
            len++;
            f = f->next;
        }

        // Position of kth node from the end (counting from the beginning)
        int pos = len - k + 1;

        // Reset f to the head
        f = head;

        // Move f to the kth node from the end
        for (int i = 1; i < pos; i++) {
            f = f->next;
        }

        // Swap the values of the two nodes
        swap(s->val, f->val);

        return head;
    }
};