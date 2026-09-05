class Solution {
public:
    bool hasDuplicate(vector<int>&arr) {
        unordered_map<int,int>mp;
        for (int i:arr){
            mp[i]++;
            if (mp[i]>1){
                return true;
            }
        }
        return false;
    }
};