let component = ReasonReact.statelessComponent("TicketEntry");
let make = (~ticket: Ticket.ticketForm, _children) => {
  ...component,
  render: _self => {
    <section className="ticket-list__entry">
      <TicketPreviewRender ticket elementClass="ticket-list__ticket-preview" />
      <section className="ticket-list__canditates">
        <h2> {ReasonReact.string("Candidate List")} </h2>
      </section>
    </section>;
  },
};
