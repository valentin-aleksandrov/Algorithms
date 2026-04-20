/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var findPoisonedDuration = function (timeSeries: number[], duration: number) {
  let counter = 0;
  let start = timeSeries.shift() ?? 0;
  let end = start + duration - 1;

  for (let i = start; ; i++) {
    if (i === timeSeries[0]) {
      start = timeSeries.shift() ?? start;
      end = start + duration - 1;
    }
    if (i >= start && i <= end) {
      counter++;
    } else if (!timeSeries.length) break;
  }

  return counter;
};

export { findPoisonedDuration };
