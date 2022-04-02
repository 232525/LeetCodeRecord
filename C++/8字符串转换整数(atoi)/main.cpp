#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        map<char, int> nums_char;
        for(int i = 0; i < 10; ++i) {
            nums_char['0'+i] = i;
        }

        // 结果
        long long result = 0;
        bool negetive = false;
        bool begin = false;
        // 转换
        for(auto c : s){
            // begin 标志位控制
            if(!begin && c != ' '){
                begin = true;
                // 如果初始非空格位不是数字位或者符号位，则直接返回0
                if(c != '+' and c != '-' and nums_char.count(c) < 1)
                    return 0;
                // negetive 标志位控制，如果首个非空格位为符号位，读取符号后跳入下一个char即可
                if(c == '+' or c == '-') {
                    negetive = (c == '-');
                    continue;
                }
            }
            // 数字位
            if(begin) {
                if(nums_char.count(c) < 1)
                    break;
                int bit = negetive ? -nums_char[c] : nums_char[c];
                result = result * 10 + bit;
                // 越界处理
                if(negetive && result < INT_MIN) {
                    result = INT_MIN;
                    break;
                }
                if(!negetive && result > INT_MAX) {
                    result = INT_MAX;
                    break;
                }
            }
        }
        return (int)result;
    }
};

int main() {
    string s = "20000000000000000000";
    cout << Solution().myAtoi(s) << " " << endl;
    return 0;
}
