import { rotate } from "../src/189. Rotate Array";

describe("Rotate Array", () => {
  it("should rotate by 3 steps", () => {
    const nums = [1, 2, 3, 4, 5, 6, 7];
    const k = 3;
    rotate(nums, k);
    expect(nums).toEqual([5, 6, 7, 1, 2, 3, 4]);
  });

  it("should rotate by 2 steps", () => {
    const nums = [1, 2, 3, 4, 5, 6, 7];
    const k = 3;
    rotate(nums, k);
    expect(nums).toEqual([5, 6, 7, 1, 2, 3, 4]);
  });

  it("should rotate by 4 steps", () => {
    const nums = [2147483647, -2147483648, 33, 219, 0];
    const k = 4;
    rotate(nums, k);
    expect(nums).toEqual([-2147483648, 33, 219, 0, 2147483647]);
  });
});
