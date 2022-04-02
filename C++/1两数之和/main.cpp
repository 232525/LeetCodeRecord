#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum_1(vector<int>& nums, int target) {
        vector<int> _res;
        for(vector<int>::iterator i=nums.begin(); i!=nums.end(); ++i){
            int _target = target - *i;
            bool _get_res = false;
            for(vector<int>::iterator j=nums.begin(); j!=nums.end(); ++j){
                if(j == i){
                    continue;
                }else{
                    if(_target == *j){
                        int _res1 = i - nums.begin();
                        int _res2 = j - nums.begin();
                        _res.push_back(_res1);
                        _res.push_back(_res2);
                        _get_res = true;
                        break;
                    }
                }
            }
            if(_get_res)
                break;
        }
        return _res;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        // 存储已遍历数据
        map<int, int> _left_data;
        // 结果
        vector<int> _res;
        // 一层循环
        for(vector<int>::iterator i=nums.begin(); i!=nums.end(); ++i){
            int _num2 = target - *i;  // _num2 = 目标值 - 当前遍历值
            if(_left_data.count(_num2) > 0){
                _res.push_back(_left_data[_num2]);
                _res.push_back(i - nums.begin());
                break;
            }
            _left_data[*i] = (i - nums.begin());
        }
        return _res;
    }
};

int main() {
    Solution *a = new Solution();
    vector<int> nums{2,7,11,15};
    // vector<int> nums(20, 1);
    vector<int> _res = a->twoSum(nums, 9);
    cout << _res.size() << endl;
    for(vector<int>::iterator i=_res.begin(); i!=_res.end(); ++i){
        cout << *i << endl;
    }
    return 0;
}
