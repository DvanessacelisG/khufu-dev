let component = ReasonReact.statelessComponent("DataListRender");

let styleModifiers = (field: FormField.field): string => {
  field.valid ?
    "create-ticket__field" : "create-ticket__field create-ticket__field--error";
};

let getValueFromEvent = (event): string => {
  (event |> ReactEventRe.Form.target |> ReactDOMRe.domElementToObj)##value;
};

let make = (~field: FormField.field, ~fieldName: Ticket.ticketFormField, ~update, _self) => {
  ...component,
  render: _self => {
    <label className={styleModifiers(field)}>
      {ReasonReact.string({field.label})}
      <select
        onChange={ev =>
          update(fieldName: Ticket.ticketFormField, getValueFromEvent(ev))
        }>
        <option value="-"> {ReasonReact.string("-")} </option>
        {List.map(
           item => <option value=item> {ReasonReact.string(item)} </option>,
           Belt.Option.getExn(field.options),
         )
         |> Array.of_list
         |> ReasonReact.array}
      </select>
    </label>;
  },
};
