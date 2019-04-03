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
  | A_DisplayError
  | A_NextPage
  | A_PreviousPage;

type pagination = {
  limit: int,
  offset: int,
  currentPage: int,
};

type state = {
  pagination,
  createTicketForm: bool,
  currentDisplay,
};

let offsetOperation = (pagination: pagination): int => {
  pagination.offset - pagination.limit;
};

let nextPage = (pagination: pagination) => {
  limit: pagination.limit,
  offset:
    pagination.offset + pagination.limit < pagination.limit ?
      pagination.limit : pagination.offset + pagination.limit,
  currentPage: pagination.currentPage + 1,
};

let previousPage = (pagination: pagination) => {
  limit: pagination.limit,
  offset: offsetOperation(pagination) < 0 ? 0 : offsetOperation(pagination),
  currentPage:
    pagination.currentPage == 1 ?
      pagination.currentPage : pagination.currentPage - 1,
};

let renderTickets = (~tickets: Ticket.ticketsList) =>
  <TicketList tickectsList=tickets />;

let renderCreateTicketForm = self =>
  ReasonReact.(
    <CreateTicketContainer close={() => self.send(A_CloseTicketForm)} />
  );

let fetchTickets = (pagination: pagination, self) => {
  let tickets = TicketService.getTickets(pagination.limit, pagination.offset);
  Js.log(pagination.limit);
  Js.log(pagination.offset);
  tickets
  |> BsFluture.fork(
       error => Js.log("ERROR"),
       value =>
         ReasonReact.(
           self.send(
             A_DisplayTickets(JsonResponseMapper.decodeTicketList(value)),
           )
         ),
     )
  |> ignore;
};
let reducer = (action, state) =>
  switch (action) {
  | A_FetchTickets =>
    ReasonReact.UpdateWithSideEffects(
      {...state, currentDisplay: S_FetchingTickets},
      fetchTickets(state.pagination),
    )
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
  | A_NextPage =>
    ReasonReact.UpdateWithSideEffects(
      {
        ...state,
        pagination: {
          nextPage(state.pagination);
        },
        currentDisplay: S_FetchingTickets,
      },
      fetchTickets(nextPage(state.pagination)),
    )
  | A_PreviousPage =>
    ReasonReact.UpdateWithSideEffects(
      {
        ...state,
        pagination: {
          previousPage(state.pagination);
        },
        currentDisplay: S_FetchingTickets,
      },
      fetchTickets(previousPage(state.pagination)),
    )
  };
let renderPageMessage = (message, showTicketForm, self) => {
  ReasonReact.(
    <div>
      <TicketOverview />
      <h2> {ReasonReact.string(message)} </h2>
      <TicketViewFooter
        cancel={() => self.send(A_DisplayTicketForm)}
        length=0
      />
      {showTicketForm ? renderCreateTicketForm(self) : ReasonReact.null}
    </div>
  );
};

let renderPageTickets =
    (ticketsList: Ticket.ticketsList, showTicketForm, self) => {
  ReasonReact.(
    <div>
      <TicketOverview />
      {renderTickets(ticketsList)}
      <Paginator
        next={() => self.send(A_NextPage)}
        prev={() => self.send(A_PreviousPage)}
        currentPage={self.state.pagination.currentPage}
      />
      <TicketViewFooter
        cancel={() => self.send(A_DisplayTicketForm)}
        length={List.length(ticketsList.tickets)}
      />
      {showTicketForm ? renderCreateTicketForm(self) : ReasonReact.null}
    </div>
  );
};

let render = self =>
  ReasonReact.(
    switch (self.state.currentDisplay) {
    | S_ComponentsCreated =>
      renderPageMessage(
        "Components Loaded",
        self.state.createTicketForm,
        self,
      )
    | S_FetchingTickets =>
      renderPageMessage("loading...", self.state.createTicketForm, self)
    | S_TicketsDisplayed(ticketsList) =>
      renderPageTickets(ticketsList, self.state.createTicketForm, self)
    | S_ErrorDisplayed =>
      renderPageMessage("Error", self.state.createTicketForm, self)
    }
  );
let component = ReasonReact.reducerComponent("TicketView");
let make = _self => {
  ...component,
  initialState: () => {
    pagination: {
      offset: 0,
      limit: 2,
      currentPage: 1,
    },
    createTicketForm: false,
    currentDisplay: S_ComponentsCreated,
  },
  reducer,
  render,
  didMount: self => {
    self.send(A_FetchTickets);
  },
};
