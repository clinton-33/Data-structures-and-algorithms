#include <stdio.h>


int removeDuplicates(int nums[], int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}

void rotate(int nums[], int numsSize, int k) {
    k = k % numsSize;

    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

void reverse(int nums[], int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

int containsDuplicate(int nums[], int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return 1;
            }
        }
    }

    return 0;
}

int singleNumber(int nums[], int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    int nums1[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int newLength = removeDuplicates(nums1, numsSize1);

    printf("Q1 - New array: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");
    int nums2[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int k = 3;
    rotate(nums2, numsSize2, k);

    printf("Q2 - Rotated array: ");
    for (int i = 0; i < numsSize2; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");
    int nums3[] = {1, 2, 3, 4, 5, 6};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    if (containsDuplicate(nums3, numsSize3)) {
        printf("Q3 - The array contains duplicates.\n");
    } else {
        printf("Q3 - The array does not contain duplicates.\n");
    }
    int nums4[] = {4, 2, 3, 2, 3};
    int numsSize4 = sizeof(nums4) / sizeof(nums4[0]);
    int single = singleNumber(nums4, numsSize4);

    printf("Q4 - The single number is: %d\n", single);

    return 0;
}
