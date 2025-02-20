export function maxProfit(prices: number[]): number {
  let maxProfitValue = 0;
  let elementWithMaxValue = prices[prices.length - 1];

  for (let i = prices.length - 2; i >= 0; i--) {
    const currentElement = prices[i];
    const nextElement = prices[i + 1];
    elementWithMaxValue = Math.max(nextElement, elementWithMaxValue);
    const newPotentialMaxProfit = elementWithMaxValue - currentElement;

    maxProfitValue = Math.max(maxProfitValue, newPotentialMaxProfit);
  }
  return maxProfitValue;
}
