[%raw {| require("./CreateTicket.scss") |}];

let targetValue = (event): string =>
  ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value;

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
        <label className="create-ticket__field create-ticket__field--title ">
          {ReasonReact.string("Title")}
          <input
            type_="text"
            placeholder="Eg. John Doe"
            value={ticketForm.title}
            onChange={ev =>
              update(Title: Ticket.ticketFormField, targetValue(ev))
            }
          />
        </label>
        <label className="create-ticket__field">
          {ReasonReact.string("Discipline")}
          <input
            type_="text"
            placeholder="Eg. Project Manager"
            value={ticketForm.discipline}
            onChange={ev =>
              update(Discipline: Ticket.ticketFormField, targetValue(ev))
            }
          />
        </label>
        <label className="create-ticket__field">
          {ReasonReact.string("Project Name")}
          <input
            type_="text"
            placeholder="Eg. Endava"
            value={ticketForm.projectName}
            onChange={ev =>
              update(ProjectName: Ticket.ticketFormField, targetValue(ev))
            }
          />
        </label>
        <label className="create-ticket__field">
          {ReasonReact.string("Grade")}
          <input
            type_="text"
            placeholder="Eg. Junior Technician"
            value={ticketForm.grade}
            onChange={ev =>
              update(Grade: Ticket.ticketFormField, targetValue(ev))
            }
          />
        </label>
        <label className="create-ticket__field">
          {ReasonReact.string("Project Role")}
          <input
            type_="text"
            placeholder="Eg. AM Mobile (IOS)"
            value={ticketForm.projectRole}
            onChange={ev =>
              update(ProjectRole: Ticket.ticketFormField, targetValue(ev))
            }
          />
        </label>
        <label className="create-ticket__field">
          {ReasonReact.string("Priority")}
          <input
            type_="text"
            placeholder="Eg. John Doe"
            value={ticketForm.priority}
            onChange={ev =>
              update(Priority: Ticket.ticketFormField, targetValue(ev))
            }
          />
        </label>
        <label className="create-ticket__field">
          {ReasonReact.string("Number of Positions")}
          <input
            type_="number"
            placeholder="Eg. 1"
            value={ticketForm.numberPositions}
            onChange={ev =>
              update(
                NumberPositions: Ticket.ticketFormField,
                targetValue(ev),
              )
            }
          />
        </label>
        <label className="create-ticket__field">
          {ReasonReact.string("Recruiter")}
          <input
            type_="text"
            placeholder="Eg. Natalia"
            value={ticketForm.recruiter}
            onChange={ev =>
              update(Recruiter: Ticket.ticketFormField, targetValue(ev))
            }
          />
        </label>
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
