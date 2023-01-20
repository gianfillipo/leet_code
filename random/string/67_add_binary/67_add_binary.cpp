#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i_a = a.length()-1;
        int i_b = b.length()-1;

        int aval, bval, carry;
        carry=0;

        while (i_a >= 0 || i_b >= 0 || carry) {
            aval = 0;
            bval = 0;
            if (i_a >= 0)
                aval = a[i_a] - '0';
            if (i_b >= 0)
                bval = b[i_b] - '0';

            
            int sum = aval + bval + carry;
            char c = sum % 2 + '0';
            ans = c + ans;
            carry = 0;

            if (sum > 1) {
                carry = 1;
            }
            i_a--;
            i_b--;
        }

        return ans;
    }
};

