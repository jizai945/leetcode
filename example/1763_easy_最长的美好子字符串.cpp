// 1763. 最长的美好子字符串
// 当一个字符串 s 包含的每一种字母的大写和小写形式 同时 出现在 s 中，就称这个字符串 s 是 美好 字符串。比方说，"abABB" 是美好字符串，因为 'A' 和 'a' 同时出现了，且 'B' 和 'b' 也同时出现了。然而，"abA" 不是美好字符串因为 'b' 出现了，而 'B' 没有出现。

// 给你一个字符串 s ，请你返回 s 最长的 美好子字符串 。如果有多个答案，请你返回 最早 出现的一个。如果不存在美好子字符串，请你返回一个空字符串。

 

// 示例 1：

// 输入：s = "YazaAay"
// 输出："aAa"
// 解释："aAa" 是一个美好字符串，因为这个子串中仅含一种字母，其小写形式 'a' 和大写形式 'A' 也同时出现了。
// "aAa" 是最长的美好子字符串。
// 示例 2：

// 输入：s = "Bb"
// 输出："Bb"
// 解释："Bb" 是美好字符串，因为 'B' 和 'b' 都出现了。整个字符串也是原字符串的子字符串。
// 示例 3：

// 输入：s = "c"
// 输出：""
// 解释：没有美好子字符串。
// 示例 4：

// 输入：s = "dDzeE"
// 输出："dD"
// 解释："dD" 和 "eE" 都是最长美好子字符串。
// 由于有多个美好子字符串，返回 "dD" ，因为它出现得最早。
 

// 提示：

// 1 <= s.length <= 100
// s 只包含大写和小写英文字母。
// 通过次数16,154提交次数23,603


// 解法1， 遍历所有情况，然后判断
class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans;
        int m = s.size();

        for (int i = 0; i < m-1; i++) {
            unordered_map<char, int>tmp;
            for (int j = i; j < m; j++) {
                tmp[s[j]]++;
                if (i == j) continue;

                int err = 0;
                for (auto it = tmp.begin(); it != tmp.end(); it++) {
                    if ( islower(it->first) && tmp.count(toupper(it->first)) == 0 ) {
                        err = 1;
                        // cout << i << " " << j << " err1"<< endl;
                        break;
                    } else if ( isupper(it->first) && tmp.count(tolower(it->first)) == 0 ) {
                        err = 1;
                        // cout << i << " " << j << " err2"<< endl;
                        break;
                    }
                }
                if (!err) {
                    string s_tmp = s.substr(i, j-i+1);
                    if (s_tmp.size() > ans.size()) {
                        ans = s_tmp;
                    }
                }

            }
            
        }

        return ans;
    }
};

// 解法2: 分治，判断每个大小写都存在的子串
class Solution {
public:
    void dfs(const string &s, int start, int end, int& maxPos, int& maxLen) {
        if (start >= end) {
            return;
        }
        int lower = 0;
        int upper = 0;
        for (int i = start; i <= end; i++) {
            if (islower(s[i])) {
                lower |= 1 << (s[i] - 'a');
            } else {
                upper |= 1 << (s[i] - 'A');
            }
        }
        if (lower == upper) {
            if (end - start + 1 > maxLen) {
                maxPos = start;
                maxLen = end - start + 1;
            }
            return ;
        }

        int tmp = lower & upper;
        int pos = start;
        while (pos <= end) {
            start = pos;
            while (pos <= end && tmp & (1 << (tolower(s[pos]) - 'a')) ) {
                pos++;
            }
            dfs(s, start, pos-1, maxPos, maxLen);
            pos++;
        }

        
    }

    string longestNiceSubstring(string s) {
        int maxPos = 0;
        int maxLen = 0;
        dfs(s, 0, s.size()-1, maxPos, maxLen);
        return s.substr(maxPos, maxLen);
    }
};


// 解法3: 滑动窗口
class Solution {
public:
    string longestNiceSubstring(string s) {
        int maxPos = 0, maxLen = 0;
        auto check = [&](int typeNum) {
            vector<int> lowerCnt(26);
            vector<int> upperCnt(26);
            int cnt = 0;
            for (int l = 0, r = 0, total = 0; r < s.size(); ++r) {
                int idx = tolower(s[r]) - 'a';
                if (islower(s[r])) {
                    ++lowerCnt[idx];
                    if (lowerCnt[idx] == 1 && upperCnt[idx] > 0) {
                        ++cnt;
                    }
                } else {
                    ++upperCnt[idx];
                    if (upperCnt[idx] == 1 && lowerCnt[idx] > 0) {
                        ++cnt;
                    }
                }
                total += (lowerCnt[idx] + upperCnt[idx]) == 1 ? 1 : 0;

                while (total > typeNum) {
                    idx = tolower(s[l]) - 'a';
                    total -= (lowerCnt[idx] + upperCnt[idx]) == 1 ? 1 : 0;
                    if (islower(s[l])) {
                        --lowerCnt[idx];
                        if (lowerCnt[idx] == 0 && upperCnt[idx] > 0) {
                            --cnt;
                        }
                    } else {
                        --upperCnt[idx];
                        if (upperCnt[idx] == 0 && lowerCnt[idx] > 0) {
                            --cnt;
                        }
                    }
                    ++l;
                }
                if (cnt == typeNum && r - l + 1 > maxLen) {
                    maxPos = l;
                    maxLen = r - l + 1;
                }
            }
        };

        int mask = 0;
        for (char & ch : s) {
            mask |= 1 << (tolower(ch) - 'a');
        }
        int types = __builtin_popcount(mask);
        for (int i = 1; i <= types; ++i) {
            check(i);
        }
        return s.substr(maxPos, maxLen);
    }
};
