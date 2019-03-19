let get = url => {
  let future =
    BsFluture.tryP(() =>
      Js.Promise.(Fetch.fetch(url) |> then_(Fetch.Response.json))
    );
  future;
};

let post = (url, payload) => {
  let future =
    BsFluture.tryP(() =>
      Js.Promise.(
        Fetch.fetchWithInit(
          url,
          Fetch.RequestInit.make(
            ~method_=Post,
            ~body=
              Fetch.BodyInit.make(
                Js.Json.stringify(Js.Json.object_(payload)),
              ),
            ~headers=Fetch.HeadersInit.make({"Content-Type": "  /json"}),
            (),
          ),
        )
        |> then_(response => response |> resolve)
      )
    );
  future;
};
