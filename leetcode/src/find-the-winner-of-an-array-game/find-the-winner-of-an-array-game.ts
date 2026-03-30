/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var getWinner = function (arr: number[], k: number) {
  if (k > arr.length) {
    return Math.max(...arr);
  }
  const map = new Map();
  for (const x of arr) {
    map.set(x, 0);
  }

  while (true) {
    const [first, second] = arr;

    if (first > second) {
      const newValue = map.get(first) + 1;
      map.set(first, newValue);
      arr.shift();
      arr.shift();
      arr.unshift(first);
      arr.push(second);
      if (newValue >= k) {
        return first;
      }
    } else {
      const newValue = map.get(second) + 1;
      map.set(second, newValue);
      arr.shift();
      arr.push(first);
      if (newValue >= k) {
        return second;
      }
    }
  }
};

/**
 * Notes:
 * map for every number
 * swap
 */

export { getWinner };
