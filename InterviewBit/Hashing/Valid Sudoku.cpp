// https://www.interviewbit.com/problems/valid-sudoku/

int Solution::isValidSudoku(const vector<string> &A) {
    unordered_set<int> set;
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (A[i][j] == '.') continue;
            else if (set.find(A[i][j]) != set.end()) return 0; 
            set.insert(A[i][j]);
        }
        set.clear();
    }
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (A[j][i] == '.') continue;
            else if (set.find(A[j][i]) != set.end()) return 0;
            set.insert(A[j][i]);
        }
        set.clear();
    }
    
    for (int i=0; i<9; i+=3) {
        for (int j=0; j<9; j+=3) {
            for (int k=0; k<3; k++) {
                for (int l=0; l<3; l++) {
                    char t = A[i+k][j+l];
                    if (t == '.') continue;
                    else if (set.find(t) != set.end()) return 0;
                    set.insert(t);
                }
            }
            set.clear();
        }
    }
    return 1;
}
