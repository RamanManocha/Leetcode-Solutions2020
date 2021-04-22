


https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/


1836. Remove Duplicates From an Unsorted Linked List
Medium

8

0

Add to List

Share
Given the head of a linked list, find all the values that appear more than once in the list and delete the nodes that have any of those values.

Return the linked list after the deletions.

 

Example 1:


Input: head = [1,2,3,2]
Output: [1,3]
Explanation: 2 appears twice in the linked list, so all 2's should be deleted. After deleting all 2's, we are left with [1,3].
Example 2:


Input: head = [2,1,1,2]
Output: []
Explanation: 2 and 1 both appear twice. All the elements should be deleted.
Example 3:


Input: head = [3,2,2,1,3,2,4]
Output: [1,4]
Explanation: 3 appears twice and 2 appears three times. After deleting all 3's and 2's, we are left with [1,4].
 

Constraints:

The number of nodes in the list is in the range [1, 105]
1 <= Node.val <= 105








class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> m;
        for (ListNode* curr = head; curr; curr = curr->next)
            m[curr->val]++;
        
        ListNode* res_head = new ListNode(-1, head);
        ListNode* prev = res_head;
        ListNode* curr = res_head->next;
        
        while (curr) {
            if (m[curr->val] != 1){
                prev->next = curr->next;
                curr = prev->next;
            }
            else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return res_head->next;
    }
};
