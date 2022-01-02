// 686. 重复叠加字符串匹配
// 给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a 的子串，如果不存在则返回 -1。

// 注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。

 

// 示例 1：

// 输入：a = "abcd", b = "cdabcdab"
// 输出：3
// 解释：a 重复叠加三遍后为 "abcdabcdabcd", 此时 b 是其子串。
// 示例 2：

// 输入：a = "a", b = "aa"
// 输出：2
// 示例 3：

// 输入：a = "a", b = "a"
// 输出：1
// 示例 4：

// 输入：a = "abc", b = "wxyz"
// 输出：-1
 

// 提示：

// 1 <= a.length <= 104
// 1 <= b.length <= 104
// a 和 b 由小写英文字母组成
// 通过次数38,740提交次数97,912
// 请问您在哪类招聘中遇到此题？

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int res = -1;

        for (int i = 0; i < a.size(); i++) {
            int b_idx = 0;
            int a_idx = i;
            res = 0;
            while (b_idx < b.size()) {
                if (b[b_idx] != a[a_idx]) {
                    break;
                } else {
                    if (!res) res += 1;
                    b_idx++;
                    a_idx++;
                    a_idx = a_idx == a.size() ? 0 : a_idx;
                    if (a_idx == 0 && b_idx != b.size()) {
                        res++;
                    }
                }
            }
            if (b_idx == b.size()) {
                break;
            }
            res = -1;
        }

        return res;
    }
};