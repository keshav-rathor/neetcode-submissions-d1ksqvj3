class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int i,int j)
        {
            this->key=i;
            this->val=j;
        }

    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> map;
    int cap;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;

    }

    void add(Node* new_node)
    {
        Node* temp=head->next;
        new_node->next=temp;
        new_node->prev=head;
        head->next=new_node;
        temp->prev=new_node;
    }
    void delete_node(Node* delnode)
    {
        Node* next=delnode->next;
        Node* pv=delnode->prev;
        next->prev=pv;
        pv->next=next;
    }


    
    int get(int key) {
        if(map.find(key)!=map.end())
        {
            Node* node=map[key];
            map.erase(key);
            delete_node(node);
            add(node);
            map[key]=head->next;
            return node->val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end())
        {
            Node* node=map[key];
            map.erase(key);
            delete_node(node);
        }
        if(map.size()==cap)
        {
            map.erase(tail->prev->key);
            delete_node(tail->prev);

        }
        add(new Node(key,value));
        map[key]=head->next;
    }
};
