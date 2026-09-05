class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>arr(n+1);
        unordered_map<int,int>mp;
        for (auto x:nums){
            mp[x]++;
        }
       for (auto x:mp){
        //index=freq
        //value=element
        //arr[i]=element having freq i
        int element =x.first;
        int freq=x.second;
        arr[freq].push_back(element);
       }
       vector<int>arr1;
       for (int i=n;i>0;i--){
        if (arr[i].size()==0){
            continue;
        }
        while (arr[i].size()>0 && k>0){
            arr1.push_back(arr[i].back());
            arr[i].pop_back();
            k--;
        }
       }
       return arr1;
    }
};
