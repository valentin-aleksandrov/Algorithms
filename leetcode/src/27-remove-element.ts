function removeElement(nums: number[], val: number) {
  const indexesToRemove: number[] = [];

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === val) {
      indexesToRemove.push(i);
    }
  }

  indexesToRemove;
  const properOrderOfIndexesToRemove = indexesToRemove.reverse();

  properOrderOfIndexesToRemove.forEach((indexToRemove) => {
    nums.splice(indexToRemove, 1);
  });

  return nums.length;
}

// const nums = [0, 1, 2, 2, 3, 0, 4, 2];
const nums = [3, 2, 2, 3];
// const valToRemove = 2;
const valToRemove = 3;

removeElement(nums, valToRemove);
nums;
