class Solution {
public:
    int binSearch(vector<int>& arr, int start, int end) {
        if (start >= end) {
            return start;
        }
        
        int mid = (start + end) / 2;
        
        if (mid == 0) {
            return binSearch(arr, mid + 1, end);
        }
        
        if (mid == arr.size() - 1) {
            return binSearch(arr, start, mid - 1);
        }
        
        if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {
            return binSearch(arr, mid + 1, end);
        } else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) {
            return binSearch(arr, start, mid - 1);
        } else {
            return mid;
        }
    }
    
    
    int peakIndexInMountainArray(vector<int>& arr) {
        return binSearch(arr, 0, arr.size() - 1);
    }
};