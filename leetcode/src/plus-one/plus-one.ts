/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits: number[]) {
  let reminder = 0;

  const result = [];
  for (let i = digits.length - 1; i >= 0; i--) {
    let newDigitValue = 0;
    if (i === digits.length - 1) {
      newDigitValue++;
    }
    newDigitValue += digits[i] + reminder;
    if (newDigitValue > 9) {
      newDigitValue = 0;
      reminder = 1;
    } else {
      reminder = 0;
    }
    result.unshift(newDigitValue);
  }

  if (reminder > 0) {
    result.unshift(1);
  }

  return result;
};

export { plusOne };
