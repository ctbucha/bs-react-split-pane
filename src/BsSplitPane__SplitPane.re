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
  split,
  [@bs.optional]
  resizerSize: int,
  [@bs.optional]
  primary,
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
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=splitPane,
    ~props=
      props(
        ~className?,
        ~split?,
        ~resizerSize?,
        ~primary?,
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
