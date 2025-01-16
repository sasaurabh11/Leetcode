/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var xorAllNums = function(nums1, nums2) {
    let n = nums1.length, m = nums2.length;

    let ans = 0;
    if(m & 1) {
        for(let val of nums1)
            ans = ans ^ val;
    }

    if(n & 1) {
        for(let val of nums2)
            ans = ans ^ val;
    }

    return ans;
};