#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 时间复杂度 O(m+n)
    double findMedianSortedArrays_1(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len_sum = len1 + len2;
        vector<int> median_idx;
        if(len_sum % 2 == 0){
            median_idx.push_back((int) (len_sum-1)/2 );
            median_idx.push_back((int) (len_sum+1)/2 );
        }else{
            median_idx.push_back((int) (len_sum-1)/2 );
        }

        // 部分数据进行排序
        // vector<int> sorted_nums(2,0);     // 存储排序的所有数据
        vector<int> sorted_nums(2,0);  // 只存储两个数据
        int cnt = 0;
        int idx1 = 0;
        int idx2 = 0;
        while(true){
            // if(sorted_nums.size() >= *(median_idx.end()-1) + 1) {
            if(cnt >= *(median_idx.end()-1) + 1){
                break;
            }
            cnt += 1;
            cout << cnt << endl;
            cout << sorted_nums[0] << " " << sorted_nums[1] << endl;
            // 边界条件
            if(idx1 < len1 && idx2 < len2){
                if(nums1[idx1] < nums2[idx2]) {
                    // sorted_nums.push_back(nums1[idx1]);
                    sorted_nums[0] = sorted_nums[1];
                    sorted_nums[1] = nums1[idx1];
                    idx1 += 1;
                }else{
                    // sorted_nums.push_back(nums2[idx2]);
                    sorted_nums[0] = sorted_nums[1];
                    sorted_nums[1] = nums2[idx2];
                    idx2 += 1;
                }
            }else if(idx1 >= len1 && idx2 < len2){
                // sorted_nums.push_back(nums2[idx2]);
                sorted_nums[0] = sorted_nums[1];
                sorted_nums[1] = nums2[idx2];
                idx2 += 1;
            }else if(idx1 < len1 && idx2 >= len2){
                // sorted_nums.push_back(nums1[idx1]);
                sorted_nums[0] = sorted_nums[1];
                sorted_nums[1] = nums1[idx1];
                idx1 += 1;
            }else{
                break;
            }
        }
        // 计算中位数
        /*
        for(int idx : median_idx){
            result += sorted_nums[idx];
        }
        result /= median_idx.size();
         */

        double result=0.;
        if(median_idx.size() == 2){
            result += (sorted_nums[0] + sorted_nums[1]);
            result /= 2;
        } else {
            result += sorted_nums[1];
            result /= 1;
        }
        return result;
    }

    // 如果要达到时间复杂度O(log(m+n))的要求，则需要使用二分法
    int getKthElement(int k, vector<int>& nums1, vector<int>& nums2){
        int len1(nums1.size()), len2(nums2.size());
        int idx1(0), idx2(0);
        int new_idx1(0), new_idx2(0);
        while(true){
            // 特殊情况（边界条件），用于退出while循环
            if(idx1 == len1){
                return nums2[idx2 + k - 1];
            }
            if(idx2 == len2){
                return nums1[idx1 + k - 1];
            }
            if(k == 1){
                // return nums1[idx1] < nums2[idx2] ? nums1[idx1] : nums2[idx2];
                return min(nums1[idx1], nums2[idx2]);
            }

            // 一般情况
            // 不能越界！！！因为是下标，所以需要 -1
            new_idx1 = (int) min(idx1 + k / 2 - 1, len1 - 1);
            new_idx2 = (int) min(idx2 + k / 2 - 1, len2 - 1);
            /*
            if(nums1[new_idx1] <= nums2[new_idx2]){
                // 更新k值
                k = k - (new_idx1 - idx1 + 1);
                // 更新idx1
                idx1 = new_idx1 + 1;
            } else {
                // 更新k值
                k = k - (new_idx2 - idx2 + 1);
                // 更新idx2
                idx2 = new_idx2 + 1;
            }
             */
            if(nums1[new_idx1] < nums2[new_idx2]){
                // 更新k值
                k = k - (new_idx1 - idx1 + 1);
                // 更新idx1
                idx1 = new_idx1 + 1;
            } else if(nums1[new_idx1] > nums2[new_idx2]) {
                // 更新k值
                k = k - (new_idx2 - idx2 + 1);
                // 更新idx2
                idx2 = new_idx2 + 1;
            } else {
                k = k - (new_idx1 - idx1 + 1) - (new_idx2 - idx2 + 1);
                if(k == 0) {
                    return nums1[new_idx1];
                }
                else{
                    idx1 = new_idx1 + 1;
                    idx2 = new_idx2 + 1;
                }
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        // length
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len_sum = len1 + len2;
        int k = (int)(len_sum - 1) / 2 + 1;

        if(len_sum % 2 != 0){
            result = getKthElement(k, nums1, nums2);
        } else {
            result = (getKthElement(k, nums1, nums2) + getKthElement(k+1, nums1, nums2) ) / 2.;
        }
        return result;
    }
};

int main() {
    // vector<int> nums1{1,2,3,4};
    // vector<int> nums2{3,4,5};
    // vector<int> nums1{2};
    // vector<int> nums2{};
    // vector<int> nums1{2,3,4,5,6};
    // vector<int> nums2{1};
    vector<int> nums1{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
    vector<int> nums2{0,6};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
