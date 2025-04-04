// https://www.interviewbit.com/problems/balanced-parantheses/

int Solution::solve(string A) {
    int count = 0;
    
    for (auto a: A) {
        if (a == '(') count++;
        else if (count > 0) count--;
        else return 0;
    }
    
    return count == 0;
}