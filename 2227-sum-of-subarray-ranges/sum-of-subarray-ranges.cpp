class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st,st1;
        int n = nums.size();
        vector<int> pge(n),pse(n),nge(n),nse(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                st.pop();
            }

            while(!st1.empty() && nums[i]<=nums[st1.top()]){
                st1.pop();
            }

            int ind1 = st.empty()?-1:st.top();
            int ind2 = st1.empty()?-1:st1.top();

            pge[i] = ind1;
            pse[i] = ind2;

            st.push(i);
            st1.push(i);

        }

        while(!st.empty()){
            st.pop();
        }

        while(!st1.empty()){
            st1.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>nums[st.top()]){
                st.pop();
            }

            int ind1 = st.empty()?n:st.top();

            nge[i] = ind1;

            while(!st1.empty() && nums[i]<nums[st1.top()]){
                st1.pop();
            }

            int ind2 = st1.empty()?n:st1.top();

            nse[i] = ind2;

            st.push(i);
            st1.push(i);
        }

        long long small = 0,great = 0;

        for(int i=0;i<n;i++){
            small += 1ll*nums[i]*(nse[i]-i)*(i-pse[i]);
            great += 1ll*nums[i]*(nge[i]-i)*(i-pge[i]);
        }

        long long ans = great-small;

        return ans;



    }
};