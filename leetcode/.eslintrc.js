module.exports = {
  env: {
    node: true,
    jest: true, // Enables Jest globals like 'it', 'describe'
  },
  extends: ["eslint:recommended", "plugin:jest/recommended"],
  plugins: ["jest"],
};
