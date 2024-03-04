/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let notorig = false;
    let ans;

    return function(...args) {
        if (!notorig) {
        ans = fn(...args);
        notorig = true;
        return ans;
        }
        return undefined;
    };
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
