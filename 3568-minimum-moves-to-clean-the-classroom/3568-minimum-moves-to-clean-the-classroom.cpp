class Solution {
public:

    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    int minMoves(vector<string>& classroom, int energy) {
        int litters=0;
        int m=classroom.size();
        int n=classroom[0].size();
        vector<vector<int>>id(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='L'){
                    id[i][j]=(1<<(litters));
                    litters++;
                }
            }
        }
        int tar=(1<<litters)-1;
        if (tar==0) {return 0;}
        vector<vector<vector<int>>>vis(m,vector<vector<int>>(n,vector<int>(tar+1,-1)));
        queue<tuple<int,int,int,int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    vis[i][j][0]=energy;
                    q.push({i,j,0,energy,0});
                }
            }
        }
        vector<pair<int,int>>movements={
            {0,1},{1,0},{-1,0},{0,-1}
        };
        
        while(!q.empty()){
            auto [x,y,mask,e,step]=q.front();
            q.pop();
            if(mask==tar){
                return step;
            }
            for(auto move:movements){
                int new_x=move.first+x;
                int new_y=move.second+y;
                if(isValid(new_x,new_y,m,n) && classroom[new_x][new_y]!='X'){
                    int new_mask=0;
                    int new_e=e-1;
                    if(new_e<0){
                        continue;
                    }
                    if(classroom[new_x][new_y]=='R'){
                        new_e=energy;
                    }
                    if(id[new_x][new_y]){
                        new_mask=mask|(id[new_x][new_y]);
                    }else{
                        new_mask=mask;
                    }
                    
                    if(new_e>(vis[new_x][new_y][new_mask])){
                        vis[new_x][new_y][new_mask]=new_e;
                        q.push({new_x,new_y,new_mask,new_e,step+1});
                    }
                }

            }
        }
            return -1;
    }
};