// 794. 有效的井字游戏
// 给你一个字符串数组 board 表示井字游戏的棋盘。当且仅当在井字游戏过程中，棋盘有可能达到 board 所显示的状态时，才返回 true 。

// 井字游戏的棋盘是一个 3 x 3 数组，由字符 ' '，'X' 和 'O' 组成。字符 ' ' 代表一个空位。

// 以下是井字游戏的规则：

// 玩家轮流将字符放入空位（' '）中。
// 玩家 1 总是放字符 'X' ，而玩家 2 总是放字符 'O' 。
// 'X' 和 'O' 只允许放置在空位中，不允许对已放有字符的位置进行填充。
// 当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
// 当所有位置非空时，也算为游戏结束。
// 如果游戏结束，玩家不允许再放置字符。
 

// 示例 1：


// 输入：board = ["O  ","   ","   "]
// 输出：false
// 解释：玩家 1 总是放字符 "X" 。
// 示例 2：


// 输入：board = ["XOX"," X ","   "]
// 输出：false
// 解释：玩家应该轮流放字符。
// 示例 3：


// 输入：board = ["XXX","   ","OOO"]
// 输出：false
// Example 4:


// 输入：board = ["XOX","O O","XOX"]
// 输出：true

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x_num = 0, o_num = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    x_num++;
                } else if (board[i][j] == 'O') {
                    o_num++;
                }
            }
        }

        if (o_num > x_num || x_num > (o_num + 1)) {
            return false;
        }

        int xx = 0, yy = 0;
        if (board[0] == "XXX" || board[1] == "XXX" || board[2] == "XXX" ||
        (board[0][0] == 'X' && board[1][1] == 'X' &&board[2][2] == 'X' )||
        (board[0][2] == 'X' && board[1][1] == 'X' &&board[2][0] == 'X' )||
        (board[0][0] == 'X' && board[1][0] == 'X' &&board[2][0] == 'X' )||
         (board[0][1] == 'X' && board[1][1] == 'X' &&board[2][1] == 'X' )||
         (board[0][2] == 'X' && board[1][2] == 'X' &&board[2][2] == 'X' )) {
             xx = 1;
        }

       if (board[0] == "OOO" || board[1] == "OOO" || board[2] == "OOO" ||
        (board[0][0] == 'O' && board[1][1] == 'O' &&board[2][2] == 'O' )||
        (board[0][2] == 'O' && board[1][1] == 'O' &&board[2][0] == 'O' )||
        (board[0][0] == 'O' && board[1][0] == 'O' &&board[2][0] == 'O' )||
        (board[0][1] == 'O' && board[1][1] == 'O' &&board[2][1] == 'O' )||
        (board[0][2] == 'O' && board[1][2] == 'O' &&board[2][2] == 'O' )) {
            yy = 1;
        }

        if (xx && yy) {
            cout << 22<<endl;
            return false;
        }

        if (xx && !yy && x_num == o_num) {
            return false;
        }

        if (!xx && yy && x_num > o_num) {
            return false;
        }

        return true;
    }
};