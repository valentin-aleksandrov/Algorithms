import type { Config } from "jest";

const config: Config = {
  verbose: true,
  preset: "ts-jest", // ✅ Use ts-jest for TypeScript support
  testEnvironment: "node",
  transform: {
    "^.+\\.ts$": "ts-jest", // ✅ Transpile TypeScript files with ts-jest
  },
  moduleFileExtensions: ["ts", "js"],
};

export default config;
