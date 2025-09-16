class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); 
        ListNode* current = &dummy; 
        int carry = 0; 

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next; 
            }
            if (l2) {
                sum += l2->val; // Add digit from l2
                l2 = l2->next; // Move to next node
            }
            carry = sum / 10; // Calculate new carry
            current->next = new ListNode(sum % 10); // Create node for current digit
            current = current->next; // Move to next position
        }

        return dummy.next; // Return the result list
    }
};
