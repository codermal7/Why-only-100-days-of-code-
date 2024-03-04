/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode partition(ListNode head, int x) {
        if (head == null) {
            return null;
        }
        ListNode smallHead = new ListNode(-1), bigHead = new ListNode(-1), iterator = head;
        ListNode smallIterator = smallHead, bigIterator = bigHead;
        while (iterator != null) {
            if (iterator.val < x) {
                smallIterator.next = new ListNode(iterator.val);
                smallIterator = smallIterator.next;
            }
            else {
                bigIterator.next = new ListNode(iterator.val);
                bigIterator = bigIterator.next;
            }
            iterator = iterator.next;
        }
        smallIterator.next = bigHead.next;
        return smallHead.next;
    }
}