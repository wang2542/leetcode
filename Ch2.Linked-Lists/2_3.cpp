i/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // 题解跳过当前节点
public:
    void deleteNode(ListNode* node) {
        // 中间点的下一个
        ListNode* next = node -> next;
        // 把下一个数值 链接到当前的点
        node -> val = next -> val;
        // 把下一个的下一个点 设置成 当前点的下一个
        node->next = next->next;
    }
};
