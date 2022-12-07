#include <iostream>
#include <unordered_map>

class RandomListNode {
public:
    int val;
    RandomListNode* next;
    RandomListNode* random;
    
    RandomListNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    std::unordered_map<RandomListNode*, RandomListNode*>mp;
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if(!head) {
            return NULL;
        }

        if(mp[head]!=NULL) {
            return mp[head];
        }

        mp[head] = new RandomListNode(head->val);
        mp[head] -> next = copyRandomList(head->next);
        mp[head] -> random = copyRandomList(head->random);

        return mp[head];
    }
};

int main() {
    RandomListNode* L;
    

    return 0;
}