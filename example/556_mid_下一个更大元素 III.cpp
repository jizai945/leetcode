// 556. 下一个更大元素 III
// 给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。如果不存在这样的正整数，则返回 -1 。

// 注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。

 

// 示例 1：

// 输入：n = 12
// 输出：21
// 示例 2：

// 输入：n = 21
// 输出：-1
 

// 提示：

// 1 <= n <= 231 - 1
// 通过次数21,361提交次数63,542

class Solution {
public:
    int getLessBig(priority_queue<int> pq, int n) {
        int ans = 0;
        while (!pq.empty()) {
            if (pq.top() > n) {
                ans = pq.top();
            } else break;
            pq.pop();
        }

        return ans;
    }

    int getLen(int n) {
        int ans = 0;
        while (n) {
            ans++;
            n /= 10;
        }

        return ans;
    }

    bool isBigMaxInt(int n, int current) {
        long nums = (long)current * 10 + n;
        // cout << current << " " <<  nums << endl;
        
        return nums <= INT_MAX;
    }

    int nextGreaterElement(int n) {
        int tmp = n;
        int len = getLen(n);
        priority_queue<int, vector<int>> bq;
        priority_queue<int, vector<int>, greater<int>> lq;

        int idx = 0, lessCache;
        while (tmp) {
            // cout << tmp << endl;
            int t = tmp % 10;
            bq.push(t);
            
            if (bq.top() > t) {
                // cout << " ========== " << tmp << endl;
                lessCache = getLessBig(bq, t);
                break;
            }
            
            tmp /= 10;
            idx++;  
        }

        if (tmp == 0) return -1;
        int flag = 1;
        // cout << idx << endl;
        vector<int> arr;
        while (!bq.empty()) {
            if (flag && bq.top() == lessCache) {
                flag = 0;
                arr.push_back(lessCache);
            } else {
                lq.push(bq.top());
            }
            bq.pop();
        }

        while (!lq.empty()) {
            arr.push_back(lq.top());
            lq.pop();
        }

        int ans = n;
        for (int i = 0; i <= idx; i++) {
            ans /= 10;    
        }

        int int_len = getLen(INT_MAX);
        for (int i = 0; i < arr.size(); i++) {
            if (len == int_len && isBigMaxInt(arr[i], ans) == false) return -1;
            ans = ans * 10 + arr[i];
        }

        return ans;

    }
};
