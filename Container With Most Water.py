class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        b, e, l = 0, len(height)-1, len(height)-1
        ret = 0
        while b < e:
            if height[b] < height[e]:
                ret = max(ret, height[b] * l)
                b += 1
            else:
                ret = max(ret, height[e] * l)
                e -= 1
            l -= 1
        return ret
