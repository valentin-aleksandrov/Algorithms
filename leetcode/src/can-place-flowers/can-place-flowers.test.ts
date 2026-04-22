import { canPlaceFlowers } from "./can-place-flowers";

describe("Can Place Flowers", () => {
  it("Should determine if flowers can be place", () => {
    expect(canPlaceFlowers([0, 0, 0, 0, 0], 5)).toBe(false);

    expect(canPlaceFlowers([1, 1, 1], 0)).toBe(true);

    expect(canPlaceFlowers([0], 1)).toBe(true);
    expect(canPlaceFlowers([1], 1)).toBe(false);

    expect(canPlaceFlowers([0, 0, 1], 1)).toBe(true);
    expect(canPlaceFlowers([0, 0, 1], 2)).toBe(false);

    expect(canPlaceFlowers([1, 0, 0], 1)).toBe(true);
    expect(canPlaceFlowers([1, 0, 0], 2)).toBe(false);

    expect(canPlaceFlowers([1, 0, 0, 0, 1], 1)).toBe(true);
    expect(canPlaceFlowers([1, 0, 0, 0, 1], 2)).toBe(false);

    expect(canPlaceFlowers([1, 0, 0, 0, 0, 1], 1)).toBe(true);
    expect(canPlaceFlowers([1, 0, 0, 0, 0, 1], 2)).toBe(false);

    expect(canPlaceFlowers([1, 0, 0, 0, 0, 0, 1], 1)).toBe(true);
    expect(canPlaceFlowers([1, 0, 0, 0, 0, 0, 1], 2)).toBe(true);
    expect(canPlaceFlowers([1, 0, 0, 0, 0, 0, 1], 3)).toBe(false);
  });
});
