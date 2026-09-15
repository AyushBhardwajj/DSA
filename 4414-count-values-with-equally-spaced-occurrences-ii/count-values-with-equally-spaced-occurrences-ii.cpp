class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int ans = 0;

        for(auto it:mp){
            bool flag = true;
            vector<int> temp = it.second;
            int siz = temp.size();

            if(siz<3)continue;

            int diff = temp[1]-temp[0];

            for(int j=1;j<siz;j++){
                if(diff != temp[j]-temp[j-1]){
                    flag = false;
                    break;
                }
            }

            if(flag)ans++;
        }

        return ans;



    }
};