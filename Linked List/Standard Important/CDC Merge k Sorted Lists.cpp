

https://leetcode.com/problems/merge-k-sorted-lists/

23. Merge k Sorted Lists
Hard

7111

357

Add to List

Share
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
  
  
  














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
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
        
//     }
// };




class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        if(!a && !b) return NULL;
        if (a && !b) return a;
        if (!a && b) return b;
        
        ListNode* ans = NULL;
        if(a->val < b->val) {
            ans = a;
            a = a->next;
        } else {
            ans = b;
            b = b->next;
        }
        
        ListNode* m = ans;
        while(a && b) {
            if(a->val < b->val) {
                m->next = a;
                a = a->next;
            } else{
                m->next = b;
                b = b->next;
            }
            m = m->next;
        }
        
        if (a) {
            m->next = a;
        } 
        if (b) {
            m->next = b;
        }
        
        return ans;
    }
    
    
    ListNode* mergeK(vector<ListNode*>& lists, int l, int r) {
        if (l==r) return lists[l];
        
        int mid = l + (r-l)/2;
        ListNode* a = mergeK(lists, l, mid);
        ListNode* b = mergeK(lists, mid+1, r);
        
        return merge(a, b);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n==0) return NULL;
        if (n==1) return lists[0];
        
        return mergeK(lists, 0, n-1);
    }
};



class Solution {
public:
    struct comp {
        bool operator()( ListNode* l1, ListNode* l2 ) {
            return l1->val > l2->val;
        }  
    };
    
    ListNode* mergeKLists( vector<ListNode*>& lists ) {
        if( lists.size() == 0 ) return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, comp> minHeap;
        for( auto list : lists ) {
            if( list != nullptr )  minHeap.push( list );
        }
        
          ListNode dummy(-1); // dummy node
        ListNode* curr = &dummy;
        while( !minHeap.empty() ) {
            curr->next = minHeap.top();
            minHeap.pop();
            curr = curr->next;
            if( curr->next ) {
                 // means this link list has more elements
                minHeap.push( curr->next );
            }
        }
        return dummy.next;
    }
};
