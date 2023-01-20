#Given two binary strings a and b, return their sum as a binary string.

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        sum = ""
        carry = 0
        i_a = len(a) - 1
        i_b = len(b) - 1 

        while i_a >= 0 or i_b >= 0:
            if i_a >= 0:
                carry += int(a[i_a])
            else:
                carry += int(b[i_b])

            i_a-=1
            i_b-=1
            
            sum = str(carry % 2) + sum
            carry //= 2
        
        if carry > 0:
            sum = str(carry%2) + sum

        return sum
