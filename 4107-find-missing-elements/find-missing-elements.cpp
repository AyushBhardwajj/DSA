class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int mint = 100;
        int maxt = 1;

        vector<int> arr(101,0);

        for(int i=0;i<nums.size();i++){
            mint = min(mint,nums[i]);
            maxt = max(maxt,nums[i]);
            arr[nums[i]]++;
        }

        vector<int> ans;

        for(int i=mint+1;i<maxt;i++){
            if(arr[i]==0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};