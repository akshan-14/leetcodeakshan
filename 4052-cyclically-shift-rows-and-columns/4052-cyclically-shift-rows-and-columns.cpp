class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
       vector<vector<int>>copy=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int k=rowShift[i];
                int nc=(j+k)%n;
                grid[i][j]=copy[i][nc];
            }
        }
        vector<vector<int>>copy1=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int k=colShift[j];
                int nr=(i+k)%n;
                grid[i][j]=copy1[nr][j];
            }
        }
        return grid;
    }
};