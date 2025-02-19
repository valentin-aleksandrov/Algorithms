/**
 Do not return anything, modify nums1 in-place instead.
 */
function merge(nums1: number[], m: number, nums2: number[], n: number): void {
  const result = [...nums1.slice(0, m), ...nums2.slice(0, n)].sort(
    (a, b) => a - b
  );

  nums1.splice(0, nums1.length);
  nums1.push(...result);
  result;
}

merge([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3);
merge([1], 1, [], 0);
merge([0], 0, [1], 1);
