// 553. 最优除法
// 给定一组正整数，相邻的整数之间将会进行浮点除法操作。例如， [2,3,4] -> 2 / 3 / 4 。

// 但是，你可以在任意位置添加任意数目的括号，来改变算数的优先级。你需要找出怎么添加括号，才能得到最大的结果，并且返回相应的字符串格式的表达式。你的表达式不应该含有冗余的括号。

// 示例：

// 输入: [1000,100,10,2]
// 输出: "1000/(100/10/2)"
// 解释:
// 1000/(100/10/2) = 1000/((100/10)/2) = 200
// 但是，以下加粗的括号 "1000/((100/10)/2)" 是冗余的，
// 因为他们并不影响操作的优先级，所以你需要返回 "1000/(100/10/2)"。

// 其他用例:
// 1000/(100/10)/2 = 50
// 1000/(100/(10/2)) = 50
// 1000/100/10/2 = 0.5
// 1000/100/(10/2) = 2
// 说明:

// 输入数组的长度在 [1, 10] 之间。
// 数组中每个元素的大小都在 [2, 1000] 之间。
// 每个测试用例只有一个最优除法解。

class Solution {
private:
    vector<string> left_flag;
    vector<string> right_flag;
public:
    float findMin(vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];
        if (start + 1 == end) return (1.0 * nums[start] / nums[end]);

        int idx = 0;
        float min_num = FLT_MAX;
        vector<string> left_cache = left_flag;
        vector<string> right_cache = right_flag;
        for (int i = start; i < end; i++) {
            float a = findMin(nums, start, i);
            float b = findMax(nums, i+1, end);
            if (a / b < min_num) {
                idx = i;
                min_num = a / b;
            }
        }

        left_flag = left_cache;
        right_flag = right_cache;
        if (idx != end-1) {
            left_flag[idx+1] += "(";
            right_flag[end] += ")";
            // printf("min %d %d %d\n", start, end, idx); 
        }

        return min_num;
    }

    float findMax(vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];
        if (start + 1 == end) return (1.0 * nums[start] / nums[end]);

        int idx = 0;
        float max_num = -1;
        vector<string> left_cache = left_flag;
        vector<string> right_cache = right_flag;
        for (int i = start; i < end; i++) {
            float a = findMax(nums, start, i);
            float b = findMin(nums, i+1, end);
            if (a / b > max_num) {
                idx = i;
                max_num = a / b;
            }
        }
        left_flag = left_cache;
        right_flag = right_cache;
        if (idx != end-1) {
            left_flag[idx+1] += "(";
            right_flag[end] += ")";
            // printf("max %d %d %d\n", start, end, idx); 
        }
        return max_num;
    }

    string optimalDivision(vector<int>& nums) {
        int m = nums.size();
        
        left_flag = vector<string>(m, "");
        right_flag = vector<string>(m, "");
        string ans;

        findMax(nums, 0, m - 1);

        for (int i = 0; i < m; i++) {
            ans += left_flag[i] + to_string(nums[i]) + right_flag[i];
            ans += (i != m-1) ? "/" : "";
        }

        return ans;
    }
};
