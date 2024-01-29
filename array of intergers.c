#include <stdio.h>

int maxSubarraySum(int nums[], int size) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < size; i++) {
        currentSum = (currentSum + nums[i] > nums[i]) ? currentSum + nums[i] : nums[i];
        maxSum = (currentSum > maxSum) ? currentSum : maxSum;
    }

    return maxSum;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int nums[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubarraySum(nums, size);

    printf("Maximum sum of a contiguous subarray: %d\n", result);

    return 0;
}

