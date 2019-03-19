let create_ticket_endpoint = "https://reqres.in/apiusers";
let get_tickets_endpoint = "http://www.mocky.io/v2/5c8fc25e3600003a47f0feef";

let createTicket = ticket => {
  let json = TypeToJsonMapper.ticketToJson(ticket);
  let response = HttpAdapter.post(create_ticket_endpoint, json);
  response;
};

let getTickets = () => {
  let response =
    HttpAdapter.get(get_tickets_endpoint);
  response;
};
