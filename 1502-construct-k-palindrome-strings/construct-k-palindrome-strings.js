/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var canConstruct = function(s, k) {
    if(s.length < k) return false;
    if(s.length === k) return true;

    let mp = new Map();

    for(let val of s) {
        mp.set(val, (mp.get(val) || 0) + 1);
    }

    let odd = 0;
    for(let [key, value] of mp) {
        if(value % 2 !== 0) odd++;
    }

    return odd <= k;
};