#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

struct point{
  int x;
  int y;
  point(int a, int b) : x(a), y(b){}
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();

        vector<point*> points;

        for(int i = 0; i != length; i ++){
          point* thisPoint = new point(i, height[i]);
          points.push_back(thisPoint);
        }

        quicksort(points, 0, points.size() - 1);

        int maxArea = 0;
        int area = 0;
        int width = 0;

        int min[50000];
        int max[50000];

        memset(min, 0, sizeof(min));
        memset(max, 0, sizeof(max));

        int minInt = points[length - 1] -> x;
        int maxInt = points[length - 1] -> x;

        for(int i = length - 1; i != -1; i --){
            if(minInt > points[i] -> x){
                minInt = points[i] -> x;
            } else if(maxInt < points[i] -> y){
                maxInt = points[i] -> x;
            }
            min[i] = minInt;
            max[i] = maxInt;
        }

        for(int i = 0; i != length - 1; i ++){
          width = abs(min[i + 1] - points[i] -> x) > abs(max[i + 1] - points[i] -> x) ? abs(min[i + 1] - points[i] -> x):abs(max[i + 1] - points[i] -> x);
          area = points[i]->y * width;
          maxArea = maxArea < area ? area : maxArea;
        }

        return maxArea;
    }

    void quicksort(vector<point*> arr, int p, int r){
      if(p < r){
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
      }
    }

    int partition(vector<point*> arr, int p, int r){
    //   int pivot = arr[r]->y;
      int center = (p + r)/2;

      int pivot = 0;

      if(arr[center ] < arr[p]){
          swap(*arr[center], *arr[p]);
      }
      if(arr[r] < arr[p]){
          swap(*arr[p], *arr[r]);
      }
      if(arr[center] > arr[r]){
          swap(*arr[center], *arr[r]);
      }

      swap(*arr[center], *arr[r - 1]);

      pivot = arr[r - 1] -> y;

      int i = p - 1;

      for(int j = p; j != r - 1; j ++){
        if(arr[j] -> y <=  pivot){
          i = i + 1;
          swap(*arr[i], *arr[j]);
        }
      }

      i ++ ;
      swap(*arr[i], *arr[r - 1]);

      return i;
    }

    void swap(point &a, point &b){
      point temp = b;
      b = a;
      a = temp;
    }
};

int main(int argc, char const *argv[]) {
  Solution test;
  vector<int> lines;
  lines.push_back(1);
  lines.push_back(1);
  lines.push_back(2);
  lines.push_back(3);
  lines.push_back(5);
  lines.push_back(4);
  int result = test.maxArea(lines);
  cout << result << endl;
  return 0;
}
