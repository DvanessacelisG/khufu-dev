let ticketToJson = (ticket: Ticket.ticketForm) =>
  Json.Encode.(
    object_([
      ("title", string(ticket.title)),
      ("discipline", string(ticket.discipline)),
      ("projectName", string(ticket.projectName)),
      ("grade", string(ticket.grade)),
      ("projectRole", string(ticket.projectRole)),
      ("priority", string(ticket.priority)),
      ("numberPositions", string(ticket.numberPositions)),
      ("recruiter", string(ticket.recruiter)),
    ])
  );
