type action =
  | A_Validate(Ticket.ticketForm)
  | A_Send(Ticket.ticketForm)
  | A_UpdateField(Ticket.ticketForm, Ticket.ticketFormField, string)
  | A_SendSuccesful
  | A_ErrorSending
  | A_Cancel;

type state =
  | S_WaitingForTicket(Ticket.ticketForm)
  | S_Validating(Ticket.ticketForm)
  | S_Sending(Ticket.ticketForm)
  | S_FormSent
  | S_SendFailed;

let ticketValues: Ticket.ticketForm = {
  title: "",
  discipline: "",
  projectName: "",
  grade: "",
  projectRole: "",
  priority: "",
  numberPositions: "0",
  recruiter: "",
};

let updateFormState =
    (currentFields: Ticket.ticketForm, field: Ticket.ticketFormField, text) =>
  switch (field) {
  | Title => {...currentFields, title: text}
  | Discipline => {...currentFields, discipline: text}
  | ProjectName => {...currentFields, projectName: text}
  | Grade => {...currentFields, grade: text}
  | ProjectRole => {...currentFields, projectRole: text}
  | Priority => {...currentFields, priority: text}
  | NumberPositions => {...currentFields, numberPositions: text}
  | Recruiter => {...currentFields, recruiter: text}
  };

let validateForm = (ticketForm: Ticket.ticketForm, self) => {
  Js.log("Form Validated");
  ReasonReact.(self.send(A_Send(ticketForm)));
};

let sendForm = (ticketForm: Ticket.ticketForm, self) => {
  let ticketCreated = TicketService.createTicket(ticketForm);
  ticketCreated
  |> BsFluture.fork(
       error => ReasonReact.(self.send(A_ErrorSending)),
       value => ReasonReact.(self.send(A_SendSuccesful)),
     )
  |> ignore;
};

let component = ReasonReact.reducerComponent("CreateTicketContainer");
let make = (~close, _self) => {
  ...component,
  initialState: () => S_WaitingForTicket(ticketValues),
  reducer: (action, _state) =>
    switch (action) {
    | A_Validate(ticketForm) =>
      ReasonReact.UpdateWithSideEffects(
        S_Validating(ticketForm),
        validateForm(ticketForm),
      )
    | A_UpdateField(ticketForm, ticketFormField, text) =>
      ReasonReact.Update(
        S_WaitingForTicket(
          updateFormState(ticketForm, ticketFormField, text),
        ),
      )
    | A_Send(ticketForm) =>
      ReasonReact.UpdateWithSideEffects(
        S_Sending(ticketForm),
        sendForm(ticketForm),
      )
    | A_SendSuccesful => ReasonReact.Update(S_FormSent)
    | A_ErrorSending => ReasonReact.Update(S_SendFailed)
    | A_Cancel =>
      close();
      ReasonReact.NoUpdate;
    },
  render: self => {
    switch (self.state) {
    | S_WaitingForTicket(ticketForm) =>
      <CreateTicketRender
        ticketForm
        update={(field, text) =>
          self.send(A_UpdateField(ticketForm, field, text))
        }
        create={() => self.send(A_Validate(ticketForm))}
        cancel={() => self.send(A_Cancel)}
      />
    | S_Sending(ticketForm) => <h2> {ReasonReact.string("Sending")} </h2>
    | S_FormSent => <h2> {ReasonReact.string("TICKET CREATED")} </h2>
    | _ => <h2> {ReasonReact.string("ERROR")} </h2>
    };
  },
};
