// 393. UTF-8 编码验证
// 给定一个表示数据的整数数组 data ，返回它是否为有效的 UTF-8 编码。

// UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：

// 对于 1 字节 的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。
// 对于 n 字节 的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，后面字节的前两位一律设为 10 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。
// 这是 UTF-8 编码的工作方式：

//    Char. number range  |        UTF-8 octet sequence
//       (hexadecimal)    |              (binary)
//    --------------------+---------------------------------------------
//    0000 0000-0000 007F | 0xxxxxxx
//    0000 0080-0000 07FF | 110xxxxx 10xxxxxx
//    0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
//    0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
// 注意：输入是整数数组。只有每个整数的 最低 8 个有效位 用来存储数据。这意味着每个整数只表示 1 字节的数据。

 

// 示例 1：

// 输入：data = [197,130,1]
// 输出：true
// 解释：数据表示字节序列:11000101 10000010 00000001。
// 这是有效的 utf-8 编码，为一个 2 字节字符，跟着一个 1 字节字符。
// 示例 2：

// 输入：data = [235,140,4]
// 输出：false
// 解释：数据表示 8 位的序列: 11101011 10001100 00000100.
// 前 3 位都是 1 ，第 4 位为 0 表示它是一个 3 字节字符。
// 下一个字节是开头为 10 的延续字节，这是正确的。
// 但第二个延续字节不以 10 开头，所以是不符合规则的。
 

// 提示:

// 1 <= data.length <= 2 * 104
// 0 <= data[i] <= 255
// 通过次数20,167提交次数48,322

class Solution {
public:
    bool judgeSub(int data) {
        if ( (data & 0xc0) != 0x80 )
            return false;

        return true;
    }

    int getLen(int data) {
        if (data >= 0 && data <= 0x7f) {
            return 1;
        } else if (data >= 0xc0 && data <= 0xdf) {
            return 2;
        } else if (data >= 0xe0 && data <= 0xef) {
            return 3;
        } else if (data >= 0xf0 && data <= 0xf7) {
            return 4;
        }
        return 5;
    }

    bool validUtf8(vector<int>& data) {

        int m = data.size();
        int idx = 0;

        while (idx < m) {
            int len = getLen(data[idx]);

            switch (len) {
                case 1:
                    idx++;
                    break;
                case 2:
                    if (idx+1 >= m) return false;
                    if (!judgeSub(data[idx+1])) return false;
                    idx += 2;
                    break;
                case 3:
                    if (idx+2 >= m) return false;
                    if (!judgeSub(data[idx+1]) || !judgeSub(data[idx+2])) return false;
                    idx += 3;
                    break;
                case 4:
                    if (idx+3 >= m) return false;
                    if (!judgeSub(data[idx+1]) || !judgeSub(data[idx+2]) || !judgeSub(data[idx+3]) ) return false;
                    idx += 4;
                    break;
                default:
                    // cout << len << endl;
                    return false;
            }
        }
        
        return true;
    }
};
