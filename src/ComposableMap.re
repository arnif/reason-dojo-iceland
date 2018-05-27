[@bs.deriving abstract]
type typeProjectionConfig = {
  scale: int,
  rotation: array(int),
};

[@bs.deriving abstract]
type typeStyle = {
  width: string,
  height: string,
};

[@bs.deriving abstract]
type jsProps = {
  projectionConfig: typeProjectionConfig,
  width: int,
  height: int,
  style: typeStyle,
};

[@bs.module "react-simple-maps"]
external myJSReactClass : ReasonReact.reactClass = "ComposableMap";

/* TODO check if this works... */
let make = (~projectionConfig, ~width, ~height, ~style, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=myJSReactClass,
    ~props=jsProps(~projectionConfig, ~width, ~height, ~style),
    children,
  );