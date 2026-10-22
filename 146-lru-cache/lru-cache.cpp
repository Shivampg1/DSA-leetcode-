class LRUCache {
public:
struct Node {
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    unordered_map<int, Node*> mp;
    int limit;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        limit=capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    void delnode(Node* newnode){
        Node* oldnod=newnode->next;
        Node* prevnod=newnode->prev;

        oldnod->prev=prevnod;
        prevnod->next=oldnod;
    }
    void addnode(Node* oldnode){
        Node* newnod=head->next;
       head->next=oldnode;
        newnod->prev=oldnode;
        oldnode->prev = head;
        oldnode->next = newnod;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* ansnode=mp[key];
        delnode(ansnode);
        addnode(ansnode);
        return ansnode->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* oldnode=mp[key];
            delnode(oldnode);
            mp.erase(key);
        }

        Node* newnode=new Node(key,value);
        addnode(newnode);
        mp[key]=newnode;
        if(mp.size()>limit){
            Node* prevnode=tail->prev;
            mp.erase(prevnode->key);
            delnode(prevnode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */