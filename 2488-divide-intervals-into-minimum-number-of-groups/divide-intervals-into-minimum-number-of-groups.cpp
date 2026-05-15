class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),[&](vector<int> &a,vector<int> &b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]>b[0];
        });

        multiset<int> st;

        for(int i=0;i<intervals.size();i++){
            if(st.empty()){
                st.insert(intervals[i][0]);
            }
            else{
                auto it = st.upper_bound(intervals[i][1]);
                if(it==st.end()){
                    st.insert(intervals[i][0]);
                }
                else{
                    st.erase(it);
                    st.insert(intervals[i][0]);
                }
            }
        }

        return st.size();

        
    }
};