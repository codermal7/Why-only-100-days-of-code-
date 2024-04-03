/**
 * @param {Function} fn
 * @return {Object}
 */

Array.prototype.groupBy = function(fn) {
    const ans = {};
   for (let ele of this) {
        const temp = fn(ele);
        ans[temp]?ans[temp].push(ele): ans[temp] = [ele];
    }
    return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */