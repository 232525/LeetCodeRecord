#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome_1(string s) {
        int len_s = s.length();
        // 长度为1或者0，直接返回
        if(len_s < 2)
            return s;

        // 长度大于等于2
        // max_len 和 begin 用于重构结果
        int max_len = 1;
        int begin = 0;
        // 构造状态矩阵dp
        vector<vector<int>> dp(len_s, vector<int>(len_s));
        for(int i = 0; i < len_s; ++i) {
            // 单个字符为回文
            dp[i][i] = 1;
        }

        // L : 子串长度循环
        for(int L = 2; L < len_s + 1; ++L){
            // i：子串左边界；j：子串右边界
            for(int i = 0; i < len_s; ++i){
                int j = i + L - 1;
                if(j >= len_s)
                    break;

                // dp更新
                if(s[i] != s[j]) {
                    dp[i][j] = 0;
                }else{
                    if(L == 2)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i+1][j-1];
                }
                // 结果更新
                if(dp[i][j] && L > max_len){
                    max_len = L;
                    begin = i;
                }
            }
        }
        return s.substr(begin, max_len);
    }

    pair<int, int> expandAroundCenter(string s, int left, int right){
        while(left >= 0 and right < s.length() and s[left] == s[right]){
            left -= 1;
            right += 1;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int len_s = s.length();
        if(len_s < 2)
            return s;

        // > 2 时单独处理
        int begin = 0;
        int max_len = 1;
        for(int i = 0; i < len_s; ++i){
            // 奇数长度子串
            auto [left1, right1] = expandAroundCenter(s, i, i);
            if(max_len < right1 - left1 + 1){
                max_len = right1 - left1 + 1;
                begin = left1;
            }
            auto [left2, right2] = expandAroundCenter(s, i, i+1);
            if(max_len < right2 - left2 + 1){
                max_len = right2 - left2 + 1;
                begin = left2;
            }
        }
        return s.substr(begin, max_len);
    }
};

int main() {
    // string s = "eebzcrhbishfhmiminstjudrmgqbjgztrczaipwnyxywjtfvzhjblbxdjoxitjxhoxvrygpudzollkzyjspcrurtlxvopboqogpmeimnzpzlcnmmboizjtsehbraojzdmsihepphexnpmssqeimcipbzvjltywradlbwwqzozphflxzxmrnhhjmfrucswfzndchgrgabolcjwdvfetsuugpkizncpjdeclaopfjmdwmhlxcvncbprfxfompsbqdjlqplfrppzfdntfxwxspwgybvqpjkasvqhovlwprsyqdyocryqccrbsggohjjgzhxqxcmpsugnzclgcsrbpwvrxsxaejntmnpyoabkqpzqvodcobwjqxxcfmjdrteptnjlppljntpetrdjmfcxxqjwbocdovqzpqkbaoypnmtnjeaxsxrvwpbrscglcznguspmcxqxhzgjjhoggsbrccqyrcoydqysrpwlvohqvsakjpqvbygwpsxwxftndfzpprflpqljdqbspmofxfrpbcnvcxlhmwdmjfpoalcedjpcnzikpguustefvdwjclobagrghcdnzfwscurfmjhhnrmxzxlfhpzozqwwbldarwytljvzbpicmieqssmpnxehppehismdzjoarbhestjziobmmnclzpznmiempgoqobpovxltrurcpsjyzkllozdupgyrvxohxjtixojdxblbjhzvftjwyxynwpiazcrtzgjbqgmrdujtsnimimhfhsibhrczbee";
    string s = "cabbac";
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}
