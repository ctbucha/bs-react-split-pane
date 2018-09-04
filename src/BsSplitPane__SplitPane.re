[@bs.module "react-split-pane"]
external splitPane : ReasonReact.reactClass = "default";

[@bs.deriving jsConverter]
type split = [ | `vertical | `horizontal];

[@bs.deriving jsConverter]
type primary = [ | `first | `second];

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  className: string,
  [@bs.optional]
  split: string,
  [@bs.optional]
  resizerSize: int,
  [@bs.optional]
  primary: string,
  [@bs.optional]
  allowResize: bool,
  [@bs.optional]
  defaultSize: int,
  [@bs.optional]
  maxSize: int,
  [@bs.optional]
  minSize: int,
  [@bs.optional]
  size: int,
  [@bs.optional]
  step: int,
};

let make =
    (
      ~className=?,
      ~split=?,
      ~resizerSize=?,
      ~primary=?,
      ~allowResize=?,
      ~defaultSize=?,
      ~maxSize=?,
      ~minSize=?,
      ~size=?,
      ~step=?,
      children,
    ) => {
  let splitJs =
    switch (split) {
    | Some(x) => Some(splitToJs(x))
    | None => None
    };
  let primaryJs =
    switch (primary) {
    | Some(x) => Some(primaryToJs(x))
    | None => None
    };
  ReasonReact.wrapJsForReason(
    ~reactClass=splitPane,
    ~props=
      props(
        ~className?,
        ~split=?splitJs,
        ~resizerSize?,
        ~primary=?primaryJs,
        ~allowResize?,
        ~defaultSize?,
        ~maxSize?,
        ~minSize?,
        ~size?,
        ~step?,
        (),
      ),
    children,
  );
};
