/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // 题解： 可以用递归直接倒数计数 返回该节点的数值
public:
    int result = 0;
    int kthToLast(ListNode* head, int k) {
        getResult(head, k);
        return result;
    }
    int getResult(ListNode* head, int k) {
        if (head == NULL) {
            return 0;
        }
        int index = getResult(head -> next, k) + 1;
        if (index == k) {
            result = head -> val;
        }
        return index;
    }
};
//----------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // 题解： 建立一个快行指针p2 先跑k个数 然后平排跑 p2跑到最后一个的时候 p1->val就是返回值
public:
    int result = 0;
    int kthToLast(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* p2 = head;

        for (int i = 0; i < k; i++) {
            p2 = p2 -> next;
        }

        while (p2 != NULL) {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return p1 -> val;
    }
};
