type action =
  | A_Validate
  | A_UpdateField(Ticket.ticketFormField, string)
  | A_SendSuccesful
  | A_ErrorSending
  | A_Cancel;

type formState =
  | S_WaitingForTicket
  | S_Validating
  | S_Sending
  | S_FormSent
  | S_SendFailed;

type globalState = {
  ticket: Ticket.ticketForm,
  formState,
  isBench: bool,
};

let validateForm = (ticket: Ticket.ticketForm) => {
  Validator.validateTicket(ticket);
};

let sendForm = (ticketForm: Ticket.ticketForm, self) => {
  Js.log(ticketForm);
  let ticketCreated = TicketService.createTicket(ticketForm);
  ticketCreated
  |> BsFluture.fork(
       error => ReasonReact.(self.send(A_ErrorSending)),
       value => ReasonReact.(self.send(A_SendSuccesful)),
     )
  |> ignore;
};

let render = self => {
  ReasonReact.(
    switch (self.state.formState) {
    | S_WaitingForTicket =>
      let ticketForm = self.state.ticket;
      <CreateTicketRender
        ticketForm
        update={(field, text) => self.send(A_UpdateField(field, text))}
        create={() => self.send(A_Validate)}
        cancel={() => self.send(A_Cancel)}
      />;
    | S_Sending => <h2> {ReasonReact.string("Sending")} </h2>
    | S_FormSent => <h2> {ReasonReact.string("TICKET CREATED")} </h2>
    | _ => <h2> {ReasonReact.string("ERROR")} </h2>
    }
  );
};

let reduce = (action, globalState, close) => {
  switch (action) {
  | A_Validate =>
    let validatedTicket = validateForm(globalState.ticket);
    Js.log(validatedTicket);
    if (!fst(validatedTicket)) {
      ReasonReact.Update({
        ...globalState,
        ticket: snd(validatedTicket),
        formState: S_WaitingForTicket,
      });
    } else {
      ReasonReact.UpdateWithSideEffects(
        {...globalState, formState: S_Sending},
        sendForm(globalState.ticket),
      );
    };
  | A_UpdateField(ticketFormField, text) =>
    ReasonReact.Update({
      ...globalState,
      ticket:
        Ticket.updateFormState(globalState.ticket, ticketFormField, text),
      formState: S_WaitingForTicket,
    })
  | A_SendSuccesful =>
    ReasonReact.Update({...globalState, formState: S_FormSent})
  | A_ErrorSending =>
    ReasonReact.Update({...globalState, formState: S_FormSent})
  | A_Cancel =>
    close();
    ReasonReact.NoUpdate;
  };
};

let component = ReasonReact.reducerComponent("CreateTicketContainer");
let make = (~close, _self) => {
  ...component,
  initialState: () => {
    ticket: Ticket.defaultValues,
    formState: S_WaitingForTicket,
    isBench: false,
  },
  reducer: (action, globalState) => reduce(action, globalState, close),
  render,
};
