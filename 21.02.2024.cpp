// User function Template for C++

class Solution {
public:
    int dp[101][101][2];
    int solve(string s, int i, int j, int isTrue)
    {
        // Base Condition
        if (i > j)
            return false;
        if (i == j) {
            if (isTrue == 1)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue] % 1003;

        int ans = 0;
        for (int k = i + 1; k <= j - 1; k = k + 2) {
            int leftF, leftT, rightT, rightF;
            if (dp[i][k - 1][1] == -1) {
                leftT = solve(s, i, k - 1, 1) % 1003;
            } // Count no. of T in left partition
            else {
                leftT = dp[i][k - 1][1] % 1003;
            }

            if (dp[k + 1][j][1] == -1) {
                rightT = solve(s, k + 1, j, 1) % 1003;
            } // Count no. of T in right partition
            else {
                rightT = dp[k + 1][j][1] % 1003;
            }

            if (dp[i][k - 1][0] == -1) {
                // Count no. of F in left partition
                leftF = solve(s, i, k - 1, 0) % 1003;
            }
            else {
                leftF = dp[i][k - 1][0] % 1003;
            }

            if (dp[k + 1][j][0] == -1) {
                // Count no. of F in right partition
                rightF = solve(s, k + 1, j, 0) % 1003;
            }
            else {
                rightF = dp[k + 1][j][0] % 1003;
            }

            if (s[k] == '&') {
                if (isTrue == 1)
                    ans += leftT * rightT;
                else
                    ans += leftF * rightF + leftT * rightF
                           + leftF * rightT;

                ans %= 1003;
            }
            else if (s[k] == '|') {
                if (isTrue == 1)
                    ans += leftT * rightT + leftT * rightF
                           + leftF * rightT;
                else
                    ans = ans + leftF * rightF;

                ans %= 1003;
            }
            else if (s[k] == '^') {
                if (isTrue == 1)
                    ans = ans + leftF * rightT
                          + leftT * rightF;
                else
                    ans = ans + leftT * rightT
                          + leftF * rightF;

                ans %= 1003;
            }
            dp[i][j][isTrue] = ans % 1003;
        }
        return ans % 1003;
    }

    int countWays(int N, string S)
    {

        memset(dp, -1, sizeof(dp));
        return solve(S, 0, N - 1, 1);
    }
};
