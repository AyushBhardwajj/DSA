class Solution {
public:
    int isPresent(string &s,int mid){
        unordered_map<long long,vector<int>> st;
        int n = s.length();

        long long hash = 0;
        long long base = 1;
        long long mod = 1e9+7;

        for(int i=0;i<mid;i++){
            hash = ((hash*31)%mod + (s[i]-'a'+1))%mod;
            if(i<mid-1) base = (base*31)%mod;
        }

        st[hash].push_back(0);

        for(int i=mid;i<n;i++){
            hash = (hash - (base*(s[i-mid]-'a'+1))%mod + mod)%mod;
            hash = ((hash*31)%mod + (s[i]-'a'+1))%mod;
            int startIdx = i-mid+1;
            
            if(st.count(hash)){
                for(int prev:st[hash]){
                    if(s.compare(prev,mid,s,startIdx,mid)==0)return startIdx;
                }
            }

            st[hash].push_back(startIdx);
        }

        return -1;

    }
    string longestDupSubstring(string s) {
        long long mod = 1e9+7;
        int n = s.length();

        int start = 1,end = n-1;
        int ind = -1;
        int len = 0;
        string ans = "";

        while(start<=end){
            int mid = start +(end-start)/2;
            int ind = isPresent(s,mid);

            if(ind!=-1){
                ans = s.substr(ind,mid);
                start = mid+1;
            }
            else{
                end = mid-1;
            }

        } 

        return ans;
    }
};