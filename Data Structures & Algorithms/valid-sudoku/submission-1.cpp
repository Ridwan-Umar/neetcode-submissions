class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++){
            unordered_map<char,int>mp1;
            unordered_map<char,int>mp2;
            for (int j=0;j<9;j++){
                mp1[board[i][j]]++;
                mp2[board[j][i]]++;
            }
            for (auto x:mp1){
                if (x.second>1 && x.first!='.'){
                    return false;
                }
            }
            for (auto x:mp2){
                if (x.second>1 && x.first!='.'){
                    return false;
                }
            }
        }
        for (int i= 0;i<9;i++) {
            unordered_map<char,int>box;
            for (int j=0;j<3;j++){
                for (int k=0;k<3;k++){
                    int r=3*(i/3)+j;
                    int c = 3*(i%3)+k;
                    char x=board[r][c];
                    if (x!='.'){
                        box[x]++;
                    }
                }
            }
            for (auto x:box){
                if (x.second>1){
                    return false;
                }
            }
        }
        return true;
    }
};
