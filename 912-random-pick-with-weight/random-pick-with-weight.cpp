class Solution {
public:
    vector<long long> presum;
    map<int,int> mp;
    vector<int> wt;
    long long tot;
    Solution(vector<int>& w) {
        long long sum = 0;

        for(int i=0;i<w.size();i++){
            sum+=w[i];
            mp[sum] = i;
        }

        this->wt = w;

        tot = sum;
    }
    
    int pickIndex() {
        int val = rand()%tot + 1;

        auto it = mp.lower_bound(val);

        return it->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */