let component = ReasonReact.statelessComponent("InputFieldRender");

let styleModifiers = (field: FormField.field): string => {
  field.valid ?
    "create-ticket__field" : "create-ticket__field create-ticket__field--error";
};

let getValueFromEvent = (event): bool => {
  (event |> ReactEventRe.Form.target |> ReactDOMRe.domElementToObj)##checked;
};

let make =
    (
      ~field: FormField.field,
      ~fieldName: Ticket.ticketFormField,
      ~update,
      _self,
    ) => {
  ...component,
  render: _self => {
    <label className={styleModifiers(field)}>
      {ReasonReact.string({field.label})}
      <input
        type_={field.inputType}
        placeholder={field.placeHolder}
        value={field.value}
        onChange={ev =>
          update(fieldName: Ticket.ticketFormField, string_of_bool(getValueFromEvent(ev)))
        }
      />
    </label>;
  },
};