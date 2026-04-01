class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        vector<pair<int,pair<int,pair<char,int>>>> vec;

        int n = positions.size();

        for(int i=0;i<n;i++){
            vec.push_back({positions[i],{healths[i],{directions[i],i}}});
        }

        sort(vec.begin(),vec.end());

        stack<pair<int,int>> st;

        vector<pair<int,int>> ans;

        for(int i=0;i<n;i++){
            char dir = vec[i].second.second.first;
            int id = vec[i].second.second.second;
            if(dir=='L'){
                int val = vec[i].second.first;
                while(!st.empty() && st.top().first<=val){
                    if(st.top().first == val){
                        val = -1;
                    }
                    st.pop();
                    val--;
                }

                if(st.empty() && val>0){
                    ans.push_back({id,val});
                }
                else if(!st.empty() && val>=0){
                    st.top().first-=1;
                    if(st.top().first==0)st.pop();
                }
            }
            else{
                st.push({vec[i].second.first,id});
            }
        }


        while(!st.empty()){
            ans.push_back({st.top().second,st.top().first});
            st.pop();
        }

        sort(ans.begin(),ans.end());

        vector<int> fans;

        for(int i=0;i<ans.size();i++){
            fans.push_back(ans[i].second);
        }

        return fans;
    }
};