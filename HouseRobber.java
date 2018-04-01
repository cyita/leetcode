class Solution {
    public int rob(int[] nums) {
        int size = nums.length;
        if(size == 0){
            return 0;
        }
        int[][] maxArray = new int[size][size];
        
        return maxMoney(maxArray, nums, 0, size - 1);
    }
    
    public int maxMoney(int[][] maxArray, int[] nums, int start, int end){
        if(start > end){
            return 0;
        }
        
        if(maxArray[start][end] != 0){
            return maxArray[start][end];
        }
        
        if(start == end){
            maxArray[start][end] = nums[start];
            return nums[start];
        } else if(end - start == 1){
            int max = nums[start] > nums[end] ? nums[start] : nums[end];
            maxArray[start][end] = max;
            return max;
        } else{
            int mid = (start + end)/2;
            int midIncludeAfter = maxMoney(maxArray, nums, start, mid - 2) + maxMoney(maxArray, nums, mid, end);
            int midNotInclude = maxMoney(maxArray, nums, start, mid - 1) + maxMoney(maxArray, nums, mid + 1, end);
            int midIncludeFront = maxMoney(maxArray, nums, start, mid) + maxMoney(maxArray, nums, mid + 2, end);
            
            int max = midIncludeAfter > midNotInclude ? midIncludeAfter : midNotInclude;
            max = max > midIncludeFront ? max : midIncludeFront;
            maxArray[start][end] = max;
            return max;
        }
    }
}