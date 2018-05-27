/* Geography */

[@bs.deriving abstract]
type typeGeography = {id: string};

[@bs.deriving abstract]
type typeProjection = {id: string};

[@bs.deriving abstract]
type styleNest = {
  fill: string,
  stroke: string,
  strokeWidth: float,
  outline: string,
};

[@bs.deriving abstract]
type typeStyle2 = {
  default: styleNest,
  hover: styleNest,
  pressed: styleNest,
};

[@bs.deriving abstract]
type jsProps = {
  geography: typeGeography,
  projection: typeProjection,
  style: typeStyle2,
};

[@bs.module "react-simple-maps"]
external myJSReactClass : ReasonReact.reactClass = "Geography";

let make = (~geography, ~projection, ~style, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=myJSReactClass,
    ~props=jsProps(~geography, ~projection, ~style),
    children,
  );