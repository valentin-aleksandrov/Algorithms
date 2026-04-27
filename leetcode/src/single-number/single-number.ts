/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function (nums: number[]) {
  for (let i = 0; i < nums.length; i++) {
    const left = nums.slice(0, i);
    const right = nums.slice(i + 1);
    const currentNumber = nums[i];
    if (!left.includes(currentNumber) && !right.includes(currentNumber)) {
      return currentNumber;
    }
  }
  return nums[0];
};

export { singleNumber };
