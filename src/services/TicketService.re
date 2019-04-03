let create_ticket_endpoint = "https://reqres.in/api/users";
let get_tickets_endpoint = "http://www.mocky.io/v2/5ca367134b000061002095e1";

let createTicket = ticket => {
  let json = TypeToJsonMapper.ticketToJson(ticket);
  let jsonAsString = Js.Json.stringify(json);
  let response = HttpAdapter.post(create_ticket_endpoint, jsonAsString);
  response;
};

let updateTicket = fields => {
  // perform the necessary actions
  let updatedFileds = fields;
  let response = HttpAdapter.put(create_ticket_endpoint, updatedFileds);
  response;
};

let delete = id => {
  // perform the necessary actions
  let response = HttpAdapter.delete(create_ticket_endpoint, id);
  response;
};

let getTickets = (limit: int, offset: int) => {
let endpoint = {j|http://localhost:5000/api/tickets?limit=$(limit)&offset=$(offset)|j};
let response = HttpAdapter.get(endpoint);
  response;
};
