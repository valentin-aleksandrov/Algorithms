export function maxProfit(prices: number[]): number {
  let maxProfitValue = 0;
  for (let i = 0; i < prices.length; i++) {
    const element = prices[i];
    for (let k = i + 1; k < prices.length; k++) {
      const innerElement = prices[k];
      const difference = innerElement - element;

      maxProfitValue = Math.max(difference, maxProfitValue);
    }
  }
  return maxProfitValue;
}
