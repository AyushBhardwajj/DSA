class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<int,string> mp;
        map<string,int> mp3;

        int k = words[0].length();
        int m = words.size();
        int n = s.length();
    
        for(int i=0;i<words.size();i++){
            mp3[words[i]]++;
        }

        for(int i=0;i<=n-k;i++){
            string str = s.substr(i,k);
            if(mp3.count(str))mp[i] = str;
        }
        

        vector<int> ans;

        for(int i = 0;i<k;i++){
            int start = i,end = i;
            map<string,int> mp2;
            int cnt = 0;
            while(end<n){
                if(!mp.count(end)){
                    start = end+k;
                    end = end+k;
                    cnt = 0;
                    mp2.clear();
                    continue;
                }

                string str = mp[end];

                if(mp2[str]+1 > mp3[str]){
                    mp2[mp[start]]-=1;
                    start+=k;
                    cnt--;
                }
                else {
                    mp2[str]+=1;
                    end+=k;
                    cnt++;
                }

                if(cnt == m){
                    int crr = start;
                    ans.push_back(crr);
                    mp2[mp[start]]-=1;
                    start+=k;
                    cnt--;
                }
            }
        }

        return ans;


    }
};