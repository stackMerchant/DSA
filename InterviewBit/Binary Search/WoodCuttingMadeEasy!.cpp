// https://www.interviewbit.com/problems/woodcutting-made-easy/

long long int wood(vector<int> &A, int height) {
    long long int sum = 0;
    for (auto &a: A) if (a > height && height >= 0) sum += a - height;
    return sum;
}

int Solution::solve(vector<int> &A, int B) {
    long long int low, high, mid, currWood, ans = 0;
    low = 0, high = pow(10, 6);
    while (low <= high) {
        mid = (high + low) / 2;
        currWood = wood(A, mid);
        
        if (currWood >= B) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return ans;
}
