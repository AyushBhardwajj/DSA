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
    Node* browser;
    Node* tail;
    BrowserHistory(string homepage) {
        browser = new Node(homepage);
        tail = browser;
    }
    
    void visit(string url) {
        tail->next = new Node(url);
        tail->next->prev = tail;
        tail = tail->next;
    }
    
    string back(int steps) {
        while(steps-- && tail->prev){
            tail = tail->prev;
        }

        return tail->data;
    }
    
    string forward(int steps) {
        while(steps-- && tail->next){
            tail = tail->next;
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