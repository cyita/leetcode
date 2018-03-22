#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
      int axis1left = 0;
      int axis1right = matrix.size() - 1;
      int axis1mid = 0;
      int axis1 = 0;
      int col = matrix[0].size();

      while(axis1left <= axis1right){
          axis1mid = axis1left + (axis1right - axis1left) / 2;
          if(matrix[axis1mid][0] <= target && matrix[axis1mid][col - 1] >= target){
              axis1 = axis1mid;
              break;
          } else if(matrix[axis1mid][0] > target){
              if(axis1mid == 0){
                  return false;
              }
              axis1right = axis1mid - 1;
          } else{
              if(axis1mid == matrix.size() - 1){
                  axis1 = axis1mid;
                  break;
              }
              axis1left = axis1mid + 1;
          }
      }

      vector<int> this_row = matrix[axis1];
      int left = 0;
      int right = this_row.size() - 1;
      int mid = 0;

      while(left <= right){
          mid = (left + right) / 2;
          if(this_row[mid] == target){
              return true;
          } else if(this_row[mid] > target){
              right = mid - 1;
          } else{
              left = mid + 1;
          }
      }

      return false;
    }
};

int main(int argc, char const *argv[]) {
  vector<int> row1;
  row1.push_back(-10);
  row1.push_back(-9);
  vector<int> row2;
  row2.push_back(-6);
  row2.push_back(-5);
  vector<int> row3;
  row3.push_back(-3);
  row3.push_back(-1);
  vector<vector<int> > matrix;
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);

  Solution solution;
  bool result = solution.searchMatrix(matrix, 2);

  if(result){
    cout << "true" << endl;
  } else{
    cout <<  "false" << endl;
  }

  return 0;
}
