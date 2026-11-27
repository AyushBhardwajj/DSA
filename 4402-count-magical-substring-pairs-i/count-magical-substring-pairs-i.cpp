class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.length();

        vector<map<int,int>> vec(n);

        for(int i=0;i<n;i++){
            set<char> st;
            for(int j=i;j<n;j++){
                st.insert(s[j]);
                int cnt = st.size();
                vec[i][cnt]++;
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            set<char> st;
            for(int j=i;j<n-1;j++){
                st.insert(s[j]);
                int cnt = st.size();
                if(vec[j+1].count(cnt)){
                    ans += vec[j+1][cnt];
                }
            }
        }

        return ans;
    }
};