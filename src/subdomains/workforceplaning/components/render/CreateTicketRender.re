[%raw {| require("./CreateTicket.scss") |}];

let targetValue = (event): string => {
  ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value;
};

let component = ReasonReact.statelessComponent("CreateTicketRender");

let make =
    (~ticketForm: Ticket.ticketForm, ~update, ~create, ~cancel, _children) => {
  ...component,
  render: _self => {
    <div className="create-ticket">
      <h2 className="create-ticket__title">
        {ReasonReact.string("Ticket Creation")}
      </h2>
      <form
        className="create-ticket__form"
        onSubmit={ev => {
          ReactEventRe.Form.preventDefault(ev);
          create();
        }}>
        <InputFieldRender field={ticketForm.title} update />
        <InputFieldRender field={ticketForm.projectName} update />
        <InputFieldRender field={ticketForm.projectStartDate} update />
        <InputFieldRender field={ticketForm.clientName} update />
        <InputFieldRender field={ticketForm.agu} update />
        <InputFieldRender field={ticketForm.du} update />
        <InputFieldRender field={ticketForm.grade} update />
        <InputFieldRender field={ticketForm.priority} update />
        <InputFieldRender field={ticketForm.positionBrief} update />
        <InputFieldRender field={ticketForm.isBench} update />
        <InputFieldRender field={ticketForm.projectCode} update />
        <div className="create-ticket__btns">
          <button
            className="create-ticket__btn create-ticket__btn--create"
            type_="submit">
            {ReasonReact.string("Create")}
          </button>
          <button
            className="create-ticket__btn create-ticket__btn--cancel"
            onClick={_ev => cancel()}>
            {ReasonReact.string("Cancel")}
          </button>
        </div>
      </form>
    </div>;
  },
};
