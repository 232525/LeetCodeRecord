#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        // 反转
        while(x != 0){
            if (result < INT_MIN / 10 || result > INT_MAX / 10) {
                return 0;
            }
            int bit = x % 10;
            x = x / 10;
            result = result * 10 + bit;
        }
        return result;
    }
};

int main() {
    int x = -2147483648;
    cout << (int)-11 / 10 << endl;
    cout << Solution().reverse(x) << endl;
    return 0;
}
