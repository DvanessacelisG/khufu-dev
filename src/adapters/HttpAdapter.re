let post = (url, payload) =>
  FetchConnector.makeRequest(url, payload, Post: Fetch.requestMethod);

let delete = (url, payload) =>
  FetchConnector.makeRequest(url, payload, Delete: Fetch.requestMethod);

let put = (url, payload) =>
  FetchConnector.makeRequest(url, payload, Put: Fetch.requestMethod);

let get = url => {
  FetchConnector.defaultRequest(url);
};
