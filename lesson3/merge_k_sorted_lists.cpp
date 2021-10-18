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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return doMerge(lists, 0 ,lists.size() -1);
    }

    ListNode* doMerge(vector <ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        //分成兩份
        int mid =  (l+r) >> 1;
        return merge2Lists(doMerge(lists, l , mid),doMerge(lists, mid+ 1, r) );
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        } else {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }
};