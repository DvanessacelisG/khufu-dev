let decodeTicket = json =>
  Json.Decode.{
    Ticket.title: json |> field("title", string),
    Ticket.projectName: json |> field("projectName", string),
    Ticket.projectStartDate: json |> field("projectStartDate", string),
    Ticket.clientName: json |> field("clientName", string),
    Ticket.agu: json |> field("agu", string),
    Ticket.du: json |> field("du", string),
    Ticket.grade: json |> field("grade", string),
    Ticket.priority: json |> field("priority", string),
    Ticket.positionBrief: json |> field("positionBrief", string),
    Ticket.isBench: json |> field("isBench", bool),
    Ticket.projectCode: json |> field("projectCode", string),
  };

let decodeTicketList = json => {
  Json.Decode.{Ticket.tickets: json |> list(decodeTicket)};
};
