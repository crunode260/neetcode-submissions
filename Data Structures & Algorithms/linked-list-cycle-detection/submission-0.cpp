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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> prevNodes;
        ListNode* currentNode = head;
        int i = 0;
        while (currentNode){
            if (prevNodes.count(currentNode) == 1){
            return true;
            }
            prevNodes[currentNode] = i;
            i++;
            currentNode = currentNode->next;
        }
        return false;

    }
};
