let component = ReasonReact.statelessComponent("InputFieldRender");

let styleModifiers = (field: FormField.field): string => {
  field.valid ?
    "create-ticket__field" : "create-ticket__field create-ticket__field--error";
};

let getValueFromEvent = (event): string =>
  (event |> ReactEventRe.Form.target |> ReactDOMRe.domElementToObj)##value;

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
          update(fieldName: Ticket.ticketFormField, getValueFromEvent(ev))
        }
      />
    </label>;
  },
};
