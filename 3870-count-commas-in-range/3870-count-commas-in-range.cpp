class Solution {
public:
    int countCommas(int n) {
        int dig=(log10(n))+1;
        if(dig<4){
            return 0;
        }
        int ans=0;
        while(dig>=4){
            n--;
            dig=log10(n)+1;
            ans++;
        }
        return ans;
    }
};