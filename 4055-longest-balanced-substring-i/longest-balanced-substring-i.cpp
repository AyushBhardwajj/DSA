class Solution {
public:
    int longestBalanced(string s) {
        
        int n = s.length();

        int ans = 1;

        for(int i=0;i<n;i++){
            vector<int> ch(26,0);
            for(int j=i;j<n;j++){
                ch[s[j]-'a']++;

                int val = ch[s[j]-'a'];
                bool flag = true;

                for(int k=0;k<26;k++){
                    if(ch[k]==0)continue;
                    if(ch[k]!=val){
                        flag = false;
                    }
                }

                if(flag == true){
                    ans = max(ans,j-i+1);
                }
            }
        }

        return ans;
    }
};