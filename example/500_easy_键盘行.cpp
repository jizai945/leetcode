// 500. 键盘行
// 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。

// 美式键盘 中：

// 第一行由字符 "qwertyuiop" 组成。
// 第二行由字符 "asdfghjkl" 组成。
// 第三行由字符 "zxcvbnm" 组成。
// American keyboard

 

// 示例 1：

// 输入：words = ["Hello","Alaska","Dad","Peace"]
// 输出：["Alaska","Dad"]
// 示例 2：

// 输入：words = ["omk"]
// 输出：[]
// 示例 3：

// 输入：words = ["adsdf","sfd"]
// 输出：["adsdf","sfd"]
 

// 提示：

// 1 <= words.length <= 20
// 1 <= words[i].length <= 100
// words[i] 由英文字母（小写和大写字母）组成
// 通过次数49,051提交次数66,092

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> m;
        vector<string> ans;

        string tmp[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        for (int i = 0; i < 3; i++) {
            for (auto ch: tmp[i]) {
                m[ch] = i;
                m[toupper(ch)] = i;
            }
        } 

        for (auto word: words){
            bool flag = true;
            for (int i = 1; i < word.size(); i++) {
                if (m[word[i]] != m[word[i-1]]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back(word);
            }
        }

        return ans;

    }
};