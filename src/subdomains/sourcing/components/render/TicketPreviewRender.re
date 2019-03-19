[%raw {| require("./TicketPreview.scss") |}];
let component = ReasonReact.statelessComponent("TicketPreviewRender");

let make = (~ticket: Ticket.ticketForm, ~elementClass, _children) => {
  ...component,
  render: _self => {
    <section className={"ticket-preview " ++ elementClass}>
      <div>
        <h1 className="ticket-preview__title">
          {ReasonReact.string(ticket.title)}
        </h1>
        <p className="ticket-preview__assign">
          {ReasonReact.string("Assigned to:" ++ ticket.recruiter)}
        </p>
      </div>
      <div className="ticket-preview__details">
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Discipline:")} </span>
          {ReasonReact.string(ticket.discipline)}
        </p>
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Project Role:")} </span>
          {ReasonReact.string(ticket.projectRole)}
        </p>
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Grade:")} </span>
          {ReasonReact.string(ticket.grade)}
        </p>
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Status:")} </span>
          {ReasonReact.string("In Progress")}
        </p>
      </div>
      <div className="ticket-preview__request">
        <div>
          <p> <span> {ReasonReact.string("Priority High")} </span> </p>
        </div>
        <div>
          <p> <span> {ReasonReact.string("3 Candidates")} </span> </p>
        </div>
      </div>
      <div className="ticket-preview__status">
        <p>
          <span> {ReasonReact.string("3 Open, 1 Hired and 4 Total")} </span>
        </p>
      </div>
    </section>;
  },
};
