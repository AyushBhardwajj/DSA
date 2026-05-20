class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> arr1,arr2;

        vector<int> ans;

        for(int i=0;i<A.size();i++){
            arr1.push_back(A[i]);
            arr2.push_back(B[i]);

            sort(arr1.begin(),arr1.end());
            sort(arr2.begin(),arr2.end());

            int k =0,j = 0;
            int cnt = 0;

            while(k<=i && j<=i){
                if(arr1[k] == arr2[j]){
                    cnt++;
                    k++;j++;
                }
                else if(arr1[k]>arr2[j]){
                    j++;
                }
                else k++;
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};