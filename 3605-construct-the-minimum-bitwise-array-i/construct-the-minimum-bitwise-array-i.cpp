class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        int n = nums.size();
        
        for(int i=0;i<n;i++){

            if(nums[i]%2 == 0){
                nums[i]=-1;
                continue;
            }

            int cnt = 0;

            while(true){
                if(nums[i]&(1<<cnt)){
                    cnt++;
                    continue;
                }

                cnt--;

                nums[i] = nums[i]^(1<<cnt);
                break;
            }
            
        }

        return nums;

    }
};