[@bs.module "react-split-pane"]
external pane : ReasonReact.reactClass = "Pane";

[@bs.deriving jsConverter]
type split = [ | `vertical | `horizontal];

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  split: string,
  [@bs.optional]
  className: string,
  [@bs.optional]
  initialSize: string,
  [@bs.optional]
  minSize: string,
  [@bs.optional]
  maxSize: string,
  [@bs.optional]
  size: string,
};

let make =
    (
      ~split=?,
      ~className=?,
      ~initialSize=?,
      ~minSize=?,
      ~maxSize=?,
      ~size=?,
      children,
    ) => {
  let splitJs =
    switch (split) {
    | Some(x) => Some(splitToJs(x))
    | None => None
    };
  ReasonReact.wrapJsForReason(
    ~reactClass=pane,
    ~props=
      props(
        ~split=?splitJs,
        ~className?,
        ~initialSize?,
        ~minSize?,
        ~maxSize?,
        ~size?,
        (),
      ),
    children,
  );
};
