let ticketToJson = (ticket: Ticket.ticketForm) => {
  let payload = Js.Dict.empty();
  Js.Dict.set(payload, "title", Js.Json.string(ticket.title));
  Js.Dict.set(payload, "discipline", Js.Json.string(ticket.title));
  Js.Dict.set(payload, "projectName", Js.Json.string(ticket.title));
  Js.Dict.set(payload, "grade", Js.Json.string(ticket.title));
  Js.Dict.set(payload, "projectRole", Js.Json.string(ticket.title));
  Js.Dict.set(payload, "priority", Js.Json.string(ticket.title));
  Js.Dict.set(payload, "numberPositions", Js.Json.string(ticket.title));
  Js.Dict.set(payload, "recruiter", Js.Json.string(ticket.title));
  payload;
};
