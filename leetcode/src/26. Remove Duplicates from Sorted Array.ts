function doesElementExistsBesidesTheIndex(nums, index, element) {
  for (let i = 0; i < nums.length; i++) {
    if (index === i) {
      continue;
    }

    if (nums[i] === element) {
      return true;
    }
  }
}
function removeDuplicates(nums: number[]): number {
  // implementation

  const uniqueElements: number[] = [];

  uniqueElements.push(nums[0]);

  for (let i = 1; i < nums.length; i++) {
    if (!uniqueElements.includes(nums[i])) {
      uniqueElements.push(nums[i]);
    }
  }

  uniqueElements;

  for (let i = 0; i < uniqueElements.length; i++) {
    nums[i] = uniqueElements[i];
  }
  return uniqueElements.length;
}

const numbers = [1, 1, 2];

removeDuplicates(numbers);

numbers;
