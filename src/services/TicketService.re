let create_ticket_endpoint = "https://reqres.in/apiusers";

let createTicket = ticket => {
  let json = TypeToJsonMapper.ticketToJson(ticket);
  let response = HttpAdapter.post(create_ticket_endpoint, json);
  response;
};

