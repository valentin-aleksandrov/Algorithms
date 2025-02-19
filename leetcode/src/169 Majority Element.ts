function majorityElement(nums: number[]): number {
  const minMajorityOccurrenceLimit = nums.length / 2;
  const elementOccurrencesMap = {};

  for (const currentNumber of nums) {
    if (elementOccurrencesMap[currentNumber] === undefined) {
      elementOccurrencesMap[currentNumber] = 1;
    } else {
      elementOccurrencesMap[currentNumber]++;
    }

    if (elementOccurrencesMap[currentNumber] > minMajorityOccurrenceLimit) {
      return currentNumber;
    }
  }

  return 0;
}

const input = [2, 2, 1, 1, 1, 2, 2];

const result = majorityElement(input);

result;
