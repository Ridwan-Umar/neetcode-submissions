class Solution {
public:
    bool isHappy(int n) {
        if (n==1 || n==7){
            return true;
        }
        while (true){
            int sum=0;
            while (n>0){
                sum+=(n%10)*(n%10);
                n=n/10;
            }
            n=sum;
            if (n==1 || n==7){
                return true;
            }
            if (n==2 || n==3 ||n==4 || n==5 || n==6 ||n==8||n==9){
                return false;
            }
        }
        return false;
    }
};