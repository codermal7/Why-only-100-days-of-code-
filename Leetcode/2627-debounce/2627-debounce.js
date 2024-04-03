/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let executionTime = 0
    let ref

    return function(...args) {
        const currentTime = Date.now()
        if (currentTime <= executionTime) clearTimeout(ref)
        executionTime = currentTime + t
        
        ref = setTimeout(() => {
            return fn(...args)
        }, t)
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */