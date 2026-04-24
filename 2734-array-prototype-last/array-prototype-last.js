/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    if(this.length === 0) return -1;
    let q = this[this.length-1];
    this.pop();
    return q;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */