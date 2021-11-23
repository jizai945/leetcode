// 859. 亲密字符串
// 给你两个字符串 s 和 goal ，只要我们可以通过交换 s 中的两个字母得到与 goal 相等的结果，就返回 true ；否则返回 false 。

// 交换字母的定义是：取两个下标 i 和 j （下标从 0 开始）且满足 i != j ，接着交换 s[i] 和 s[j] 处的字符。

// 例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。
 

// 示例 1：

// 输入：s = "ab", goal = "ba"
// 输出：true
// 解释：你可以交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 相等。
// 示例 2：

// 输入：s = "ab", goal = "ab"
// 输出：false
// 解释：你只能交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 不相等。
// 示例 3：

// 输入：s = "aa", goal = "aa"
// 输出：true
// 解释：你可以交换 s[0] = 'a' 和 s[1] = 'a' 生成 "aa"，此时 s 和 goal 相等。
// 示例 4：

// 输入：s = "aaaaaaabc", goal = "aaaaaaacb"
// 输出：true
 

// 提示：

// 1 <= s.length, goal.length <= 2 * 104
// s 和 goal 由小写英文字母组成
// 通过次数54,585提交次数159,556

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        vector<int> err_index;
        unordered_map<int, int> m;
        int same_flag = 0;

        if (s.size() != goal.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) {
                err_index.push_back(i);
            } else {
                m[s[i] - 'a']++;
                if (m[s[i] - 'a'] >= 2) {
                    same_flag = 1;
                }
            }
        }

        if (err_index.size() == 2) {
            if (s[err_index[0]] == goal[err_index[1]] && s[err_index[1]] == goal[err_index[0]]) {
                return true;
            }
        } else if (err_index.size() == 0 && same_flag == 1) {
            return true;
        }
        

        return false;
    }
};