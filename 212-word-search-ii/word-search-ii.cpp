vector<string> ans;
int n,m;
class TrieNode{
public:
    bool end;
    string word;
    TrieNode* children[26];
};

TrieNode* getNode(){
    TrieNode* newNode = new TrieNode();
    newNode->end = false;

    newNode->word = "";

    for(int i=0;i<26;i++){
        newNode->children[i] = NULL;
    }

    return newNode;
}

void insert(TrieNode* root,string& word){
    TrieNode* crawler = root;

    for(int i=0;i<word.length();i++){
        char ch = word[i];

        if(crawler->children[ch-'a']==NULL){
            crawler->children[ch-'a'] = getNode();
        }

        crawler = crawler->children[ch-'a'];
        
    }

    crawler->end = true;
    crawler->word = word;
}

vector<int> dr = {-1,0,1,0};
vector<int> dc = {0,-1,0,1};

void findwords(vector<vector<char>> &board,int i,int j,TrieNode* root){
    if(i<0 || i>=n || j<0 || j>=m)return;
    if(board[i][j]=='$' || root->children[board[i][j]-'a'] == NULL)return;

    root = root->children[board[i][j]-'a'];

    if(root->end == true){
        ans.push_back(root->word);
        root->end = false;
    }

    char temp = board[i][j];
    board[i][j] = '$';

    for(int k=0;k<4;k++){
        findwords(board,i+dr[k],j+dc[k],root);
    }

    board[i][j] = temp;

}

class Solution {
public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        n = board.size();
        m = board[0].size();
        ans.clear();

        TrieNode* root = getNode();

        for(auto str:words){
            insert(root,str);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                char ch = board[i][j];
                if(root->children[ch-'a']!=NULL){
                    findwords(board,i,j,root);
                }


            }
        }

        return ans;
        
    }
};