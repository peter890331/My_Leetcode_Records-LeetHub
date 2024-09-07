class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0: return False
        x_=str(x)
        for i in range(len(x_)/2):
            if x_[i] != x_[len(x_)-1-i]:
                return False
        return True
        