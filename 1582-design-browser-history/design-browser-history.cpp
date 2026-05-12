class Node{
public:
    Node* next;
    Node* prev;
    string data;

    Node(string data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class BrowserHistory {
public:
    Node* start;
    Node* tail;
    BrowserHistory(string homepage) {
        start = new Node(homepage);
        tail = start;
    }
    
    void visit(string url) {
        Node* temp = new Node(url);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
    string back(int steps) {
        while(steps>0 && tail->prev!=nullptr){
            tail = tail->prev;
            steps--;
        }

        return tail->data;
    }
    
    string forward(int steps) {
        while(steps>0 && tail->next!=nullptr){
            tail = tail->next;
            steps--;
        }
        return tail->data;

    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */