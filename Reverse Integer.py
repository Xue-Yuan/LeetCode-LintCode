class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        neg = x < 0
        x = abs(x)
        ret = 0
        while x:
            ret = ret * 10 + x % 10
            x /= 10
        return -ret if neg else ret