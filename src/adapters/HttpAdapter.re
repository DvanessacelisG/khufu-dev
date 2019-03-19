let post = (url, payload) => {
  FetchConnector.post(url, payload);
};

let get = url => {
  FetchConnector.get(url);
};
