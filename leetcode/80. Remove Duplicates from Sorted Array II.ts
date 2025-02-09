function removeDuplicates(array: number[]): number {
  const nums: (number | undefined)[] = [...array];
  const numsMap = {};
  for (let index = 0; index < nums.length; index++) {
    const element = nums[index];

    if (element !== undefined && numsMap[element] === 1) {
      nums[index] = undefined;
    } else {
      if (numsMap[element!] === undefined) {
        numsMap[element!] = 0;
      } else {
        numsMap[element!] = 1;
      }
    }
  }

  for (let index = nums.length - 1; index > 0; index--) {
    if (nums[index] === undefined) {
      array.splice(index, 1);
    }
  }

  return array.length;
}

// const input = [0, 0, 1, 1, 1, 1, 2, 3, 3];
const input = [0, 0, 0, 0, 0];

const result = removeDuplicates(input);
