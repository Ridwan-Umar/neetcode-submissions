class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        unordered_set<int>st;
        for (int x:nums){
            st.insert(x);
        }
        int ans=1;
        for (auto x:st){
            if (st.find(x-1)==st.end()){
                int count=1;
                int nextnum=x;
                while (st.find(nextnum+1)!=st.end()){
                    count++;
                    nextnum++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};
