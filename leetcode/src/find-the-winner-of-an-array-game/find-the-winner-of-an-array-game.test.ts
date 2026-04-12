import { getWinner } from "./find-the-winner-of-an-array-game";

describe("Find the Winner of an Array Game", () => {
  it("should return the number that stays a winner k times in a row", () => {
    expect(getWinner([2, 1, 3, 5, 4, 6, 7], 2)).toBe(5);
    expect(getWinner([3, 2, 1], 10)).toBe(3);
    expect(getWinner([1000000, 1, 2, 3, 4, 5], 1000000000)).toBe(1000000);
  });
});
