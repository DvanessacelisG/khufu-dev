let decodeTicket = json =>
  Json.Decode.{
    Ticket.title: json |> field("title", string),
    Ticket.discipline: json |> field("discipline", string),
    Ticket.projectName: json |> field("projectName", string),
    Ticket.grade: json |> field("grade", string),
    Ticket.projectRole: json |> field("projectRole", string),
    Ticket.priority: json |> field("priority", string),
    Ticket.numberPositions: json |> field("numberPositions", string),
    Ticket.recruiter: json |> field("recruiter", string),
  };

let decodeTicketList = json => {
  Json.Decode.{
    Ticket.tickets: json |> field("tickets", list(decodeTicket)),
  };
};
