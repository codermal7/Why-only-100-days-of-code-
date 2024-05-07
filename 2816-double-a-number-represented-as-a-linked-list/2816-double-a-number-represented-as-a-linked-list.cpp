/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode* > stk;
        ListNode* tmp = head;
        
        while (tmp)
        {
            stk.push(tmp);
            tmp = tmp->next;
        }

        int carry = 0;
        while (!stk.empty())
        {
            ListNode* curr = stk.top();
            stk.pop();
            
            int sum = curr->val * 2 + carry;
            curr->val = sum % 10;
            carry = sum / 10;
        }

        if (carry != 0)
        {
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};