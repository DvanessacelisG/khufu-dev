let ticketToJson = (ticket: Ticket.ticketForm) =>
  Json.Encode.(
    object_([
      ("title", string(ticket.title.value)),
      ("projectName", string(ticket.projectName.value)),
      ("projectStartDate", string(ticket.projectStartDate.value)),
      ("clientName", string(ticket.clientName.value)),
      ("agu", string(ticket.agu.value)),
      ("du", string(ticket.du.value)),
      ("grade", string(ticket.grade.value)),
      ("priority", string(ticket.priority.value)),
      ("positionBrief", string(ticket.positionBrief.value)),
      ("isBench", string(ticket.isBench.value)),
      ("projectCode", string(ticket.projectCode.value)),
    ])
  );
