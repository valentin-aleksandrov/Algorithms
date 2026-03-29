/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function (points: number[][]) {
  const sortedPoints = [...points].sort((a, b) => a[1] - b[1]);

  let counter = 1;
  let lastArrow = sortedPoints[0][1];

  for (let i = 1; i < sortedPoints.length; i++) {
    if (sortedPoints[i][0] <= lastArrow) {
      continue;
    }
    counter++;
    lastArrow = sortedPoints[i][1];
  }
  return counter;
};

export { findMinArrowShots };
