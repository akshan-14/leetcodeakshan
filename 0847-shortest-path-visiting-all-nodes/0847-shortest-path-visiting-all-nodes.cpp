class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int target=(1<<n)-1;
        queue<tuple<int,int,int>>q;
        vector<vector<int>>visited(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            q.push({i,mask,0});
        }
        while(!q.empty()){
            auto[node,mask,dist]=q.front();
            q.pop();
            if(mask==target){
                return dist;
            }
            for(auto x:graph[node]){
                int new_mask=(mask|(1<<x));
                if(!visited[x][new_mask]){
                    visited[x][new_mask]=1;
                    q.push({x,new_mask,dist+1});
                }
            }
        }
        return 0;
    }
};