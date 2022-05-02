// 5. 最长回文子串
// 给你一个字符串 s，找到 s 中最长的回文子串。

 

// 示例 1：

// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。
// 示例 2：

// 输入：s = "cbbd"
// 输出："bb"
 

// 提示：

// 1 <= s.length <= 1000
// s 仅由数字和英文字母组成



class Solution {
public:
    string longestPalindrome(string s) {
        int m = s.size();
        if (m == 1) return s;
        vector<vector<int>> dp(m, vector<int>(m, 0));
        int maxLen = 1;
        string ans = s.substr(0, 1);

        for (int i = 0; i < m; i++) {
            dp[i][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int sa = 0; sa < m; sa++) {
                int e = sa + i;
                if (e >= m) continue;
                    if ( (i == 1 && s[sa] == s[e]) ||
                        (s[sa] == s[e] && dp[sa+1][e-1]) ) {
                        dp[sa][e] = 1;
                        if (e - sa + 1 > maxLen) {
                            maxLen = e - sa + 1;
                            ans = s.substr(sa, e-sa+1);
                            // cout << maxLen << " " << dp[sa+1][e-1] << " " << ans << endl;
                        }
                    }
                
            }
        }

        return ans;

    }
};