class Solution {
    int mod = 1e9 + 7;
    long long solve(string str, int i, int j, vector<vector<long long>>& dp) {
        // base case
        if (i > j)
            return 0;

        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        //  we are aiming here to calculate the number of different palindromic
        //  subsequences , key to take care here is DIFFERENT

        if (str[i] == str[j]) {
            int left = i + 1;
            int right = j - 1;

            while (left <= right && str[i] != str[left]) {
                left++;
            }
            while (left <= right && str[i] != str[right]) {
                right--;
            }

            //  if there is no occurence means there will be not any occurences
            //  hence all subsequences will be different
            if (left > right) {
                return dp[i][j] = 2 * solve(str, i + 1, j - 1, dp) % mod + 2;
                // 2-> s[i] , s[i]s[j] -> no same
            } else if (left == right) {
                return dp[i][j] = 2 * solve(str, i + 1, j - 1, dp) % mod + 1;
            } else {
                return dp[i][j] =
                           (2 * solve(str, i + 1, j - 1, dp) % mod -
                            solve(str, left + 1, right - 1, dp) % mod + mod) %
                           mod;
            }
        } else {
            return dp[i][j] = (solve(str, i + 1, j, dp) % mod +
                               solve(str, i, j - 1, dp) % mod -
                               solve(str, i + 1, j - 1, dp) % mod + mod) %
                              mod;
        }
    }

public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        string str=s;

        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {

                if (str[i] == str[j]) {
                    int left = i + 1;
                    int right = j - 1;

                    while (left <= right && str[i] != str[left]) {
                        left++;
                    }
                    while (left <= right && str[i] != str[right]) {
                        right--;
                    }

                    //  if there is no occurence means there will be not any
                    //  occurences hence all subsequences will be different
                    if (left > right) {
                        dp[i][j] = 2 * dp[i + 1][j - 1]% mod + 2;
                    } else if (left == right) {
                    dp[i][j] = 2 * dp[i + 1][j - 1] % mod + 1;
                    } else {
                        dp[i][j] = (2 * dp[i + 1][j - 1]% mod -dp[left + 1][right - 1]% mod + mod) % mod;
                    }
                } else {
                    dp[i][j] =
                               (dp[i + 1][j]% mod +dp[i][j - 1]% mod -dp[i + 1][j - 1] % mod + mod) % mod;
                }
            }
        }

        return dp[0][n - 1];
    }
};