

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
    // IMPORTANT in case of linked list we have to keep comp like this
    struct comp {
        bool operator()( ListNode* l1, ListNode* l2 ) {
            return l1->val > l2->val;
        }  
    };
   ListNode *mergeKLists(vector<ListNode *> &lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, comp > heap;
    ListNode head(0);
    ListNode *curNode = &head;
    int i, k, n = lists.size();
    for (i = 0; i < n; i++)
        if (lists[i]) heap.push(lists[i]);
    while (!heap.empty()){
        curNode->next = heap.top();
        heap.pop();
        curNode = curNode->next;
        if (curNode->next) heap.push(curNode->next);
    }
    return head.next;
}
};
