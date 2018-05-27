[@bs.module "react-simple-maps"]
external myJSReactClass : ReasonReact.reactClass = "Markers";

let make = children =>
  ReasonReact.wrapJsForReason(
    ~reactClass=myJSReactClass,
    ~props=(),
    children,
  );