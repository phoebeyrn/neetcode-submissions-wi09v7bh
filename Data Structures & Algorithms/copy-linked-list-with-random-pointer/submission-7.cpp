/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node * it = head;
        unordered_map<Node*, Node*> copies;
        
        //for pass 1
        while(it)
        {
            Node * newNode = new Node(it->val);
            copies[it] = newNode;
            it = it->next;
        }

        it = head;
        while(it)
        {
            Node * copy = copies[it];
            copy->next = copies[it->next];
            copy->random = copies[it->random];
            it = it->next;
        }

        return copies[head];

    }
};
