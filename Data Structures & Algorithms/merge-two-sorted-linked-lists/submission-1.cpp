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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* currentNode1 = list1;
        ListNode* currentNode2 = list2;
        if (currentNode1 == nullptr){
            return currentNode2;
        }
        if (currentNode2 == nullptr){
            return currentNode1;
        }
        if (currentNode1->val < currentNode2->val){
            ListNode* nextNode1 = currentNode1->next;
            currentNode1->next = mergeTwoLists(nextNode1, currentNode2);
            return currentNode1;
        }
        else{
            ListNode* nextNode2 = currentNode2->next;
            currentNode2->next = mergeTwoLists(currentNode1, nextNode2);
            return currentNode2;
        }

    }
};
