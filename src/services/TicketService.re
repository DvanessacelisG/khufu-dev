let create_ticket_endpoint = "http://localhost:5000/api/tickets";
let get_tickets_endpoint = "http://localhost:5000/api/tickets";

let createTicket = ticket => {
  let json = TypeToJsonMapper.ticketToJson(ticket);
  Js.log(json);
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
