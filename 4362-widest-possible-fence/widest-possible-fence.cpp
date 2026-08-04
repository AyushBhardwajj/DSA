class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();

        map<long long,int> mp;

        int ans = 0;
        long long cc = 0;
        set<int> st;

        for(int i=0;i<n;i++){
            long long curr = planks[i];
            mp[curr]++;
            if(ans<mp[curr]){
                ans = mp[curr];
                cc = curr;
            }
            st.insert(planks[i]);
        }

        vector<int> narr;

        for(auto it:st){
            int val  = it;
            narr.push_back(val);
        }

        cout<<mp[5]<<"\n";

        int m = narr.size();

        sort(narr.begin(),narr.end());

        map<long long,int> mp2;

        for(auto it:mp){
            mp2[it.first] = mp[it.first];
        }

        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                long long curr = 1ll*narr[i]+1ll*narr[j];
                // mp2[curr]+=mp[curr];
                if(i==j){
                    mp2[curr]=mp2[curr]+(mp[narr[i]])/2;
                    if(curr == 5){
                        cout<<"-->1-->"<<mp[narr[i]]<<"\n";
                    }
                }
                else{
                    mp2[curr]+=min(mp[narr[i]],mp[narr[j]]);
                    if(curr == 5){
                        cout<<"-->2-->"<<narr[i]<<" "<<narr[j]<<" "<<min(mp[narr[i]],mp[narr[j]])<<"\n";
                    }
                }

                if(ans<mp2[curr]){
                    ans = mp2[curr];
                    cc = curr;
                }
            }
        }

        cout<<cc<<"\n";

        return ans;

        
    }
};