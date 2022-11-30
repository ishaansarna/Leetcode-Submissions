class Solution {
public:
    int findMin(vector<int>& arr) {
        if (arr.size()==1)
            return arr[0];
        if (arr[0] < arr.back())
            return arr[0];
        int beg = 0;
        int end = arr.size()-1;
        int mid = beg + (end-beg)/2;
        while (mid > 0) {
            if (arr[mid] < arr[mid-1])
                return arr[mid];
            else if (arr[mid] > arr[end])
                beg = mid+1;
            else if (arr[mid] < arr[end])
                end = mid-1;
            mid = beg + (end-beg)/2;
        }
        if (mid == 0) {
            if (arr[0] > arr[1])
                return arr[1];
            return arr[0];
        }
        return -1;
    }
};