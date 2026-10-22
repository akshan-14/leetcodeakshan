class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0;
        int  r=k-1;
        double n=nums.size();
        double sum=accumulate(nums.begin(),nums.begin()+k,0);
        double ans=INT_MIN;
        while(r<n-1){
             ans=max(ans,(sum)/k);
             sum=sum-nums[l];
             l++;
             r++;
             sum=sum+nums[r];
        }
        ans=max((sum)/k,ans);
        return ans;
    }
};