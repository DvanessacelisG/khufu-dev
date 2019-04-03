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
        <InputFieldRender field={ticketForm.title} fieldName=Title update />
        <DataListRender field={ticketForm.grade} fieldName=Grade update />
        <CheckboxRender field={ticketForm.isBench} fieldName=IsBench update />
        <DataListRender
          field={ticketForm.priority}
          fieldName=Priority
          update
        />
        <InputFieldRender field={ticketForm.du} fieldName=Du update />
        <InputFieldRender
          field={ticketForm.positionBrief}
          fieldName=PositionBrief
          update
        />
        {ticketForm.isBench.value === "true"
           ? <div>
               <InputFieldRender
                 field={ticketForm.projectName}
                 fieldName=ProjectName
                 update
               />
               <InputFieldRender
                 field={ticketForm.projectCode}
                 fieldName=ProjectCode
                 update
               />
               <InputFieldRender
                 field={ticketForm.clientName}
                 fieldName=ClientName
                 update
               />
               <InputFieldRender field={ticketForm.agu} fieldName=Agu update />
               <InputFieldRender
                 field={ticketForm.projectStartDate}
                 fieldName=ProjectStartDate
                 update
               />
             </div>
           : ReasonReact.null}
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
