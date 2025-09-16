class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m; // Binary search range for nums1

        while (left <= right) {
            int partitionX = (left + right) / 2; // Partition point in nums1
            int partitionY = (m + n + 1) / 2 - partitionX; // Corresponding partition in nums2

            // Get left and right elements for both arrays
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            // Check if partitions are correct
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Found correct partition
                if ((m + n) % 2 == 0) {
                    // Even total length: average of max of left and min of right
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    // Odd total length: max of left parts
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                
                right = partitionX - 1;
            } else {
                
                left = partitionX + 1;
            }
        }

        // Should never reach here if inputs are valid
        return 0.0;
    }
};
