let createFetch = (url, payload, httpVerb) => {
  Fetch.fetchWithInit(
    url,
    Fetch.RequestInit.make(
      ~method_=httpVerb,
      ~body=Fetch.BodyInit.make(payload),
      ~headers=Fetch.HeadersInit.make({"Content-Type": "  /json"}),
      (),
    ),
  );
};

let makeRequest = (url, payload, httpVerb) => {
  let future =
    BsFluture.tryP(() =>
      Js.Promise.(
        createFetch(url, payload, httpVerb)
        |> then_(response => response |> resolve)
      )
    );
  future;
};

let defaultRequest = url => {
  let future =
    BsFluture.tryP(() =>
      Js.Promise.(Fetch.fetch(url) |> then_(Fetch.Response.json))
    );
  future;
};
