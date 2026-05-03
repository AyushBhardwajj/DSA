class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        vector<long long> pre(n,0),post(n,0);

        for(int i=1;i<n;i++){
            if(i==1){
                pre[i]=1;
            }
            else{
                int left = abs(nums[i-2]-nums[i-1]);
                int right = abs(nums[i-1]-nums[i]);

                if(left<=right){
                    pre[i] = pre[i-1]+right;
                }else{
                    pre[i] = pre[i-1]+1;
                }
            }
        }

        for(int i=n-2;i>=0;i--){
            if(i==n-2){
                post[i]=1;
            }
            else{
                int left = abs(nums[i+2]-nums[i+1]);
                int right = abs(nums[i+1]-nums[i]);

                if(left<right){
                    post[i] = post[i+1]+right;
                }else{
                    post[i] = post[i+1]+1;
                }
            }
        }

        vector<int> ans;

        for(int i=0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];

            if(l<r){
                int curr = pre[r]-pre[l];
                ans.push_back(curr);
            }else{
                int curr = post[r]-post[l];
                ans.push_back(curr);
            }
        }

        return ans;


    }
};