/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* current = head;
        while (current != NULL) {
            ListNode* runner = current; 
            while (runner->next != NULL) {
                if (current -> val == runner -> next -> val) {
                    if (runner -> next -> next != NULL) {
                        runner -> next = runner -> next -> next;    
                    }
                    else {
                        runner -> next = NULL;
                    }
                    
                }
                else {
                    runner = runner -> next;
                }
            }
            current = current -> next;
        }  
        return head;
    }
};
// 快行指针：同时用两个指针迭代访问链表 runner跑的快（查重）
// 空间复杂度O(1) 时间复杂度O(N^2)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* current = head;
        if (!head) return NULL;
        unordered_map<int,int> mp;
        mp[current->val]++;
        while(current != NULL){
            while (current->next && mp[current->next->val] != 0) {
                current->next = current->next->next;
            }
			// 如果下一个非空 将下一个元素累计加1
            if (current->next) mp[current->next->val]++;
            current = current -> next;
        }
        return head;
    }
};
// hash map 散列表记录 然后删除已有元素
// 时间复杂度 O(N)
