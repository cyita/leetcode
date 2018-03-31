// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

// --------------------------first solution O(n^2)-----------------------------
class Solution {
    public int maxArea(int[] height) {
        int size = height.length;
        int max = 0;
        for(int i = 0; i != size -1; i ++){
            for(int j = i + 1; j != size; j ++){
                int thisArea = area(j - i, height[i], height[j]);
                max = max > thisArea ? max : thisArea;
            }
        }
        return max;
    }

    private int area(int width, int x1, int x2){
        int height = x1 > x2 ? x2 : x1;
        return width * height;
    }
}

// --------------------------second solution O(n^2)-----------------------------

class Solution {
    public int maxArea(int[] height) {
        int size = height.length;
        heightIndex[] hi = heightIndex[size];
        for(int i = 0; i != size; i ++){
            hi[i] = new heightIndex(height[i], i);
        }



        int max = 0;
        for(int i = 0; i != size -1; i ++){
            for(int j = i + 1; j != size; j ++){
                int thisArea = area(j - i, height[i], height[j]);
                max = max > thisArea ? max : thisArea;
            }
        }
        return max;
    }

    private int area(int width, int x1, int x2){
        int height = x1 > x2 ? x2 : x1;
        return width * height;
    }

    private void quickSort(heightIndex[] data){

    }

    private int partition(heightIndex[] data, int left, int right){
        int pivot = data[left].height;

        int i = left + 1;
        int j = right ;

        while(i < j){
            while(data[j].height > pivot){
                j --;
            }

            while(data[i].height <= pivot){
                i ++;
            }

            // swap
            heightIndex temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }

        heightIndex temp = data[j];
        data[j] = data[left];
        data[left] = temp;

        return j;
    }

    class heightIndex{
        int height;
        int index;
    }
}
