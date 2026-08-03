class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();

        vector<int> pref(n,-1),suff(n,n);

        long long ans = 0;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            int ind = st.empty()?-1:st.top();

            pref[i] = ind;

            st.push(i);
        }

        stack<int> st2;

        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && arr[st2.top()]>arr[i]){
                st2.pop();
            }

            int ind = st2.empty()?n:st2.top();

            suff[i] = ind;

            st2.push(i);
        }

        long long mod = 1e9+7;

        for(int i=0;i<n;i++){
            ans = (ans + 1ll*(1ll*(i-pref[i])*(suff[i]-i)*arr[i])%mod)%mod;
        }

        return ans;

    }
};