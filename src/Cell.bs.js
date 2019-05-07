// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var $$Map = require("bs-platform/lib/js/map.js");
var List = require("bs-platform/lib/js/list.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Caml_obj = require("bs-platform/lib/js/caml_obj.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

function make(coordinate) {
  return /* record */[
          /* coordinate */coordinate,
          /* links : [] */0,
          /* neighbors : record */[
            /* n */undefined,
            /* e */undefined,
            /* s */undefined,
            /* w */undefined
          ]
        ];
}

function link(self, cell) {
  return /* record */[
          /* coordinate */self[/* coordinate */0],
          /* links : :: */[
            cell,
            self[/* links */1]
          ],
          /* neighbors */self[/* neighbors */2]
        ];
}

function unlink(self, cell) {
  return /* record */[
          /* coordinate */self[/* coordinate */0],
          /* links */List.filter((function (l) {
                    return l !== cell;
                  }))(self[/* links */1]),
          /* neighbors */self[/* neighbors */2]
        ];
}

function isLinked(self, cell) {
  try {
    List.find(cell, self[/* links */1]);
    return true;
  }
  catch (exn){
    if (exn === Caml_builtin_exceptions.not_found) {
      return false;
    } else {
      throw exn;
    }
  }
}

var compare = Caml_obj.caml_compare;

var CellMap = $$Map.Make(/* module */[/* compare */compare]);

var a_000 = /* coordinate : tuple */[
  1,
  1
];

var a_002 = /* neighbors : record */[
  /* n */undefined,
  /* e */undefined,
  /* s */undefined,
  /* w */undefined
];

var a = /* record */[
  a_000,
  /* links : [] */0,
  a_002
];

var b_000 = /* coordinate : tuple */[
  2,
  2
];

var b_002 = /* neighbors : record */[
  /* n */undefined,
  /* e */undefined,
  /* s */undefined,
  /* w */undefined
];

var b = /* record */[
  b_000,
  /* links : [] */0,
  b_002
];

var g = Curry._2(CellMap[/* add */3], /* tuple */[
      1,
      1
    ], a);

exports.make = make;
exports.link = link;
exports.unlink = unlink;
exports.isLinked = isLinked;
exports.CellMap = CellMap;
exports.a = a;
exports.b = b;
exports.g = g;
/* CellMap Not a pure module */
