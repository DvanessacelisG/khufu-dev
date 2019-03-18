let component = ReasonReact.statelessComponent("TicketList");

let renderTicket = t => {
  <TicketEntry />;
};

let renderTickets = tickets => {
  let ticketList =
    List.map(t => renderTicket(t), tickets)
    |> Array.of_list
    |> ReasonReact.array;
  <div className="ticket-list"> ticketList </div>;
};

let make = (~tickectsList: Ticket.ticketsList, _children) => {
  ...component,
  render: _self => {
    renderTickets(tickectsList.tickets);
  },
};
