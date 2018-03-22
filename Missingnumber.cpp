#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        unsigned int sum = 0;

        for(int i = 0; i != length; i ++){
            sum += 1<<nums[i];
        }

        // for(int i = 0; i != length; i ++){
        //
        // }
        cout << "sum " << sum << endl;

        unsigned int k = 1;
        for(int i = 0; i != length + 1; i ++){
            cout << "sum k " << (sum & k) << endl;
            if((sum & k) == 0){
                return i;
            }
            cout << k << endl;
            k<<=1;
        }

        return -1;
    }
};
int main(int argc, char const *argv[]) {
  Solution test;
  std::vector<int> v;
  v.push_back(0);
  cout << test.missingNumber(v) << endl;
  return 0;
}
