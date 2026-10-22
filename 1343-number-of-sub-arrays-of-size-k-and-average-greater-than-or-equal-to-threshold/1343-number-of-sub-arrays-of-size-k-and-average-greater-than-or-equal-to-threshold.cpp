class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int l=0;
        int r=k-1;
        int cnt=0;
        int sum=accumulate(arr.begin(),arr.begin()+k,0);
        while(r<n-1){
          double avg=(double)sum/k;
          if(avg>=threshold){
             cnt++;
          }
          sum=sum-arr[l];
          l++;
          r++;
          sum=sum+arr[r];
        }
        double a=(double)sum/k;
        if(a>=threshold){
            cnt++;
        }
        return cnt;
    }
};