class Solution {
public:
    int fun(string s){
        int cnt=0;
        for(auto x:s){
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
                cnt++;
            }
        }
        return cnt;
    }
    bool check(char x){
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int l=0;
        int r=k-1;
        int ans=INT_MIN;
        string sub=s.substr(l,r-l+1);
        int cnt=fun(sub);
        while(r<n-1){
            ans=max(cnt,ans);
            if(check(s[l])){
                cnt--;
            }
            l++;
            r++;
            if(check(s[r])){
                cnt++;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};