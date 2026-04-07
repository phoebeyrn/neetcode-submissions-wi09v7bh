/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
public:
    Node* cloneGraph(Node* node) 
    {
        unordered_map<Node*, Node*> copies;
        return dfs(node, copies);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& copies)
    {
        if(node == nullptr)
        {
            return nullptr;
        }

        if(copies.count(node))
        {
            return copies[node];
        }

        Node* newCopy = new Node(node->val);
        copies[node] = newCopy;

        for(Node* newNode : node->neighbors)
        {
            newCopy->neighbors.push_back(dfs(newNode, copies));
        }

        return newCopy;
    }
};
