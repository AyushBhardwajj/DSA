class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> st;

        for(int i=0;i<arr1.size();i++){
            int num = arr1[i];
            while(num>0){
                st.insert(num);
                num = num/10;
            }
        }

        int ans = 0;

        for(int i=0;i<arr2.size();i++){
            int num = arr2[i];

            while(num>0){
                auto it = st.find(num);
                if(it!=st.end()){
                    int curr = to_string(num).length();
                    ans = max(ans,curr);
                    break;
                }

                num = num/10;
            }
        }

        return ans;
    }
};