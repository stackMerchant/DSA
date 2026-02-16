// https://www.interviewbit.com/problems/palindromic-binary-representation/

// Solution explanation => https://www.youtube.com/watch?v=oA-2BPNwjYQ

// Groups, no of elements, length of binary
// 1, 2, (1, 2)
// 2, 4, (3, 4)
// 3, 8, (5, 6)

int Solution::solve(int A) {
    int g = 1; // group
    
    // Calculate group
    while (A - (1<<g) > 0) {
        A -= (1<<g);
        g++;
    }

    // Calculate which part of group
    int digits = 2*g - 1; // see illustration above
    if (A > (1<<g)/2) { // if in second part
        A -= (1<<g)/2;
        digits++;
    }
    
    // Prepare binary of left over number
    A--;
    string bin = "";
    while (A > 0) {
        bin = bin + (A%2 == 0 ? '0' : '1');
        A /= 2;
    }
    
    // Calculate zeroes to append and append, with 1
    int controlledPositions = (digits + 1) / 2;
    int zeroes = controlledPositions - 1 - bin.size();
    while (zeroes > 0) {
        bin += '0';
        zeroes--;
    }
    bin += '1';
    
    // Generate first half of binary
    string reverseBin = bin;
    reverse(reverseBin.begin(), reverseBin.end());
    if (digits%2 == 1)
        reverseBin = reverseBin.substr(0, reverseBin.size() -1);
    
    // Add both to get final binary
    bin = reverseBin + bin;
    
    // Convert to number
    int ans = 0, p = 0;
    for (auto b: bin) {
        ans += (b - '0')*(1<<p);
        p++;
    }

    return ans;
}