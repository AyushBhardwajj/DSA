class Solution {
public:
    int find(vector<int> &a){
        int n = a.size();
        vector<int> vec;

        for(int i=0;i<n;i++){
            auto it = lower_bound(vec.begin(),vec.end(),a[i]);

            if(it == vec.end()){
                vec.push_back(a[i]);
            }

            else{
                int ind = it-vec.begin();
                vec[ind] = a[i];
            }
        }

        return vec.size();
    }
    int longestSubsequence(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> b;
        for(int i=0;i<30;i++){
            vector<int> tmp;
            int d = pow(2,i);
            for(auto it:a){
                if(it&d) tmp.push_back(it);
            }
            b.push_back(tmp);
        }
        int ans = 0;
        for(auto it:b){
            ans=max(ans,find(it));
        }
        return ans;
    }
};