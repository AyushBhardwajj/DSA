class Solution {
public:
    int countStaircase(vector<int>& nums) {
        vector<vector<int>> freq(1e5+1);
        int n = nums.size();

        for(int i=0;i<n;i++){
            freq[nums[i]].push_back(i);
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            int mint = n-1;
            int crr = i;
            set<int> st;

            for(int j=i;j<n;j++){
                if(crr == j){
                    ans++;
                    //cout<<i<<" "<<j<<"\n";
                    if(j<n-1){
                        if(!st.count(nums[j+1]))mint = n-1;
                    }
                }
                if(!st.count(nums[j])){
                    int siz = st.size();
                    int need = siz+1;
                    st.insert(nums[j]);
                    int ind = lower_bound(freq[nums[j]].begin(),freq[nums[j]].end(),j)-freq[nums[j]].begin();
                    int needind = ind+need-1;
                    int siz2 = freq[nums[j]].size();
                    if(needind>=siz2 || freq[nums[j]][needind]>mint)break;
                    crr = max(crr,freq[nums[j]][needind]);
                    int needind2 = ind+need;
                    if(needind2<siz2){
                        mint = min(mint,freq[nums[j]][needind2]-1);
                    }
                }
            }
        }

        return ans;
    }
};