class Solution {
public:
    string generate(string s){
        int arr[26]={0};
        for (auto x:s){
            arr[x-'a']++;
        }
        string new_word="";
        for (int i=0;i<26;i++){
            if (arr[i]>0){
                new_word+=string(arr[i],i+'a');
            }
        }
        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (auto s:strs){
            string new_word=s;
            new_word=generate(s);
            res[new_word].push_back(s);
        }
        vector<vector<string>> result;
        for (auto r : res){
            result.push_back(r.second);
        }
        return result;
    }
};