// https://www.interviewbit.com/problems/tushars-birthday-bombs/

vector<int> Solution::solve(int A, vector<int> &B) {
    vector<int> ret;
    int n = B.size();
    if (n == 0) return ret;
    
    // Find smallest number in B
    int minB = B[0];
    for (auto b: B) minB = min(minB, b);
    
    // Find maximum number of shots possible
    int shotsCount = A / minB;
    
    int i = 0;
    while (shotsCount > 0) {
        // If after using B[i], we can still have shotsCount number of elements
        if (A - B[i] >= (shotsCount - 1) * minB) {
            A -= B[i]; // Decrease A
            ret.push_back(i); // Add element's index to answer
            shotsCount--; // Decrease shot's count
        } else i++; // Else move to next element
    }
    
    return ret;
}
