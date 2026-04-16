import { reverseWords } from "./reverse-words-in-a-string-III";

describe("Reverse Words in a String III", () => {
  it("should reverse words separated by whitespace", () => {
    expect(reverseWords("Let's take LeetCode contest")).toBe(
      "s'teL ekat edoCteeL tsetnoc",
    );
    expect(reverseWords("Mr Ding")).toBe("rM gniD");
  });
});
