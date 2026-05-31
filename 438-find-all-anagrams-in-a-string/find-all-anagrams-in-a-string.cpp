class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n = s.length();
        int m = p.length();

        vector<int> map(26,0);

        for(int i=0;i<m;i++){
            map[p[i]-'a']++;
        }

        int start = 0,right  =0;
        vector<int> map2(26,0);

        int cnt = m;

        vector<int> ans;

        while(right<n){
            map2[s[right]-'a']++;
            cnt--;
            while(map2[s[right]-'a']>map[s[right]-'a']){
               map2[s[start]-'a']--;
               cnt++;
               start++;
            }

            if(cnt == 0){
                ans.push_back(right-m+1);
                map2[s[start]-'a']--;
                cnt++;
                start++;
            }
            right++;
        }

        return ans;

    }
};