/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
    // 解题思路：
    // 1. 查长度和尾部 如果尾部不同直接返回
    // 2. 如果尾部相同 计算两组长度差值 较长的1组 跳过差值
    // 3. 遍历比较 发现节点立刻返回
    struct ResultType {
        int length;
        int tail;
    };
public:
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ResultType* result1 = getTailandSize(headA);
        ResultType* result2 = getTailandSize(headB);

        if (result1->tail != result2->tail) {
            return NULL;
        }
        // 比较谁更长 把指针设置到头部
        ListNode* longer = result1->length > result2->length ? headA : headB; 
        ListNode* shorter = result1->length > result2->length ? headB : headA;
        // 跳过n个节点
        longer = SkipNode(longer, abs(result1->length - result2->length));

        while (longer != shorter) {
            shorter = shorter -> next;
            longer = longer -> next;
        }
        return longer;
    }
    ListNode* SkipNode(ListNode* head, int n) {
        ListNode* current = head;
        for (int i = 0; i < n; i++) {
            current = current -> next;
        }
        return current;
    }
    ResultType* getTailandSize(ListNode* head) {
        if (head == NULL) return NULL;
        ResultType* tmp = new ResultType();
        int size = 1;
        while (head -> next != NULL) {
            size++;
            head = head -> next;
        }
        tmp->length = size;
        tmp->tail = head -> val;
        return tmp;
    }
};
