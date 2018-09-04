# bs-react-split-pane
[BuckleScript](https://bucklescript.github.io/) bindings for [react-split-pane](https://github.com/tomkp/react-split-pane).

## Status

🚧 This is a WIP, not everything is supported yet. 🚧

Feel free to create an issue or PR if you find anything missing.

## Installation


```
npm install --save @ctbucha/bs-react-split-pane
```

Then add `@ctbucha/bs-react-split-pane` to `bs-dependencies` in your
`bsconfig.json`:

```
{
  ...
  "bs-dependencies": ["@ctbucha/bs-react-split-pane"]
}
```

## Usage

```reason
/* App.re */
let component = ReasonReact.statelessComponent("App");

let make = _children => { 
  ...component,
  render: _self => BsSplitPane.(
    <SplitPane size=100>
      <div>(ReasonReact.string("first div"))</div>
      <div>(ReasonReact.string("second div"))</div>
    </SplitPane>
  )
};
```
