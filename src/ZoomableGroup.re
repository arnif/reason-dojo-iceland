[@bs.deriving abstract]
type jsProps = {
  center: array(int),
  disablePanning: bool,
};

[@bs.module "react-simple-maps"]
external myJSReactClass : ReasonReact.reactClass = "ZoomableGroup";

let make = (~center, ~disablePanning, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=myJSReactClass,
    ~props=jsProps(~center, ~disablePanning),
    children,
  );