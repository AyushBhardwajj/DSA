class Node{
public:
    vector<Node*> vec;
    bool end;

    Node(){
        vec.resize(26,NULL);
        end = false;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* trav = root;
        for(int i=0;i<word.length();i++){
            int val = word[i]-'a';
            if(trav->vec[val] == NULL){
                trav->vec[val] = new Node();
            }

            trav = trav->vec[val];
        }
        trav->end = true;
    }
    
    bool search(string word) {
        Node* trav = root;

        for(int i=0;i<word.length();i++){
            int val = word[i]-'a';
            if(trav->vec[val] == NULL)return false;
            trav = trav->vec[val];
        }
        if(trav->end)return true;
        return false;
    }
    
    bool startsWith(string word) {
        Node* trav = root;

        for(int i=0;i<word.length();i++){
            int val = word[i]-'a';
            if(trav->vec[val] == NULL)return false;
            trav = trav->vec[val];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */