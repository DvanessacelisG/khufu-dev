[%raw {| require("./TicketList.scss") |}];
let component = ReasonReact.statelessComponent("TicketList");

let renderTicket = ticket => {
  <TicketEntry ticket />;
};
let ticketListHeader = () => {
  <ul className="ticket-list__headers">
    <li> {ReasonReact.string("Ticket Information")} </li>
    <li> {ReasonReact.string("Candidate Name")} </li>
    <li> {ReasonReact.string("Status")} </li>
    <li> {ReasonReact.string("Recent Commet")} </li>
    <li> {ReasonReact.string("Last Updated")} </li>
  </ul>;
};

let renderTickets = tickets => {
  let ticketList =
    List.map(t => renderTicket(t), tickets)
    |> Array.of_list
    |> ReasonReact.array;
  <div className="ticket-list"> {ticketListHeader()} ticketList </div>;
};

let make = (~tickectsList: Ticket.ticketsList, _children) => {
  ...component,
  render: _self => {
    renderTickets(tickectsList.tickets);
  },
};
