[%raw {| require("./TicketOverview.scss") |}];
let component = ReasonReact.statelessComponent("TicketOverview");
let make = _children => {
  ...component,
  render: _self => {
    <section className="overview">
      <h2> {ReasonReact.string("Overview")} </h2>
      <ul className="overview__filter">
        <li className="overview__item overview__item--active">
          <a> {ReasonReact.string("Active")} </a>
        </li>
        <li className="overview__item">
          <a> {ReasonReact.string("Closed")} </a>
        </li>
        <li className="overview__item">
          <a> {ReasonReact.string("All")} </a>
        </li>
        <li className="overview__item">
          <a> {ReasonReact.string("To Update")} </a>
        </li>
      </ul>
    </section>;
  },
};
