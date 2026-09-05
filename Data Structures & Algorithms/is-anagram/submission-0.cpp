class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        if (s.length()!=t.length()){
            return false;
        }
        for (char i:s){
            mp1[i]++;
        }
        for (char i:t){
            mp2[i]++;
        }
        for (char i:s){
            if (mp1[i]!=mp2[i]){
                return false;
            }
        }
        return true;
    }
};