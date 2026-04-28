import { findPoisonedDuration } from "./teemo-attacking";

describe("Teemo Attacking", () => {
  it("should the number of seconds Ashe was poisoned", () => {
    expect(findPoisonedDuration([1, 4], 2)).toBe(4);
    expect(findPoisonedDuration([1, 2], 2)).toBe(3);
    expect(findPoisonedDuration([0, 1, 2, 3, 4], 5)).toBe(9);
    expect(findPoisonedDuration([0], 10000000)).toBe(10000000);
    expect(findPoisonedDuration([1], 1)).toBe(1);
  });
});
