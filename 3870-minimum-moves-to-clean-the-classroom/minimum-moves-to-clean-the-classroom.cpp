class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        
        int rows = classroom.size();
        int cols = classroom[0].size();

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        int startr = -1,startc =-1;
        int littercount = 0;
        map<pair<int,int>,int> mp;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(classroom[i][j] == 'S'){
                    startr = i;
                    startc = j;
                }

                else if(classroom[i][j] == 'L'){
                    mp[{i,j}] = littercount;
                    littercount++;
                }
            }
        }


        if(littercount == 0)return 0;

        int target_mask = (1<<littercount) - 1;

        vector<vector<vector<vector<int>>>> dist(rows,vector<vector<vector<int>>>(cols,vector<vector<int>>(energy+1,vector<int>(1<<littercount,-1))));

        queue<tuple<int,int,int,int>> q;

        dist[startr][startc][energy][0] = 0;

        q.push({startr,startc,energy,0});

        while(!q.empty()){

            auto [r,c,current_e,visited_mask] = q.front();
            q.pop();

            int moves = dist[r][c][current_e][visited_mask];

            if(visited_mask == target_mask){
                return moves;
            }

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<rows && nc>=0 && nc<cols && classroom[nr][nc] != 'X' && current_e > 0){

                    int next_moves = moves+1;
                    int next_e = current_e - 1;
                    int next_mask = visited_mask;

                    if(classroom[nr][nc] == 'L'){
                        next_mask = next_mask | (1<<mp[{nr,nc}]);
                    }

                    else if(classroom[nr][nc] == 'R'){
                        next_e = energy;
                    }

                    if(dist[nr][nc][next_e][next_mask] == -1){
                        dist[nr][nc][next_e][next_mask] = next_moves;
                        q.push({nr,nc,next_e,next_mask});
                    }
                }
            }


        }

        return -1;


    }
};