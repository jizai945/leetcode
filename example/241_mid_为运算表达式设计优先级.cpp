// 241. 为运算表达式设计优先级
// 给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。

// 生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。

 

// 示例 1：

// 输入：expression = "2-1-1"
// 输出：[0,2]
// 解释：
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// 示例 2：

// 输入：expression = "2*3-4*5"
// 输出：[-34,-14,-10,-10,10]
// 解释：
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
 

// 提示：

// 1 <= expression.length <= 20
// expression 由数字和算符 '+'、'-' 和 '*' 组成。
// 输入表达式中的所有整数值在范围 [0, 99] 


class Solution {
public:
    const int ADDITION = -1;
    const int SUBTRACTION = -2;
    const int MULTIPLICATION = -3;

    vector<int> diffWaysToCompute(string expression) {
        vector<int> ops;
        for (int i = 0; i < expression.size();) {
            if (!isdigit(expression[i])) {
                if (expression[i] == '+') {
                    ops.push_back(ADDITION);
                } else if (expression[i] == '-') {
                    ops.push_back(SUBTRACTION);
                } else {
                    ops.push_back(MULTIPLICATION);
                }
                i++;
            } else {
                int t = 0;
                while (i < expression.size() && isdigit(expression[i])) {
                    t = t * 10 + expression[i] - '0';
                    i++;
                }
                ops.push_back(t);
            }
        }
        vector<vector<vector<int>>> dp((int) ops.size(), vector<vector<int>>((int) ops.size()));
        for (int i = 0; i < ops.size(); i += 2) {
            dp[i][i] = {ops[i]};
        }
        for (int i = 3; i <= ops.size(); i++) {
            for (int j = 0; j + i <= ops.size(); j += 2) {
                int l = j;
                int r = j + i - 1;
                for (int k = j + 1; k < r; k += 2) {
                    auto& left = dp[l][k - 1];
                    auto& right = dp[k + 1][r];
                    for (auto& num1 : left) {
                        for (auto& num2 : right) {
                            if (ops[k] == ADDITION) {
                                dp[l][r].push_back(num1 + num2);
                            }
                            else if (ops[k] == SUBTRACTION) {
                                dp[l][r].push_back(num1 - num2);
                            }
                            else if (ops[k] == MULTIPLICATION) {
                                dp[l][r].push_back(num1 * num2);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][(int) ops.size() - 1];
    }
};

