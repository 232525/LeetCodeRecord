#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    // 思路：滑动窗口，右坐标遍历更新，左坐标根据是否存在重复进行滑动更新
    int lengthOfLongestSubstring_1(string s) {
        // 字符下标数据
        map<char, int> char_dict;
        // 子串左右下标
        int left_indx=0, right_indx=0;
        // 最终结果和临时结果（当前子串的长度）
        int result=0;
        int tmp_result=0;
        // 遍历字符串 s
        int s_lenght = s.length();
        for(int i=0; i < s_lenght; ++i){
            char c = s[i];
            if(!char_dict.count(c)){
                char_dict[c] = i;
            }
            // 获取当前子串 substr(begin_pos, length)
            string sub_s = s.substr(left_indx, right_indx - left_indx);
            // 查找重复字符c在该子串中出现的位置，其在完整字符串中的位置为 left_indx + pos
            auto pos = sub_s.rfind(c);
            // 找到子串中字符c的位置后，对整个字符串中字符c的位置进行更新
            char_dict[c] = i;
            if(pos == string::npos){
                // 当前字符在子串中无重复，则右下标+1
                right_indx += 1;
                tmp_result += 1;
            }else{
                // 当前字符在子串中存在重复，则重新调整左下标（重复字符后一个字符）和右下标（+1）
                // 需要计算当前字符在完整字符串中的位置 left_indx + pos
                left_indx = left_indx + pos + 1;
                right_indx += 1;
                // 出现重复时，则需要进行当前子串长度与结果对比，以判断是否更新result
                result = tmp_result > result ? tmp_result : result;
                // 更新新一轮子串长度结果
                tmp_result = right_indx - left_indx;
            }
        }
        result = tmp_result > result ? tmp_result : result;
        return result;
    }

    int lengthOfLongestSubstring(string s) {
        // 字符下标数据
        map<char, int> char_dict;
        // 子串左下标，右下标即为遍历过程中的下标
        string sub_s;
        int left_indx=0;
        // 最终结果和临时结果（当前子串的长度）
        int result=0;
        int tmp_result=0;
        // 遍历字符串 s
        int s_lenght = s.length();
        for(int right_indx=0; right_indx < s_lenght; ++right_indx){
            char c = s[right_indx];
            if(!char_dict.count(c)){
                char_dict[c] = right_indx;
            }
            // 获取当前子串 substr(begin_pos, length)
            // [c0, c1, c2, c3, ..., ck, c]，即当前字符 c 之前[c0, c1, c2, c3, ..., ck]串的长度
            sub_s = s.substr(left_indx, right_indx - left_indx);
            // 查找重复字符c在该子串中出现的位置，其在完整字符串中的位置为 left_indx + pos
            auto pos = sub_s.rfind(c);
            // 找到子串中字符c的位置后，对整个字符串中字符c的位置进行更新
            char_dict[c] = right_indx;
            if(pos == string::npos){
                // 当前字符在子串中无重复，则tmp_result + 1
                tmp_result += 1;
            }else{
                // 当前字符 c 在子串中存在重复，则重新调整左下标
                // 需要计算当前字符在完整字符串中的位置 left_indx + pos
                left_indx = left_indx + pos + 1;   // （重复字符c的后一个字符的下标）
                // 出现重复时，则需要进行当前子串长度与结果对比，以判断是否更新result
                result = tmp_result > result ? tmp_result : result;
                // 更新新一轮子串的临时长度
                tmp_result = right_indx - left_indx + 1;
            }
        }
        // 输出结果前进行比较
        result = tmp_result > result ? tmp_result : result;
        return result;
    }
};

int main() {
    // string s = "abcabcbb";
    // string s = "bbbbbbb";
    // string s = "kwkkeww";
    // string s = "dvdf";
    string s = "abcdaef";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}
