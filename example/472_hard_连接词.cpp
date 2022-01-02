
// 472. 连接词
// 给你一个 不含重复 单词的字符串数组 words ，请你找出并返回 words 中的所有 连接词 。

// 连接词 定义为：一个完全由给定数组中的至少两个较短单词组成的字符串。

 

// 示例 1：

// 输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
// 输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
// 解释："catsdogcats" 由 "cats", "dog" 和 "cats" 组成; 
//      "dogcatsdog" 由 "dog", "cats" 和 "dog" 组成; 
//      "ratcatdogcat" 由 "rat", "cat", "dog" 和 "cat" 组成。
// 示例 2：

// 输入：words = ["cat","dog","catdog"]
// 输出：["catdog"]
 

// 提示：

// 1 <= words.length <= 104
// 0 <= words[i].length <= 1000
// words[i] 仅由小写字母组成
// 0 <= sum(words[i].length) <= 105
// 通过次数18,172提交次数37,387
// 请问您在哪类招聘中遇到此题？


// 使用 前缀树和dfs的方法
struct Tree {
    bool isEnd;
    vector<Tree *> children;
    Tree() {
        this->children = vector<Tree *>(26, nullptr);
        this->isEnd = false;
    }
};

class Solution {
public:
    Tree * tree = new Tree();
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;    
        sort(words.begin(), words.end(), [&](const string &a, const string &b) {
            return a.size() < b.size();
        });
            
        for (auto word: words) {
            if (word.size() == 0) {
                continue;
            }

            if (dfs(word, 0)) {
                // cout << "emplace: " << word << endl;
                ans.emplace_back(word);
            } else {
                // cout << "insert: " << word << endl;
                insert(word);
            }

        }
        return ans;
    }

    bool dfs(const string &word, int start) {
        if (word.size() == start) {
            return true;
        }

        Tree *node = tree;
        for (int i = start; i < word.size(); i++) {
            char ch = word[i];
            int index = ch - 'a';
            node = node->children[index];
            if (node == nullptr) {
                return false;
            }

            if (node->isEnd) {
                if (dfs(word, i + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

    void insert(const string &word) {
        Tree *node = tree;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Tree();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
};