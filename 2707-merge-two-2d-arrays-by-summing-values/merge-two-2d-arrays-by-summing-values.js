/**
 * @param {number[][]} nums1
 * @param {number[][]} nums2
 * @return {number[][]}
 */
var mergeArrays = function(nums1, nums2) {
    let mp = new Map();

    for(let val of nums1) {
        mp.set(val[0], val[1]);
    }

    for(let val of nums2) {
        mp.set(val[0], (mp.get(val[0]) || 0) + val[1]);
    }

    let ans = [];
    for(let [key, value] of mp) {
        ans.push([key, value]);
    }

    return ans.sort((a, b) => a[0] - b[0]);
};