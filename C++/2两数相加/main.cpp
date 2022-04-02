#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 初始版本
    ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode results;
        ListNode *res_ptr = &results;
        int carry = 0;
        while(1){
            int val1, val2;
            // 取值
            if(node1 != nullptr){
                val1 = node1->val;
            }
            else{
                val1 = 0;
            }
            if(node2 != nullptr){
                val2 = node2->val;
            }
            else{
                val2 = 0;
            }

            // 计算: 两个数值相加，同时需加上上一步计算的进位值
            int sum = val1 + val2 + carry;
            // 处理进位信息 （商）
            carry = (int) sum / 10;
            // 存储结果（余数）
            if(res_ptr->next == nullptr){
                res_ptr->next = new ListNode(sum % 10);
            }

            // 链表后移
            if(node1 != nullptr)
                node1 = node1->next;
            if(node2 != nullptr)
                node2 = node2->next;
            res_ptr = res_ptr->next;
            if(node1 == nullptr and node2 == nullptr){
                // 判断最后结果是否有进位，如有进位，则需存储至结果中
                if(carry > 0){
                    res_ptr->next = new ListNode(carry);
                }
                break;
            }
        }
        return results.next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 存储结果
        ListNode *results = nullptr, *res_ptr = nullptr;
        int carry = 0;
        while(true){
            int val1, val2;
            // 取值
            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;

            // 计算: 两个数值相加，同时需加上上一步计算的进位值
            int sum = val1 + val2 + carry;
            // 处理进位信息 （商）
            carry = (int) sum / 10;
            // 存储结果（余数）
            if(!results){
                // 结果初始化
                res_ptr = new ListNode(sum % 10);
                results = res_ptr;
            }else{
                // 存入新结果，同时结果指针后移
                res_ptr->next = new ListNode(sum % 10);
                res_ptr = res_ptr->next;
            }

            // 输入数据链表指针后移
            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
            // while 循环退出条件
            if(!l1 and !l2){
                // 判断最后结果是否有进位，如有进位，则需存储至结果中
                if(carry > 0){
                    res_ptr->next = new ListNode(carry);
                }
                break;
            }
        }
        return results;
    }
};

int main() {
    // 创建链表
    ListNode *l1 = nullptr, *l2 = nullptr;
    for(int i = 0; i < 7; ++i){
        l1 = new ListNode(9, l1);
    }
    for(int i = 0; i < 4; ++i){
        l2 = new ListNode(9, l2);
    }
    //遍历链表
    ListNode *ptr1 = l1;
    ListNode *ptr2 = l2;
    while(ptr1 != nullptr){
        cout << ptr1->val << " ";
        ptr1 = ptr1->next;
    }
    cout << endl;
    while(ptr2 != nullptr){
        cout << ptr2->val << " ";
        ptr2 = ptr2->next;
    }
    cout << endl;

    // 函数调用
    ListNode *res = Solution().addTwoNumbers(l1, l2);
    ListNode *ptr = res;
    while(ptr != nullptr){
        cout << "hello:";
        cout << ptr->val << endl;
        ptr = ptr->next;
    }
    return 0;
}
