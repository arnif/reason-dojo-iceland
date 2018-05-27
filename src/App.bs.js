// Generated by BUCKLESCRIPT VERSION 3.1.4, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Marker$MyProjectName = require("./Marker.bs.js");
var Fetcher$MyProjectName = require("./Fetcher.bs.js");
var Markers$MyProjectName = require("./Markers.bs.js");
var Geography$MyProjectName = require("./Geography.bs.js");
var Geographies$MyProjectName = require("./Geographies.bs.js");
var ComposableMap$MyProjectName = require("./ComposableMap.bs.js");
var ZoomableGroup$MyProjectName = require("./ZoomableGroup.bs.js");

var component = ReasonReact.reducerComponent("App");

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              Fetcher$MyProjectName.fetchPost("https://immense-river-25513.herokuapp.com/add-location", "arnif");
              return Fetcher$MyProjectName.fetchGet("https://immense-river-25513.herokuapp.com/locations", (function (data) {
                            console.log(data);
                            return Curry._1(self[/* send */3], /* LoadData */[data]);
                          }));
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              return ReasonReact.element(/* None */0, /* None */0, ComposableMap$MyProjectName.make({
                              scale: 100,
                              rotation: /* array */[
                                1,
                                1
                              ]
                            }, 980, 551, {
                              width: "100%",
                              height: "auto"
                            }, /* array */[ReasonReact.element(/* None */0, /* None */0, ZoomableGroup$MyProjectName.make(/* array */[
                                        0,
                                        20
                                      ], true, /* array */[
                                        ReasonReact.element(/* None */0, /* None */0, Geographies$MyProjectName.make("../world-50m.json", (function (geographies, projection) {
                                                    return $$Array.mapi((function (i, gg) {
                                                                  return ReasonReact.element(/* Some */[String(i)], /* None */0, Geography$MyProjectName.make(gg, projection, {
                                                                                  default: {
                                                                                    fill: "#ECEFF1",
                                                                                    stroke: "#607D8B",
                                                                                    strokeWidth: 0.75,
                                                                                    outline: "none"
                                                                                  },
                                                                                  hover: {
                                                                                    fill: "#607D8B",
                                                                                    stroke: "#607D8B",
                                                                                    strokeWidth: 0.75,
                                                                                    outline: "none"
                                                                                  },
                                                                                  pressed: {
                                                                                    fill: "#FF5722",
                                                                                    stroke: "#607D8B",
                                                                                    strokeWidth: 0.75,
                                                                                    outline: "none"
                                                                                  }
                                                                                }, /* array */[]));
                                                                }), geographies);
                                                  }))),
                                        ReasonReact.element(/* None */0, /* None */0, Markers$MyProjectName.make($$Array.map((function (mark) {
                                                        var match = mark.location;
                                                        return ReasonReact.element(/* None */0, /* None */0, Marker$MyProjectName.make({
                                                                        coordinates: /* tuple */[
                                                                          match[1],
                                                                          match[0]
                                                                        ]
                                                                      }, /* array */[React.createElement("circle", {
                                                                              cx: "0",
                                                                              cy: "0",
                                                                              r: "2"
                                                                            })]));
                                                      }), param[/* state */1][/* data */0])))
                                      ]))]));
            }),
          /* initialState */(function () {
              return /* record */[/* data : array */[]];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _) {
              return /* Update */Block.__(0, [/* record */[/* data */action[0]]]);
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */