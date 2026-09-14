
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> onesImg1;
        vector<pair<int, int>> onesImg2;

        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) onesImg1.push_back({r, c});
                if (img2[r][c] == 1) onesImg2.push_back({r, c});
            }
        }

      
        map<pair<int, int>, int> translationCounts;
        int maxOverlap = 0;

        
        for (auto p1 : onesImg1) {
            for (auto p2 : onesImg2) {
                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;
                
                translationCounts[{dx, dy}]++;
                maxOverlap = max(maxOverlap, translationCounts[{dx, dy}]);
            }
        }

        return maxOverlap;
    }
};