class Solution {
public:
    int countCommas(int n) {
        int dig=(log10(n))+1;
        if(dig<4){
            return 0;
        }
        return (n-999);
    }
};