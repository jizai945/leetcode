// 1220. 统计元音字母序列的数目
// 给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：

// 字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
// 每个元音 'a' 后面都只能跟着 'e'
// 每个元音 'e' 后面只能跟着 'a' 或者是 'i'
// 每个元音 'i' 后面 不能 再跟着另一个 'i'
// 每个元音 'o' 后面只能跟着 'i' 或者是 'u'
// 每个元音 'u' 后面只能跟着 'a'
// 由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。

 

// 示例 1：

// 输入：n = 1
// 输出：5
// 解释：所有可能的字符串分别是："a", "e", "i" , "o" 和 "u"。
// 示例 2：

// 输入：n = 2
// 输出：10
// 解释：所有可能的字符串分别是："ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" 和 "ua"。
// 示例 3：

// 输入：n = 5
// 输出：68
 

// 提示：

// 1 <= n <= 2 * 10^4
// 通过次数16,004提交次数26,654

class Solution {
public:
    int countVowelPermutation(int n) {
        long long mod = pow(10, 9) + 7;
        vector<long long>dp(5, 1);
        vector<long long>tmp(5);

        for (int i = 1; i < n; i++) {
            tmp[0] = (dp[1] + dp[2] + dp[4]) % mod;
            tmp[1] = (dp[0] + dp[2]) % mod;
            tmp[2] = (dp[1] + dp[3]) % mod;
            tmp[3] = dp[2] % mod;
            tmp[4] = (dp[2] + dp[3]) % mod;
            dp = tmp;
        }

        long long ans = 0;
        for (auto n: dp) {
            ans += n;
            ans %= mod;
        }
        return (int)ans;
        
    }
};