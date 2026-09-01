class Solution {
public:
    bool isvalid(int x,int y,int n,int m){
        if(x<0 ||y<0||x>=n||y>=m){
            return false;
        }
        return true;
    }
    int ans=INT_MIN;
    vector<vector<int>>visited;
    void bfs(int i,int j,vector<vector<int>>& grid){
        queue<pair<int,int>>q;
         int n=grid.size();
        int m=grid[0].size();
        q.push({i,j});
        visited[i][j]=1;
        int dr[]={-1,0,0,1};
        int dl[]={0,-1,1,0};
        
        int cnt=0;
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            cnt++;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dl[i];
                if(!isvalid(nr,nc,n,m)){
                    continue;
                }
                if(grid[nr][nc]==1 &&!visited[nr][nc]){
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        ans=max(ans,cnt);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        visited.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 &&!visited[i][j]){
                    bfs(i,j,grid);
                }
            }
        }
        if(ans==INT_MIN){
            return 0;
        }
        else{
        return ans;
        }
    }        
};