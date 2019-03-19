[%raw {| require("./TicketFooter.scss") |}];
let component = ReasonReact.statelessComponent("TicketViewFooter");
let make = (~cancel, ~length, _children) => {
  ...component,
  render: _self => {
    <section className="tickets-footer">
      <div />
      <p className="tickets-footer__sum">
        {ReasonReact.string(
           string_of_int(length)
           ++ " Open Tickets, 14 Active Candidates and 33 Total Candidates",
         )}
      </p>
      <a className="tickets-footer__create" onClick={_ev => cancel()}>
        {ReasonReact.string("Add Ticket")}
      </a>
    </section>;
  },
};
