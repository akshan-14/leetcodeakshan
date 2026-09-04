class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int n=nums.size();
        for(int i=0;i<n;i++){
            int mini=*min_element(nums.begin()+i,nums.end());
            int maxi=*max_element(nums.begin(),nums.begin()+i);
            if(maxi-mini<=k){
                return i;
            }
        }
        return -1;
    }
};