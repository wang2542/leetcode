//链表-反转
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // 解题思路:  1.改变指针方向，从而实现反转方向
    //           2. 检查改变后是否相等
    // https://blog.csdn.net/ekaake/article/details/79938245
public:
    bool isPalindrome(ListNode* head) {
        ListNode* result = reversed(head);
        cout << "-----------" << endl;
        return isEqual(head, result);
    }
    ListNode* reversed(ListNode* node) {
        // 反转链表指针头（游标） 讲指针方向改变了
        ListNode* head = NULL;
        while (node != NULL) {
            ListNode* n = new ListNode(node -> val);
            n -> next = head;
            head = n;
            node = node -> next;
        }
        return head;
    }
    bool isEqual(ListNode* one, ListNode* two) {
        while (one != NULL && two != NULL) {
            if (one -> val != two -> val) {
                return false;
            }
            one = one -> next;
            two = two -> next;
        }
        return one == NULL && two == NULL;
    }
};
//-------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //解题思路：双行指针
    //慢指针推入栈堆 快指针两倍速到最后 
    //开始pop栈堆 然后比较剩余链表
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slower = head;
        ListNode* faster = head;
        
        stack<int> tank;
        while (faster != NULL && faster -> next != NULL) {
            tank.push(slower -> val);
            slower = slower -> next;
            faster = faster -> next -> next;
        }
        // 奇数时跳过中间节点
        if (faster != NULL) {
            slower = slower -> next;
        }
        while (slower != NULL) {
            int top = tank.top();
            if (top != slower -> val) {
                return false;
            }
            tank.pop();
            slower = slower -> next;
        }
        return true;
    }
};
