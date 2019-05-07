module Grid =
  Map.Make({
    type t = string;
    let compare = compare;
  });