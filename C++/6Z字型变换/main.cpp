#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }

        vector<string> vecs(numRows, "");
        int idx = 1;
        int direction = 1;
        for(auto c: s){
            vecs[idx-1] += c;
            idx += direction;
            if(idx == 1 || idx == numRows){
                direction = -direction;
            }
        }
        string result = "";
        for(auto _s: vecs){
            result += _s;
        }
        return result;
    }
};

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << Solution().convert(s, numRows) << endl;
    return 0;
}
