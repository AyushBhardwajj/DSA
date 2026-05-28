class Solution {
public:
    long long binpower(long long base,long long pow,long long mod){
        long long ans = 1;

        while(pow>0){
            if(pow&1){
                ans = (ans*base)%mod;
            }
            base = (base*base)%mod;

            pow = pow>>1;
        }

        return ans;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        
        unordered_map<long long,set<pair<int,int>>> mp;

        long long mod = 1e9+7;
        int mint = 1e4;
        int ind = -1;

        for(int i=0;i<wordsContainer.size();i++){
            long long count = 0;
            int len = wordsContainer[i].length();
            if(len<mint){
                mint = len;
                ind = i;
            }
            for(int j=len-1;j>=0;j--){
                count = (count*27 + (int)(wordsContainer[i][j]-'a'+1)%mod)%mod;
                mp[count].insert({len,i});
                if(mp[count].size()>1){
                    mp[count].erase(prev(mp[count].end()));
                }
            }
        }

        vector<int> ans;

        for(int i=0;i<wordsQuery.size();i++){
            long long count = 0;
            int len = wordsQuery[i].length();
            int crr = ind;
            for(int j=len-1;j>=0;j--){
                count = (count*27 + (int)(wordsQuery[i][j]-'a'+1)%mod)%mod;
                if(mp.count(count)){
                    auto it = mp[count].begin();
                    crr = it->second;
                }
                else break;
            }
            ans.push_back(crr);
        }

        return ans;
    }
};