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
    ListNode* reverseList(ListNode* head) {
        ListNode* previousNode = head;
        if (previousNode == nullptr){
            return head;
        }
        ListNode* currentNode = head->next;
        if (currentNode == nullptr){
            return head;
        }
        ListNode* nextNode = currentNode->next;
        head->next = nullptr;
        while (nextNode != nullptr){
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
        currentNode->next = previousNode;
        return currentNode;

    }
};
