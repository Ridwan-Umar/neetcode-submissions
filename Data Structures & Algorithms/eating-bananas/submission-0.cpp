class Solution {
public:
    long long sumi(int mid,vector<int>& piles){
        long long sum=0;
        for (auto x:piles){
            sum+=(mid+x-1)/mid;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while (s<=e){
            int mid=(e-s)/2+s;
            if (sumi(mid,piles)<=h){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};