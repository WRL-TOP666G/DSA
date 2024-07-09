class Solution {
public:
    bool row(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            set<char> st;
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] != '.'){
                    if(st.contains(board[i][j])) return false;
                    st.insert(board[i][j]);
                }
            }
        }

        return true;
    }

    bool col(vector<vector<char>>& board){
        for(int j=0; j<board[0].size(); j++){
            set<char> st;
            for(int i=0; i<board.size(); i++){
                if(board[i][j] != '.'){
                    if(st.contains(board[i][j])) return false;
                    st.insert(board[i][j]);
                }
            }
        }

        return true;
    }

    bool three(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i+=3){
            for(int j=0; j<board[0].size(); j+=3){
                set<char> st;
                for(int x=i; x<i+3; x++){
                    for(int y=j; y<j+3; y++){
                        if(board[x][y] != '.'){
                            if(st.contains(board[x][y])) return false;
                            st.insert(board[x][y]);
                        }
                    }
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return row(board) && col(board) && three(board);
    }
};

// 1 pass
// TC: O(1)
// SC: O(1)

