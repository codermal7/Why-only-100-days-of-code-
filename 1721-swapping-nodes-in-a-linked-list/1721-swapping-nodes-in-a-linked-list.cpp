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
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode base;
    base.next = head;
    ListNode* a = &base;
    while (k > 1) {
      --k;
      a = a->next;
    }  // Now a is the parent of the kth node.

    ListNode* b = &base;
    ListNode* end = a->next->next;
    while (end != nullptr) {
      b = b->next;
      end = end->next;
    }  // Now b is the parent of the -kth node.
    if (a != b) {
      swap(a->next, b->next);
      swap(a->next->next, b->next->next);
    }
    return base.next;
  }
};