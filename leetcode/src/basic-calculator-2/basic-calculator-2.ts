/**
 * @param {string} s
 * @return {number}
 */
var calculate = function (s: string) {
  const stack: number[] = [];
  let num = 0;
  let op = "+";

  for (let i = 0; i < s.length; i++) {
    const ch = s[i];

    if (ch >= "0" && ch <= "9") {
      num = num * 10 + parseInt(ch);
    }

    if ((ch !== " " && isNaN(Number(ch))) || i === s.length - 1) {
      if (op === "+") {
        stack.push(num);
      } else if (op === "-") {
        stack.push(-num);
      } else if (op === "*") {
        const lastDigit = stack.pop();
        if (lastDigit !== undefined) {
          stack.push(lastDigit * num);
        }
      } else if (op === "/") {
        const lastDigit = stack.pop();
        if (lastDigit !== undefined) {
          stack.push(Math.trunc(lastDigit / num));
        }
      }
      op = ch;
      num = 0;
    }
  }

  return stack.reduce((a, b) => a + b, 0);
};

export { calculate };
