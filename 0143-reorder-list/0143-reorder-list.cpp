class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        vector<int> values;

        ListNode* temp = head;

        // Store all values
        while (temp != NULL) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        int j = values.size() - 1;

        temp = head;

        // Change only node values
        while (i <= j) {
            if (i == j) {
                temp->val = values[i];
                break;
            }

            temp->val = values[i];
            temp = temp->next;

            temp->val = values[j];
            temp = temp->next;

            i++;
            j--;
        }
    }
};