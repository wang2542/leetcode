/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	// 递归解法
	// 添加carry进位数 然后添加进位为下一次递归的初始数
	// 将余数设置为当前节点值 然后将递归指向下一个节点
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }
    ListNode* helper(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == NULL && l2 == NULL && carry == 0)
            return NULL;
        int value = carry;
        if (l1 != NULL) {
            value += l1 -> val;
        }
        if (l2 != NULL) {
            value += l2 -> val;
        }
        ListNode* resultNode = new ListNode( value % 10 );
        resultNode->next = helper( l1 ? (l1->next) : NULL,
                                    l2 ? (l2->next) : NULL,
                                    value >= 10 ? 1 : 0 );  
        return resultNode;
    } 
};

