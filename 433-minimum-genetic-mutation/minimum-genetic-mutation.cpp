class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();

        queue<string> q;
        q.push(startGene);

        set<string> st;

        for(int i=0;i<bank.size();i++){
            st.insert(bank[i]);
        }

        int cnt = 0;

        vector<char> chh = {'A','C','G','T'};

        while(!q.empty()){

            int siz = q.size();

            for(int i=0;i<siz;i++){
                string curr = q.front();
                if(curr == endGene)return cnt;
                q.pop();

                for(int j=0;j<curr.length();j++){
                    string trav = curr;
                    for(int k=0;k<4;k++){
                        trav[j] = chh[k];

                        if(st.find(trav)!=st.end()){
                            q.push(trav);
                            st.erase(trav);
                        }
                    }
                }
            }

            cnt++;

        }

        return -1;
    }
};