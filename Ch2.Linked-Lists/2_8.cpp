/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // 解题思路： 双行指针（slower = p, faster = 2p）两倍速前进
    // 1. slower faster 两倍速前进直到相遇 如果没相遇返回 -1
    // 2. 如果相遇了把其中一个指针扔到开始处 （此时两个指针距离环链起始点距离相同）
    //    调整两个指针速度为p 当他们相遇时返回 该点val
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slower = head;
        ListNode* faster = head;

        while (faster != NULL && faster -> next != NULL) {
            slower = slower -> next;
            faster = faster -> next -> next;
            if (slower == faster) {
                break;
            }
        }
        if (faster == NULL || faster -> next == NULL) {
            return NULL;
        }
        slower = head;
        while (slower != faster) {
            slower = slower -> next;
            faster = faster -> next;
        }

        return faster;
    }
};
