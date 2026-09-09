class Solution {
public:
    long long countCommas(long long n) {
       int size=to_string(n).length();
       if(size<4){
        return 0;
       }
       long long ans=0;
      while(size!=3){
        if(size==16){
        long long a=n-(1e15)+1;
        ans+=a*5;
        size=15;
        n=1e15-1;
        }
       else if(size==15 ||size==14 ||size==13){
        long long a=n-(1e12)+1;
        ans+=a*4;
        size=12;
        n=1e12-1;
       }
       else if(size==12 ||size==11 ||size==10){
         long long a=n-(1e9)+1;
         ans+=a*3;
         size=9;
         n=1e9-1;
       }
       else if(size==9 ||size==8||size==7){
         long long a=n-(1e6)+1;
         ans+=a*2;
         size=6;
         n=(1e6)-1;
       }
       else{
         long long a=n-999;
        ans+=a;
        break;
       }
      }
      return ans;
    }
};