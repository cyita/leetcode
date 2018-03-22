#include <vector>
#include <iostream>

using namespace std;

void quicksort(vector<int>& arr, int start, int end);
int partition(vector<int>& arr, int start, int end);
void myswap(vector<int>& arr, int i, int j);

int main(int argc, char const *argv[]) {
  int a[11] = {1,3,4,2,6,3,7,8,5,13,10};
  vector<int> arr(a, a + 11);
  quicksort(arr, 0, arr.size() - 1);
  for(int i = 0; i != arr.size(); i ++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}

void quicksort(vector<int>& arr, int start, int end){
  if(start >= end){
    return;
  } else{
    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
  }
}

int partition(vector<int>& arr, int start, int end){
  int mid = start + (end - start)/2;
  if(arr[start] > arr[mid]){
    myswap(arr, start, mid);
  }
  if(arr[start] > arr[end]){
    myswap(arr, start, end);
  }
  if(arr[mid] > arr[end]){
    myswap(arr, mid, end);
  }

  myswap(arr, mid, end - 1);

  if(end - start < 3){
    return mid;
  }

  int pivot = arr[end - 1];

  int i = start + 1;
  int j = end - 2;

  while(i < j){
    while(pivot > arr[i]){
      i ++;
    }

    while(pivot < arr[j]){
      j --;
    }

    if(i < j){
      myswap(arr, i, j);
    }
  }

  myswap(arr, i, end - 1);
  return i;
}

void myswap(vector<int>& arr, int i, int j){
  int temp = arr[j];
  arr[j] = arr[i];
  arr[i] = temp;
}
