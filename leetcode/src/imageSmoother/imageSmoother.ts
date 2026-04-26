/**
 * @param {number[][]} img
 * @return {number[][]}
 */
var imageSmoother = function (img: number[][]) {
  let result: number[][] = [];

  for (let i = 0; i < img.length; i++) {
    result.push([]);
    for (let j = 0; j < img[i].length; j++) {
      result[i].push(0);
    }
  }

  for (let i = 0; i < img.length; i++) {
    for (let j = 0; j < img[i].length; j++) {
      let sum = 0;
      let availableElements = 0;

      sum += img[i][j];
      availableElements++;

      if (i > 0) {
        sum += img[i - 1][j];
        availableElements++;
      }

      if (j > 0) {
        sum += img[i][j - 1];
        availableElements++;
      }

      if (i > 0 && j > 0) {
        sum += img[i - 1][j - 1];
        availableElements++;
      }

      if (i > 0 && j < img[0].length - 1) {
        sum += img[i - 1][j + 1];
        availableElements++;
      }

      if (i < img.length - 1) {
        sum += img[i + 1][j];
        availableElements++;
      }

      if (j < img[0].length - 1) {
        sum += img[i][j + 1];
        availableElements++;
      }

      if (i < img.length - 1 && j > 0) {
        sum += img[i + 1][j - 1];
        availableElements++;
      }

      if (i < img.length - 1 && j < img[0].length - 1) {
        sum += img[i + 1][j + 1];
        availableElements++;
      }

      result[i][j] = Math.floor(sum / availableElements);
    }
  }

  return result;
};

export { imageSmoother };
