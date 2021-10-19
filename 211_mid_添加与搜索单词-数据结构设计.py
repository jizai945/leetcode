# 211. 添加与搜索单词 - 数据结构设计
# 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

# 实现词典类 WordDictionary ：

# WordDictionary() 初始化词典对象
# void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
# bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
 

# 示例：

# 输入：
# ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
# [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
# 输出：
# [null,null,null,null,false,true,true,true]

# 解释：
# WordDictionary wordDictionary = new WordDictionary();
# wordDictionary.addWord("bad");
# wordDictionary.addWord("dad");
# wordDictionary.addWord("mad");
# wordDictionary.search("pad"); // return False
# wordDictionary.search("bad"); // return True
# wordDictionary.search(".ad"); // return True
# wordDictionary.search("b.."); // return True
 

# 提示：

# 1 <= word.length <= 500
# addWord 中的 word 由小写英文字母组成
# search 中的 word 由 '.' 或小写英文字母组成
# 最多调用 50000 次 addWord 和 search
# 通过次数42,157提交次数83,987
# 请问您在哪类招聘中遇到此题？


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.son = [None for i in range(26)]
        self.end = False

class WordDictionary:

    def __init__(self):
        self.root = TreeNode('-1')

    def addWord(self, word: str) -> None:
        node = self.root
        for w in word:
            idx = ord(w) - ord('a')
            if node.son[idx] == None:
                new_node = TreeNode(w)
                node.son[idx] = new_node
                node = new_node
            else:
                node = node.son[idx]

        node.end = True

    def sub_search(self, word:str, root: TreeNode) -> bool:
        node = root
        size = len(word)
        for i in range(size):
            w = word[i]
            if w != '.':
                idx = ord(w) - ord('a')
                if node.son[idx] == None:
                    return False
                node = node.son[idx]
            else:
                for one in range(97,123):
                    if self.sub_search(chr(one) + word[i+1:], node) == True:
                        return True
                
                return False

        return node.end

    def search(self, word: str) -> bool:
        return self.sub_search(word, self.root)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)