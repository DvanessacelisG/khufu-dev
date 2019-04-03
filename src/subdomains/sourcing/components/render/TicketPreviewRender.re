[%raw {| require("./TicketPreview.scss") |}];
let component = ReasonReact.statelessComponent("TicketPreviewRender");

let make = (~ticket: Ticket.ticket, ~elementClass, _children) => {
  ...component,
  render: _self => {
    <section className={"ticket-preview " ++ elementClass}>
      <div>
        <h1 className="ticket-preview__title">
          {ReasonReact.string(ticket.title)}
        </h1>
        <p className="ticket-preview__assign">
          {ReasonReact.string("Assigned to:" ++ ticket.projectName)}
        </p>
      </div>
      <div className="ticket-preview__details">
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Project Start Date:")} </span>
          {ReasonReact.string(ticket.projectStartDate)}
        </p>
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Client Name:")} </span>
          {ReasonReact.string(ticket.clientName)}
        </p>
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Agu:")} </span>
          {ReasonReact.string(ticket.agu)}
        </p>
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Du:")} </span>
          {ReasonReact.string(ticket.du)}
        </p>
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Grade:")} </span>
          {ReasonReact.string(ticket.grade)}
        </p>
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Priority:")} </span>
          {ReasonReact.string(ticket.priority)}
        </p>
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Position Brief:")} </span>
          {ReasonReact.string(ticket.positionBrief)}
        </p>
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Is Bench:")} </span>
          {ReasonReact.string(string_of_bool(ticket.isBench))}
        </p>
        <p className="ticket-preview__detail">
          <span> {ReasonReact.string("Project Code:")} </span>
          {ReasonReact.string(ticket.projectCode)}
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
