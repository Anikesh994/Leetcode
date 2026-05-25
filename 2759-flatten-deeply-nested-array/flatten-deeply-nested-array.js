/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
  if (n === 0) return arr;
  let out = [];

  const deeply = (arr, dp) => {
    arr.forEach((el) => {
      if (Array.isArray(el) && dp !== 0) {
        deeply(el, dp - 1);
      } else out.push(el);
    });
  };

  deeply(arr, n);
  return out;
};