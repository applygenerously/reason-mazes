type t = (int, int);

let make = (row, col): t => (row, col);

let add = ((row, col), (row', col')): t => (row + row', col + col');