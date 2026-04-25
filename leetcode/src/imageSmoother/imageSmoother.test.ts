import { imageSmoother } from "./imageSmoother";

describe("Image Smoother", () => {
  it("should apply the image smoother filter on the image", () => {
    expect(imageSmoother([[0]])).toEqual([[0]]);
    expect(imageSmoother([[1]])).toEqual([[1]]);
    expect(
      imageSmoother([
        [1, 1, 1],
        [1, 0, 1],
        [1, 1, 1],
      ]),
    ).toEqual([
      [0, 0, 0],
      [0, 0, 0],
      [0, 0, 0],
    ]);
    expect(
      imageSmoother([
        [100, 200, 100],
        [200, 50, 200],
        [100, 200, 100],
      ]),
    ).toEqual([
      [137, 141, 137],
      [141, 138, 141],
      [137, 141, 137],
    ]);
  });
});
