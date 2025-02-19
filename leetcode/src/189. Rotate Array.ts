/**
 Do not return anything, modify nums in-place instead.
 */
export function rotate(nums: number[], k: number): void {
  let numberOfRotations = k;
  for (let i = nums.length - 1; numberOfRotations > 0; i--) {
    const lastElement = nums.pop();
    numberOfRotations--;
    if (lastElement !== undefined) {
      nums.unshift(lastElement);
    }
  }
}
