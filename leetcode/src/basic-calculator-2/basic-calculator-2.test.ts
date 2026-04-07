import { calculate } from "./basic-calculator-2";

describe("Basic Calculator 2", () => {
  it("should evaluate the expression", () => {
    expect(calculate("3+2*2")).toBe(7);
    expect(calculate(" 3/2 ")).toBe(1);
    expect(calculate("3+5 / 2")).toBe(5);
  });
});
