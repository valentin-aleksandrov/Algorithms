import { findMinArrowShots } from "./minimum-number-of-arrows-to-burst-balloons";

describe("Minimum Number of Arrows to Burst Balloons", () => {
  it("should the minimum amount of unique numbers that are included in each sub array", () => {
    expect(
      findMinArrowShots([
        [10, 16],
        [2, 8],
        [1, 6],
        [7, 12],
      ]),
    ).toBe(2);
    expect(
      findMinArrowShots([
        [1, 2],
        [3, 4],
        [5, 6],
        [7, 8],
      ]),
    ).toBe(4);
    expect(
      findMinArrowShots([
        [1, 2],
        [2, 3],
        [3, 4],
        [4, 5],
      ]),
    ).toBe(2);
  });
});
