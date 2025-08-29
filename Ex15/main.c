int minPairSum(int* nums, int numsSize){
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < numsSize / 2; i++) {
        int sum = nums[i] + nums[numsSize - 1 - i];
        if (sum > ans) ans = sum;
    }

    return ans;
}

// ex 1877