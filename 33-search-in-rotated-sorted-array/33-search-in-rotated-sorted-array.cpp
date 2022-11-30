class Solution {
    int findPivot(vector<int>& arr) {
        // if (arr[0] > arr[1])
        //     return 1;
        if (arr[0] < arr.back())
            return 0;
        // if (arr.back() < *(--arr.end()))
        //     return arr.size()-1;
        int beg = 0;
        int end = arr.size()-1;
        int mid = beg + (end-beg)/2;
        while (mid > 0) {
            if (arr[mid] < arr[mid-1])
                return mid;
            else if (arr[mid] > arr[end])
                beg = mid+1;
            else if (arr[mid] < arr[end])
                end = mid-1;
            mid = beg + (end-beg)/2;
        }
        if (mid == 0) {
            if (arr[0] > arr[1])
                return 1;
            return 0;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        int pivot = findPivot(nums);
        if (pivot == -1)
            return -2;
        int beg = 0;
        int end = nums.size()-1;
        if (target <= nums.back())
            beg = pivot;
        else {
            end = pivot-1;
            end = end < 0 ? nums.size()-1 : end;
        }
        int mid = beg + (end-beg)/2;
        while (beg <= end) {
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target)
                beg = mid+1;
            else if (nums[mid] >= target)
                end = mid-1;
            mid = beg + (end-beg)/2;
        }
        return -1;
    }
};