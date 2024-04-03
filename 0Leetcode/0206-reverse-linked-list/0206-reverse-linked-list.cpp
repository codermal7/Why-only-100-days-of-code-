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
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* nextNode;
//         ListNode* prevNode=NULL;
//         while(head){
//             nextNode=head->next;
//             head->next=prevNode;
//             prevNode=head;
//             head=nextNode;
//         }
//         return prevNode;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;        
        }
        return prev;
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL) return head;
//         ListNode* prev = NULL;
//         ListNode* h2 = reverseList(head->next);
//         head->next->next = head;
//         head->next=prev;
//         return h2;
//     }
// };