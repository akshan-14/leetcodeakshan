class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0;
        sort(nums1.begin(),nums1.end());
        for(auto x:nums1){
            if(x%2!=0){
                odd++;
            }
        }
        if(odd==0){
            return true;
        }
        int min=0;
        int index=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                min=nums1[i];
                index=i;
                break;
            }
        }
        for(int i=0;i<nums1.size();i++){
            if(i==index){
                continue;
            }
            else if(nums1[i]-min<=0){
                return false;
            }
        }
        return true; 
    }
};