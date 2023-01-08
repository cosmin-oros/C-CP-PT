#include <iostream>
#include <vector>

/*
    You are given the head of a singly linked-list. The list can be represented as:

    L0 → L1 → … → Ln - 1 → Ln
    Reorder the list to be on the following form:

    L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    You may not modify the values in the list's nodes. Only nodes themselves may be changed.

    

    Example 1:


    Input: head = [1,2,3,4]
    Output: [1,4,2,3]
*/

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    void getNodes(ListNode* node, std::vector<ListNode*>&nodes ){
        if(node == NULL) {
            return;
        }

        nodes.push_back(node);
        getNodes(node->next,nodes);
    }

    void reorderList(ListNode* head) {
        std::vector<ListNode*> nodes;
        getNodes(head,nodes);

        int n = nodes.size();
        int i = 0;

        for(i; i < n/2; i++){
            nodes[i]->next = nodes[n-i-1];
            if((i+1) < ((n+1)/2)) {
            nodes[n-i-1]->next = nodes[i+1];
            }
        }
        nodes[i]->next = NULL;
        head = nodes[0];
    }

    /* Function to insert a node at
    the beginning of the linked list */
    void push(ListNode** head_ref, int new_data)
    {
        /* allocate node */
        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        if(!new_node){
            std::cout << "Couldn't allocate mem" << std::endl;
            exit(1);
        }
    
        /* put in the data  */
        new_node->val = new_data;
    
        /* link the old list off the new node */
        new_node->next = (*head_ref);
    
        /* move the head to point to the new node */
        (*head_ref) = new_node;
    }
 
    /* Function to print nodes in
    a given linked list */
    void printList(ListNode* node)
    {
        while (node != NULL) {
            std::cout << node->val << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;
    ListNode* head = NULL;
    s.push(&head, 4);
    s.push(&head, 3);
    s.push(&head, 2);
    s.push(&head, 1);

    s.printList(head);

    s.reorderList(head);

    s.printList(head);

    return 0;
}