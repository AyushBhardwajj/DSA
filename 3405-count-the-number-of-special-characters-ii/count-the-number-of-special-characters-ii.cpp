class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> low(26,2e9),up(26,1e9);

        int n = word.length();

        for(int i =0 ;i<n;i++){
            if(word[i]>=65 && word[i]<=90){
                if(up[word[i]-'A'] == 1e9)up[word[i]-'A'] = i;
            }

            else{
                low[word[i]-'a'] = i;
            }
        }

        int ans = 0;

        for(int i=0;i<26;i++){
            if(up[i]>low[i] && up[i]!=1e9)ans++;
        }

        return ans;
    }
};