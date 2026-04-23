/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function (flowerbedParam: number[], n: number) {
  const flowerbed = [...flowerbedParam];
  if (n === 0) return true;
  if (flowerbed.length === 1) {
    return flowerbed[0] === 0 && n === 1;
  }
  if (n === flowerbed.length) return false;

  let counter = 0;

  for (let i = 0; i < flowerbed.length; i++) {
    if (i === 0 && flowerbed[i] === 0 && flowerbed[i + 1] === 0) {
      flowerbed[i] = 1;
      counter++;
    } else if (
      i === flowerbed.length - 1 &&
      flowerbed[i] === 0 &&
      flowerbed[i - 1] === 0
    ) {
      flowerbed[i] = 1;
      counter++;
    } else if (
      flowerbed.length > 2 &&
      flowerbed[i] === 0 &&
      flowerbed[i + 1] === 0 &&
      flowerbed[i - 1] === 0
    ) {
      flowerbed[i] = 1;
      counter++;
    }
  }

  return counter >= n;
};

/**
 * Notes:
 *
 * [1,0,0,0,1]
 * [1,0,1,0,1]
 *
 * [1,0,0,0,0,1]
 * [1,0,1,0,0,1] or [1,0,0,1,0,1]
 *
 * [1,0,0,0,0,0,1]
 * [1,0,1,0,1,0,1]
 */

export { canPlaceFlowers };
