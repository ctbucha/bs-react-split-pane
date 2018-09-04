[@bs.module "react-split-pane"]
external pane : ReasonReact.reactClass = "Pane";

type split = [ | `vertical | `horizontal];

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  split,
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
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=pane,
    ~props=
      props(
        ~split?,
        ~className?,
        ~initialSize?,
        ~minSize?,
        ~maxSize?,
        ~size?,
        (),
      ),
    children,
  );
