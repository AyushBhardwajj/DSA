class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mapWords;
        int n = s.length();


        for(int i=0;i<words.size();i++){
            mapWords[words[i]]++;
        }

        int k = words[0].length();

        vector<int> ans;

        for(int i=0;i<k;i++){
            int start = i,end = i;
            int cnt = words.size();
            unordered_map<string,int> mapSubstr;

            while(end+k<=n){
                string str = s.substr(end,k);

                if(!mapWords.count(str)){
                    start = end+k;
                    end = end+k;
                    cnt = words.size();
                    mapSubstr.clear();
                    continue;
                }
                else{
                    mapSubstr[str]++;
                    cnt--;
                    while(mapSubstr[str] > mapWords[str]){
                        string curr = s.substr(start,k);
                        mapSubstr[curr]--;
                        cnt++;
                        start+=k;
                    }

                    if(cnt == 0){
                        ans.push_back(start);
                        string curr2 = s.substr(start,k);
                        start+=k;
                        cnt++;
                        mapSubstr[curr2]--;
                    }
                }

                end +=k;
            }
        }

        return ans;


    }
};