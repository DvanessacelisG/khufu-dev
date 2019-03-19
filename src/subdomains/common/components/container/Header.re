let component = ReasonReact.statelessComponent("Header");


let make = (_self) => {
  ...component,
  render: _self => {
    <header className="header">
        <h2 className="header__title">{ReasonReact.string("Title")}</h2>
    </header>;
  },
};

