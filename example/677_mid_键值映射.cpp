// 677. 键值映射
// 实现一个 MapSum 类，支持两个方法，insert 和 sum：

// MapSum() 初始化 MapSum 对象
// void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键 key 已经存在，那么原来的键值对将被替代成新的键值对。
// int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
 

// 示例：

// 输入：
// ["MapSum", "insert", "sum", "insert", "sum"]
// [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
// 输出：
// [null, null, 3, null, 5]

// 解释：
// MapSum mapSum = new MapSum();
// mapSum.insert("apple", 3);  
// mapSum.sum("ap");           // return 3 (apple = 3)
// mapSum.insert("app", 2);    
// mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 

// 提示：

// 1 <= key.length, prefix.length <= 50
// key 和 prefix 仅由小写英文字母组成
// 1 <= val <= 1000
// 最多调用 50 次 insert 和 sum
// 通过次数32,530提交次数49,240
// 请问您在哪类招聘中遇到此题？



struct ChString {
    ChString(){
        for (int i = 0; i < 26; i++) {
            sub[i] = nullptr;
            end = false;
            val = 0;
        }
    }
    ChString* sub[26];
    bool end;
    int val;
};

class MapSum {
private:
    struct ChString root;

public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        ChString* node = &root;
        int size = key.size();
        for(int i = 0; i < size; i++) {
            int index = key[i]-'a';
            if (node->sub[index] == nullptr) {
                ChString* new_node = new ChString();
                node->sub[index] = new_node;                 
            } 

            node = node->sub[index];
            if (i == (size - 1)) {
                node->end = true;
                node->val = val;
            }
            
        }
    }

    int get_sub_sum(ChString* root) {
        if (!root) return 0;
        int sum = 0;
        if (root->end) sum += root->val;

        for (int i = 0; i < 26; i++) {
            if (root->sub[i] != nullptr) {
                sum += get_sub_sum(root->sub[i]);
            }
        }

        return sum;
    }
    
    int sum(string prefix) {

        ChString* node = &root;
        int size = prefix.size();

        for(int i = 0; i < size; i++) {
            int index = prefix[i]-'a';
            if (node->sub[index] == nullptr) {
                return 0;
            } 

            node = node->sub[index];
        }
        int res = get_sub_sum(node);

        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */