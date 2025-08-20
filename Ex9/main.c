// LeetCode 33

int search(int* nums, int numsSize, int target) {
    if (numsSize == 0) return -1;
    int low = 0, high = numsSize - 1, mid, min_idx;
    if (nums[low] < nums[high]) {  
        min_idx = 0;
    } else {
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid; 
            }
        }
        min_idx = low;
        
        low = 0;
        high = numsSize - 1;
    }
   
    if (target == nums[min_idx]) {
        return min_idx;
    }
   
    else if (target > nums[min_idx] && target <= nums[high]) {
        low = min_idx + 1;
    }
    
    else {
        high = min_idx - 1;
    }
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}


