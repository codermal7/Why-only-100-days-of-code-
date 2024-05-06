class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextTemp = nullptr;
        while (current != nullptr) {
            nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }
        
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        int maximum = 0;
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            maximum = max(maximum, current->val);
            if (current->val < maximum) {
                prev->next = current->next;
                ListNode* deleted = current;
                current = current->next;
                deleted->next = nullptr;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
        return reverseList(head);
    }
};