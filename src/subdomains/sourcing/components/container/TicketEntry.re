[%raw {| require("./TicketEntry.scss") |}];
let component = ReasonReact.statelessComponent("TicketEntry");
let make = _children => {
  ...component,
  render: _self => {
    <section className="ticket-entry">
      <TicketPreviewRender elementClass="ticket-entry__ticket-preview" />
      <section className="ticket-entry__canditates">
        <h2> {ReasonReact.string("Candidate List")} </h2>
      </section>
    </section>;
  },
};
