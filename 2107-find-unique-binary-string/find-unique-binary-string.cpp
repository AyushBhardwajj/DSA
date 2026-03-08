class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        string ans = "";
        int start = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i][start]=='0')ans.push_back('1');
            else ans.push_back('0');
            start++;
        }

        return ans;
    }
};