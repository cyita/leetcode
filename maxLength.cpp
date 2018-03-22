#include <vector>
#include <iostream>

using namespace std;

struct info{
    int maxLength;
    int maxVal;
    info(int ml, int mv) : maxLength(ml), maxVal(mv){}
    info() : maxLength(0), maxVal(0){}
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLength = 1;
        int length = nums.size();
        info arr[length][length];
        int thisLength = 0;
        info* thisInfo;

        for(int i = 0; i != length; i ++){
            thisInfo = new info(1, nums[i]);
            arr[i][i] = *thisInfo;
        }

        for(int i = 0; i != length; i ++){
            for(int j = i + 1; j != length; j ++){
                if(nums[j] > arr[i][j - 1].maxVal){
                    thisLength = arr[i][j - 1].maxLength + 1;
                    thisInfo = new info(thisLength, nums[j]);
                    arr[i][j] = *thisInfo;
                    maxLength = maxLength > thisLength ? maxLength : thisLength;
                } else{
                    arr[i][j] = arr[i][j - 1];
                }
            }
        }

        return maxLength;
    }
};

int main(int argc, char const *argv[]) {
  vector<int> testcase;
  for(int i = 1; i != 1500; i ++){
    testcase.push_back(i);
  }
  Solution test;
  int maxLength = test.lengthOfLIS(testcase);
  cout << maxLength << endl;
  return 0;
}
