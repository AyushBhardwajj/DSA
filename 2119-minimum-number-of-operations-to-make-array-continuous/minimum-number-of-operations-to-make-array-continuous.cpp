class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> stt;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int start = 0;
        int maxt = 1;

        for(int i=0;i<nums.size();i++){
            
            stt.insert(nums[i]);

            int frst = *stt.begin();
            int end = *stt.rbegin();

            while(abs(end-frst)>=n){
                auto it = stt.find(frst);
                stt.erase(it);

                frst = *stt.begin();
            }

            int curr = stt.size();

            maxt = max(maxt,curr);
        }

        int ans = n-maxt;

        return ans;
    }
};