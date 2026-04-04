class Node
{

public:
Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}

int value;
int key;
Node * prev;
Node * next;

};

class LRUCache 
{

private:
    int cap = 0;
    Node * left;
    Node * right;
    unordered_map<int, Node*> member;

    void remove(Node* node)
    {
        Node* temp1 = node->prev;
        Node* temp2 = node->next;

        temp1->next = temp2;
        temp2->prev = temp1;
    }

    void insert(Node* node)
    {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) 
    {
        this->cap = capacity;
        member.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) 
    {
        if(member.find(key) != member.end())
        {
            Node * node = member[key];
            remove(node);
            insert(node);
            return node->value;
        }

        return -1;
    }
    
    void put(int key, int value) 
    {
        if(member.find(key) != member.end())
        {
            remove(member[key]);
        }

        Node* newNode = new Node(key, value);
        member[key] = newNode;
        insert(newNode);

        if(member.size() > cap)
        {
            Node* lru = left->next;
            remove(lru);
            member.erase(lru->key);
            delete lru;
        }

    }

};
