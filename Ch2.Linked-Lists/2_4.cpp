/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // <X 的节点 排在 >= x的节点之前
    // 题解： 建立两个链表 一个前半段 <x 一个后半段 >=x
    // 跟例子顺序无关
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* BeforeStart = NULL;
        ListNode* BeforeEnd = NULL;
        ListNode* AfterStart = NULL;
        ListNode* AfterEnd = NULL;

        while (head != NULL) {
            ListNode* next = head -> next;
            head -> next = NULL;
            if (head -> val < x) {
                if (BeforeStart == NULL) {
                    BeforeStart = head;
                    BeforeEnd = BeforeStart;
                }
                else {
                    BeforeEnd -> next = head;
                    BeforeEnd = head;
                }
            }
            else {
                if (AfterStart == NULL) {
                    AfterStart = head;
                    AfterEnd = AfterStart;
                }
                else {
                    AfterEnd -> next = head;
                    AfterEnd = head;
                }
            }
            head = next;
        }

        // 如果beforestart为空直接返回带x的后半段
        if (BeforeStart == NULL) {
            return AfterStart;
        }
        BeforeEnd -> next = AfterStart;
        return BeforeStart;
    }
};
