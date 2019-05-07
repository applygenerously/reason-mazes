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

let isLinked = (self, cell): bool => {
  switch (List.find(cell, self.links)) {
  | exception Not_found => false
  | _ => true
  };
};

module CellMap =
  Map.Make({
    type t = Coordinate.t;
    let compare = compare;
  });

type grid = CellMap.t(t);

let a = make((1, 1));

let b = make((2, 2));

let g = CellMap.add(a.coordinate, a);