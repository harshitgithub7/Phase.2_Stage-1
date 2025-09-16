class Solution:
    def maxArea(self, height: List[int]) -> int:

        left, right = 0, len(height) - 1
        max_water = 0

        while left < right:
            # Calculates width and height
            width = right - left
            h = min(height[left], height[right])
            area = width * h
            max_water = max(max_water, area)

            # Move pointer at the smaller height
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_water
