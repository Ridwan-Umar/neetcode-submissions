class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<char>f1(26,0);
        vector<char>f2(26,0);
        int i=0;
        int j=0;
        for (auto x:s1){
            f1[x-'a']++;
        }
        while (j<m){
            f2[s2[j]-'a']++;
            if ((j-i+1)>n){
                f2[s2[i]-'a']--;
                i++;
            }
            if (f1==f2){
                return true;
            }
            j++;
        }
        return false;
    }
};
