// https://www.interviewbit.com/problems/potions/

class MixResult {
    public:
        int color;
        int smoke;
        MixResult(int c, int s) {
            color = c;
            smoke = s;
        };
};

MixResult calc(vector<vector<MixResult>> &dp, vector<int> colors, int i, int j) {
    if (dp[i][j].color != -1) return dp[i][j];
    if (i == j) {
        dp[i][j] = MixResult(colors[i], 0);
        return dp[i][j];
    }

    int minSmoke = INT_MAX, minColor, currSmoke;
    for (int k=i; k<j; k++) {
        MixResult mixA = calc(dp, colors, i, k);
        MixResult mixB = calc(dp, colors, k+1, j);
        currSmoke = mixA.smoke + mixB.smoke + mixA.color * mixB.color;
        
        if (currSmoke < minSmoke) {
            minSmoke = currSmoke;
            minColor = (mixA.color + mixB.color) % 100;
        }
    }

    dp[i][j] = MixResult(minColor, minSmoke);
    return dp[i][j];
}

int Solution::minSmoke(vector<int> &A) {
    int N = A.size();
    vector<vector<MixResult>> dp(N, vector<MixResult>(N, MixResult(-1, -1)));
    return calc(dp, A, 0, N-1).smoke;
}
