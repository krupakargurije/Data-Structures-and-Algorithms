class LRUCache {
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v){
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> m;
    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);

public:
    LRUCache(int capacity) : cap(capacity) {
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int res = resNode->value;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* ex = m[key];
            m.erase(key);
            deleteNode(ex);
        }
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};