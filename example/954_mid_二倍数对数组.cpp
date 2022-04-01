// 954. 二倍数对数组
// 给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足 “对于每个 0 <= i < len(arr) / 2，都有 arr[2 * i + 1] = 2 * arr[2 * i]” 时，返回 true；否则，返回 false。

 

// 示例 1：

// 输入：arr = [3,1,3,6]
// 输出：false
// 示例 2：

// 输入：arr = [2,1,2,6]
// 输出：false
// 示例 3：

// 输入：arr = [4,-2,2,-4]
// 输出：true
// 解释：可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]
 

// 提示：

// 0 <= arr.length <= 3 * 104
// arr.length 是偶数
// -105 <= arr[i] <= 105

class cmp {
  bool operator() (const int &a, const int &b) {
      return abs(a) < abs(b);
  }  
};

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        vector<int> buf;
        unordered_map<int, int>mp;
        int tmp;

        for (auto a: arr) {
            mp[a]++;
            if (mp[a] > 1) continue;
            buf.emplace_back(a);
        }

        sort(buf.begin(), buf.end(), [](int a, int b){
            return abs(a) < abs(b);
        });

        for (auto b: buf) {
            if (mp[b*2] < mp[b]) {
                return false;
            }

            mp[b*2] -= mp[b];
            mp[b] = 0;
            
        }

        return true;

    }
};
