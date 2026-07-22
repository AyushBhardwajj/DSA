class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0,end = height.size()-1;

        int ans = 0;

        while(start<end){
            int curr = min(height[start],height[end])*(end-start);
            ans = max(ans,curr);
            if(height[start]==height[end]){
                start++;
                end--;
            }
            else if(height[start]<height[end]){
                start++;
            }

            else end--;
        }

        return ans;
    }
};