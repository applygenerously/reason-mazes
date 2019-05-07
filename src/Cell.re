type t = {
  coordinate: Coordinate.t,
  links: list(t),
  neighbors,
}
and neighbors = {
  n: option(t),
  e: option(t),
  s: option(t),
  w: option(t),
};

let make = coordinate => {
  coordinate,
  links: [],
  neighbors: {
    n: None,
    e: None,
    s: None,
    w: None,
  },
};

let link = (self, cell) => {...self, links: [cell, ...self.links]};

let unlink = (self, cell) => {
  ...self,
  links: List.filter(l => l !== cell, self.links),
};

let isLinked = (self: t, cell: t): bool => {
  switch (List.find(c => c == cell, self.links)) {
  | exception Not_found => false
  | _ => true
  };
};

module CellMap =
  Map.Make({
    type t = Coordinate.t;
    let compare = compare;
  });

type grid = {
  rows: int,
  cols: int,
  grid: CellMap.t(t),
};

let addCell = (c: t, g: grid): grid => {
  ...g,
  grid: CellMap.add(c.coordinate, c, g.grid),
};

let getCell = (c: Coordinate.t, {grid}: grid): option(t) => {
  switch (CellMap.find(c, grid)) {
  | cell => Some(cell)
  | exception Not_found => None
  };
};

let getNeighbors = (self: t, g: grid): t => {
  let (row, col) = self.coordinate;
  {
    ...self,
    neighbors: {
      n: getCell((row - 1, col), g),
      e: getCell((row, col + 1), g),
      s: getCell((row + 1, col), g),
      w: getCell((row, col - 1), g),
    },
  };
};