class Solution(object):
    def doesValidArrayExist(self, derived):
        """
        :type derived: List[int]
        :rtype: bool
        """
        n = len(derived)
        sum = 0
        for i in range(n):
            sum += derived[i]
        return sum%2==0

# Reference from conner1231230's solution.

'''

If i = n - 1, then derived[i] = original[i] ⊕ original[0].
Otherwise, derived[i] = original[i] ⊕ original[i + 1].

derived[0] ⊕ derived[1] ⊕ ⋯ ⊕ derived[n−1] =
original[0] ⊕ original[1] ⊕ original[1] ⊕ original[2] ⊕ ⋯ ⊕ original[n−1] ⊕ original[0] = 
original[0] ⊕ original[0] ⊕ original[1] ⊕ original[1] ⊕ ⋯ ⊕ original[n−1] ⊕ original[n−1].

because a ⊕ a = 0,
so original[0] ⊕ original[0] ⊕ original[1] ⊕ original[1] ⊕ ⋯ ⊕ original[n−1] ⊕ original[n−1] = 0,
so derived[0] ⊕ derived[1] ⊕ ⋯ ⊕ derived[n−1] = 0,
so if 1 in derived is even, XOR of derived is 0, return true; else if 1 in derived is odd, XOR of derived is 1, return false.

'''