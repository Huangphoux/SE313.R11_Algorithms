let res = queens()

for (let row of res) { console.log(row.join(" ")) }

function queens() {
  let n = 8

  // Array(n).fill(0): Mảng n phần tử, chứa n số 0
  // Array.from: mat có n phần tử
  // mat: mảng n phần tử, mỗi phần tử là một mảng có n số 0
  let mat = Array.from({ length: n }, () => Array(n).fill(0))

  placeQueens(mat, 0)

  return mat
}

function placeQueens(mat, row) {
  let n = mat.length // n = 8

  if (row === n) return true

  // for each row
  for (let i = 0; i < n; i++) {
    if (isSafe(mat, row, i)) {
      // test column
      mat[row][i] = 1

      if (placeQueens(mat, row + 1)) { return true }

      mat[row][i] = 0
    }
  }

  return false
}

function isSafe(mat, row, col) {
  let n = mat.length // n = 8

  for (let i = 0; i < row; i++)
    if (mat[i][col] === 1) { return false }

  for (let i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    if (mat[i][j] === 1) { return false }

  for (let i = row - 1, j = col + 1; j < n && i >= 0; i--, j++)
    if (mat[i][j] === 1) { return false }

  return true
}