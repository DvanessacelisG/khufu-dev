type currentDisplay =
  | S_ComponentsCreated
  | S_FetchingTickets
  | S_TicketsDisplayed(Ticket.ticketsList)
  | S_ErrorDisplayed;

type action =
  | A_FetchTickets
  | A_DisplayTickets(Ticket.ticketsList)
  | A_DisplayTicketForm
  | A_CloseTicketForm
  | A_DisplayError;

type state = {
  createTicketForm: bool,
  currentDisplay,
};

let renderTickets = (~tickets: Ticket.ticketsList) =>
  <TicketList tickectsList=tickets />;

let renderFooter = () =>
  <section>
    <p>
      {ReasonReact.string(
         "2 Open Tickets, 14 Active Candidates and 33 Total Candidates",
       )}
    </p>
    <a> {ReasonReact.string("Add Ticket")} </a>
  </section>;
let renderCreateTicketForm = () => <CreateTicketContainer />;

let reducer = (action, state) =>
  switch (action) {
  | A_FetchTickets =>
    ReasonReact.Update({...state, currentDisplay: S_FetchingTickets})
  | A_DisplayTickets(ticketsList) =>
    ReasonReact.Update({
      ...state,
      currentDisplay: S_TicketsDisplayed(ticketsList),
    })
  | A_DisplayTicketForm =>
    ReasonReact.Update({...state, createTicketForm: true})
  | A_CloseTicketForm =>
    ReasonReact.Update({...state, createTicketForm: false})
  | A_DisplayError =>
    ReasonReact.Update({...state, currentDisplay: S_ErrorDisplayed})
  };
let render = self =>
  ReasonReact.(
    switch (self.state.currentDisplay) {
    | S_ComponentsCreated =>
      <div>
        <h2> {ReasonReact.string("Components Loaded")} </h2>
        {renderFooter()}
        {self.state.createTicketForm ? renderCreateTicketForm() : null}
      </div>

    | S_FetchingTickets =>
      <div>
        <h2> {ReasonReact.string("loading...")} </h2>
        {renderFooter()}
        {self.state.createTicketForm ? renderCreateTicketForm() : null}
      </div>

    | S_TicketsDisplayed(ticketsList) =>
      <div>
        {renderTickets(ticketsList)}
        {renderFooter()}
        {self.state.createTicketForm ? renderCreateTicketForm() : null}
      </div>

    | S_ErrorDisplayed =>
      <div>
        <h2> {ReasonReact.string("Error")} </h2>
        {renderFooter()}
        {self.state.createTicketForm ? renderCreateTicketForm() : null}
      </div>
    }
  );
let component = ReasonReact.reducerComponent("TicketView");
let make = _self => {
  ...component,
  initialState: () => {
    createTicketForm: false,
    currentDisplay: S_ComponentsCreated,
  },
  reducer,
  render,
  didMount: self => {
    self.send(A_FetchTickets);
  },
};
