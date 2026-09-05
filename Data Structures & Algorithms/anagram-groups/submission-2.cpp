class Solution {
public:
    string generate(string &x){
        int freq[26]={0};
        for (auto ch:x){
            freq[ch-'a']++;
        }
        string key="";
        for (int i=0;i<26;i++){
            if (freq[i]>0){
                key+=string(freq[i],i+'a');
            }
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for (auto x:strs){
            string key=generate(x);
            mp[key].push_back(x);
        }
        vector<vector<string>>s;
        for (auto x:mp){
            s.push_back(x.second);
        }
        return s;
    }
};