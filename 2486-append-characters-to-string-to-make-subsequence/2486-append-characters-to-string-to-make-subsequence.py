class Solution(object):
    def appendCharacters(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        s_ = len(s)
        t_ = len(t)
        i = 0
        j = 0
        while i < s_:
            if j < t_ and s[i] == t[j]:
                i+=1
                j+=1
            else:
                i+=1
        return t_ - j