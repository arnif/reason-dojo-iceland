/* Geographies */

[@bs.deriving abstract]
type jsProps = {geography: string};

[@bs.module "react-simple-maps"]
external myJSReactClass : ReasonReact.reactClass = "Geographies";

let make = (~geography, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=myJSReactClass,
    ~props=jsProps(~geography),
    children,
  );