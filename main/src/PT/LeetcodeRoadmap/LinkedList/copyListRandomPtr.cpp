#include <iostream>
#include <unordered_map>

/*
    A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

    Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its 
    corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in
    the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

    For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

    Return the head of the copied linked list.

    The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
    Your code will only be given the head of the original linked list.

    

    Example 1:


    Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode *head) {

        RandomListNode* dummy = new RandomListNode(-1);

        RandomListNode* copy_current = dummy;

        std::unordered_map<RandomListNode*, RandomListNode*> links;


        for (auto current = head; current != nullptr; current = current->next) {

            links[current] = new RandomListNode(current->label);

            copy_current->next = links[current];
            copy_current = copy_current->next;
        }
        
        copy_current = dummy->next;

        for (auto current = head; current != nullptr; current = current->next) {

            if (current->random != nullptr) {
                copy_current->random = links[current->random];
            }
            
            copy_current = copy_current->next;
        }
				
        return dummy->next;        
    }
};

void printList(RandomListNode* head) {
    while (head != NULL) {
            std::cout << head->label << " ";
            head = head->next;
        }
        std::cout << std::endl;
}

int main() {
    Solution s;
    RandomListNode* head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    
    RandomListNode* copy = s.copyRandomList(head);

    printList(copy);

    return 0;
}