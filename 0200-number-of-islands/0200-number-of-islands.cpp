class Solution {
public:
    bool isvalid(int x,int y,int n,int m){
       
        if(x<0 ||x>=n||y<0||y>=m){
            return false;
        }
        return true;
    }
    void  dfs(int i,int j,vector<vector<int>>&visited,vector<vector<char>>&grid){
      visited[i][j]=1;
       int n=grid.size();
        int m=grid[0].size();
      int rx[]={-1,0,0,1};
      int ly[]={0,-1,1,0};
      for(int k=0;k<4;k++){
        int nx=i+rx[k];
        int ny=j+ly[k];
        
        if(isvalid(nx,ny,n,m)&&!visited[nx][ny] &&grid[nx][ny]=='1'){
            dfs(nx,ny,visited,grid);
        }

      }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(i,j,visited,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};