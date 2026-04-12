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

private:
unordered_map<Node*, Node*> seen;

public:
    Node* cloneGraph(Node* node) 
    {
        if(!node) return nullptr;
        if(seen.contains(node)) return seen[node];

        Node* newNode = new Node(node->val);
        seen[node] = newNode;

        for(const auto& neighbor : node->neighbors)
        {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return newNode;
    }

};
