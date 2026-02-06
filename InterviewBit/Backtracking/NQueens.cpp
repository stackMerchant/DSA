// https://www.interviewbit.com/problems/nqueens/

unordered_set<int> cols, addDiag, subDiag;

bool isNotInSet(unordered_set<int> &set, int n) {
    return set.find(n) == set.end();
}

void trav(int i, vector<string> &board, vector<vector<string>> &ans) {
    if (i >= board.size()) {
        ans.push_back(board);
        return;
    }
    
    for (int j=0; j<board.size(); j++) {
        if (isNotInSet(cols, j) && isNotInSet(addDiag, i+j) && isNotInSet(subDiag, i-j)) {
            // add in sets and board
            cols.insert(j); addDiag.insert(i+j); subDiag.insert(i-j);
            board[i][j] = 'Q';
            
            trav(i+1, board, ans);
            
            // remove from sets and board
            cols.erase(j); addDiag.erase(i+j); subDiag.erase(i-j);
            board[i][j] = '.';
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int A) {
    vector<string> board(A, string(A, '.'));
    vector<vector<string>> ans;
    trav(0, board, ans);
    return ans;
}
