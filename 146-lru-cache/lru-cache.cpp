class Node{
public:
    int key,value;
    Node* next;
    Node* prev;

    Node(int key,int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
public:
    int cap;
    int tot;
    unordered_map<int,Node*> lru;
    unordered_map<int,int> keyvalue;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        this->cap = capacity;
        this->tot = 0;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(keyvalue.find(key)!=keyvalue.end()){
            Node* temp = lru[key];
            Node* prevNode = temp->prev;
            Node* nxtNode = temp->next;
            prevNode->next = nxtNode;
            nxtNode->prev = prevNode;

            Node* tailprev = tail->prev;
            tailprev->next = temp;
            tail->prev = temp;
            temp->prev = tailprev;
            temp->next = tail;
            
            return keyvalue[key];

        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyvalue.find(key)!=keyvalue.end()){
            keyvalue[key] = value;
            Node* temp = lru[key];
            temp->value = value;
            Node* prevNode = temp->prev;
            Node* nxtNode = temp->next;
            prevNode->next = nxtNode;
            nxtNode->prev = prevNode;

            Node* tailprev = tail->prev;
            tailprev->next = temp;
            tail->prev = temp;
            temp->prev = tailprev;
            temp->next = tail;
        }
        else{
            if(tot == cap){
                Node* headnext = head->next;
                headnext->next->prev = headnext->prev;
                head->next = headnext->next;
                tot--;
                int k = headnext->key;
                keyvalue.erase(k);
            }
            Node *temp = new Node(key,value);
            lru[key] = temp;
            keyvalue[key] = value;

            Node* tailprev = tail->prev;
            tailprev->next = temp;
            tail->prev = temp;
            temp->prev = tailprev;
            temp->next = tail;
            tot++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */