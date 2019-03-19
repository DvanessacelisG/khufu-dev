let component = ReasonReact.statelessComponent("TicketView");
let make = _children => {
  ...component,
  render: _self => {
    <div>
      <TicketEntry />
      <section>
        <p>2 Open Tickets, 14 Active Candidates and 33 Total Candidates</p>
        <a>Add Ticket</a>
      </section>
      
    </div>
    
    
    ;
  },
};
