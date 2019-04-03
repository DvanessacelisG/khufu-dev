let component = ReasonReact.statelessComponent("InputFieldRender");

// let targetValue = (event): string => {
//   Js.log(event);
//   ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value;
// };

// let styleModifiers = (field: FormField.field): string => {
//   let baseClass = "create-ticket__field ";
//   field.valid ?
//     baseClass ++ "create-ticket__field--valid" :
//     field.error != "" ? baseClass ++ "create-ticket__field--error" : baseClass;
// };

let getValueFromEvent = (event): string =>
  (event |> ReactEventRe.Form.target |> ReactDOMRe.domElementToObj)##value;

let make = (~field: FormField.field, ~update, _self) => {
  ...component,
  render: _self => {
    <label className="create-ticket__field">
      {ReasonReact.string("Position Title")}
      <input
        type_="text"
        placeholder="vacio"
        value=field.value
        onChange={ev =>
          update(Title: Ticket.ticketFormField, getValueFromEvent(ev))
        }
      />
    </label>;
  },
};
