class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> map;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void add(Node* newNode) {
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
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            map.erase(key);
            deleteNode(node);
            add(node);
            map[key] = head->next;
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* del = map[key];
            map.erase(key);
            deleteNode(del);
        }

        if (map.size() == cap) {
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        add(new Node(key, value));
        map[key] = head->next;
    }
};
