/*
    Problem components 
        Sorted arrays
        merge the array in sorted whay
    
    Solution Ideas:
    New array solution:
        Create a new as a copy of the first array and then use two pointers
        to merge into the nums1 array 
    Time complexity:
        O(2*m+n) or simply O(m+n)
    Space complexity:
        O(m)

    Three pointers solution:
        Create a a pointer to the last elements at m+n-1 and compare to the elements
        of two other pointers nums1[m-1] and nums2[n-1].

    Time complexity:
        O(m+n)
    Space complexity:
        O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int move = m + n - 1;
        int p1 = m - 1;
        int p2 = n - 1;

        for (int p = m + n -1; p >= 0; p--){
            if (p2 < 0)
                break;

            if (p1 >= 0 and nums1[p1] > nums2[p2]) 
                nums1[move] = nums1[p1--];

            else
                nums1[move] = nums2[p2--];
        }
    }
};

