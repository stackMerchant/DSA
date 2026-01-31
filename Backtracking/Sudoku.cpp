// https://www.interviewbit.com/problems/sudoku/

vector<unordered_set<char>> rowSets, colSets, boxSets;

void prepareSets(vector<vector<char> > &A) {
    rowSets.clear(); rowSets.resize(9);
    colSets.clear(); colSets.resize(9);
    boxSets.clear(); boxSets.resize(9);
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            char e = A[i][j];
            if (e != '.') {
                rowSets[i].insert(e);
                colSets[j].insert(e);
                boxSets[3*(i/3) + j/3].insert(e);
            }
        }
    }
}

bool solve(int i, int j, vector<vector<char>> &A) {
    if (A[i][j] != '.') {
        if (j<8) return solve(i, j+1, A);
        if (i<8) return solve(i+1, 0, A);
        return true;
    }

    for (int c=0; c<9; c++) {
        char ne = '1' + c; // new element
        
        if (
            rowSets[i].find(ne) == rowSets[i].end() &&
            colSets[j].find(ne) == colSets[j].end() &&
            boxSets[3*(i/3) + j/3].find(ne) == boxSets[3*(i/3) + j/3].end()
        ) {
            rowSets[i].insert(ne);
            colSets[j].insert(ne);
            boxSets[3*(i/3) + j/3].insert(ne);
            A[i][j] = ne;
            
            if (j<8) {
                if (solve(i, j+1, A)) return true;
            } else if (i<8) {
                if (solve(i+1, 0, A)) return true;
            } else {
                return true;
            }
            
            rowSets[i].erase(ne);
            colSets[j].erase(ne);
            boxSets[3*(i/3) + j/3].erase(ne);
            A[i][j] = '.';
        }
    }

    return false;
}

void Solution::solveSudoku(vector<vector<char>> &A) {
    prepareSets(A);
    solve(0, 0, A);
    return;
}
