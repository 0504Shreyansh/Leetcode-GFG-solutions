/**
 * @param {Function} fn
 */
function memoize(fn) {
    var cache = {};
    return (...args) => cache[args]!==undefined ? cache[args] : cache[args]=fn(...args);
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */