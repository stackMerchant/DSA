// https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/

vector<int> Solution::solve(int A, int B, int C, int D) {
    int a = 0, b = 0, c = 0, curr; // Pointers for each prime number
    vector<int> ret;
    ret.push_back(1); // Add 1 at the start, and all pointers are on this initially
    
    while (D > 0) {
        curr = min(ret[a] * A, min(ret[b] * B, ret[c] * C)); // Multiply primes to their pointer numbers
        
        if (ret.back() < curr) { // If only current number is acceptable
            ret.push_back(curr);
            D--;
        }
        
        // Increase pointer for prime contributing to curr
        if (curr == ret[a] * A) a++;
        else if (curr == ret[b] * B) b++;
        else if (curr == ret[c] * C) c++;
    }
    
    ret.erase(ret.begin()); // Remove 1 from start
    return ret;
}
