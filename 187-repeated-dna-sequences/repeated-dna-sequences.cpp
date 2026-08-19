class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_map<char,int> mp;
        mp['A'] = 0;
        mp['C'] = 1;
        mp['G'] = 2;
        mp['T'] = 3;

        int n = s.length();

        unordered_map<int,int>mp2;

        int hash = 0;

        for(int i=0;i<10;i++){
            hash = hash+mp[s[i]]*pow(4,9-i);
        }

        mp2[hash]++;

        vector<string> ans;

        for(int i =10;i<n;i++){
            hash = hash - mp[s[i-10]]*pow(4,9);
            hash = hash*4;
            hash = hash + mp[s[i]];

            if(mp2[hash]==1){
                ans.push_back(s.substr(i-9,10));
            }

            mp2[hash]++;
        }

        return ans;


    }
};