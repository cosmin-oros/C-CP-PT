#include <iostream>

/*
    Given head, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
    Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

    Return true if there is a cycle in the linked list. Otherwise, return false.

    

    Example 1:


    Input: head = [3,2,0,-4], pos = 1
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
*/

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) {
            return false;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow) {
                return true;
            }
        }
        
        return false;
    }

    void printList(ListNode* head) {
    while (head != NULL) {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
}
};

int main() {
    Solution s;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    s.printList(head);

    std::cout << s.hasCycle(head) << std::endl;

    return 0;
}