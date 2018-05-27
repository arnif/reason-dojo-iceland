[@bs.deriving abstract]
type typeMarker = {coordinates: (float, float)};

[@bs.deriving abstract]
type jsProps = {marker: typeMarker};

[@bs.module "react-simple-maps"]
external myJSReactClass : ReasonReact.reactClass = "Marker";

let make = (~marker, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=myJSReactClass,
    ~props=jsProps(~marker),
    children,
  );