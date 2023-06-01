/**
 * @param {number[]} nums
 */
var ArrayWrapper = function(nums) {
    this.data = nums;
};

ArrayWrapper.prototype.valueOf = function() {
    return this?.data?.reduce((prev, cur) => prev + cur, 0);
}

ArrayWrapper.prototype.toString = function() {
    return `[${this.data.join(",")}]`;
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */