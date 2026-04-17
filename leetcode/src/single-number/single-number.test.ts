import { singleNumber } from "./single-number";

describe("Single Number", () => {
  it("should return the number that is not repeated", () => {
    expect(singleNumber([2, 2, 1])).toBe(1);
    expect(singleNumber([4, 1, 2, 1, 2])).toBe(4);
    expect(singleNumber([1])).toBe(1);
  });
});
