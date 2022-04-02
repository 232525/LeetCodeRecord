#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome_1(int x) {
        if(x < 0)
            return false;
        // 转换为字符串进行处理
        string x_str = to_string(x);
        int left = 0, right = x_str.length() - 1;
        while(left <= right){
            if(x_str[left] != x_str[right])
                return false;
            left += 1;
            right -= 1;
        }
        return true;
    }

    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x < 10)
            return true;

        // 直接通过数字循环整除判断
        int right_x = x % 10;
        int left_x = x / 10;
        if(right_x == 0)
            return false;
        while(left_x > 0){
            int ratio = right_x / left_x;
            if(ratio > 999)
                return false;
            if(left_x == right_x)
                return true;
            if((int)left_x / 10 == right_x)
                return true;
            int bit = left_x % 10;
            right_x = right_x * 10 + bit;
            left_x = left_x / 10;
        }
        return false;
    }
};

int main() {
    int x = 1231;
    cout << Solution().isPalindrome(x) << endl;
    return 0;
}
