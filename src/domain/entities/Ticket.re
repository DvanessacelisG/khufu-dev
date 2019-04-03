type ticketForm = {
  title: FormField.field,
  projectName: FormField.field,
  projectStartDate: FormField.field,
  clientName: FormField.field,
  agu: FormField.field,
  du: FormField.field,
  grade: FormField.field,
  priority: FormField.field,
  positionBrief: FormField.field,
  isBench: FormField.field,
  projectCode: FormField.field,
};

type ticket = {
  title: string,
  projectName: string,
  projectStartDate: string,
  clientName: string,
  agu: string,
  du: string,
  grade: string,
  priority: string,
  positionBrief: string,
  isBench: bool,
  projectCode: string,
}

type ticketFormField =
  | Title
  | ProjectName
  | ProjectStartDate
  | ClientName
  | Agu
  | Du
  | Grade
  | Priority
  | PositionBrief
  | IsBench
  | ProjectCode;

type ticketsList = {tickets: list(ticket)};

let defaultValues: ticketForm = {
  title: {
    label: "Position Title",
    valid: false,
    value: "string",
    inputType: "text",
    placeHolder: "Title",
    options: None,
    error: "string",
  },
  projectName: {
    label: "Project Name",
    valid: false,
    value: "string",
    inputType: "text",
    placeHolder: "Project Name",
    options: None,
    error: "string",
  },
  projectStartDate: {
    label: "Project Start Date",
    valid: false,
    value: "string",
    inputType: "text",
    placeHolder: "Start Date",
    options: None,
    error: "string",
  },
  clientName: {
    label: "Client Name",
    valid: false,
    value: "string",
    inputType: "text",
    placeHolder: "CLient Name",
    options: None,
    error: "string",
  },
  agu: {
    label: "Agu",
    valid: false,
    value: "string",
    inputType: "text",
    placeHolder: "Agu",
    options: None,
    error: "string",
  },
  du: {
    label: "Du",
    valid: false,
    value: "string",
    inputType: "text",
    placeHolder: "Du",
    options: None,
    error: "string",
  },
  grade: {
    label: "Grade",
    valid: false,
    value: "string",
    inputType: "text",
    placeHolder: "Grade",
    options: None,
    error: "string",
  },
  priority: {
    label: "Priority",
    valid: false,
    value: "string",
    inputType: "text",
    placeHolder: "Priority",
    options: None,
    error: "string",
  },
  positionBrief: {
    label: "Position Brief",
    valid: false,
    value: "string",
    inputType: "text",
    placeHolder: "Position Brief",
    options: None,
    error: "string",
  },
  isBench: {
    label: "Is in bench",
    valid: false,
    value: "string",
    inputType: "checkbox",
    placeHolder: "Title",
    options: None,
    error: "string",
  },
  projectCode: {
    label: "Project Code",
    valid: false,
    value: "string",
    inputType: "text",
    placeHolder: "Project Code",
    options: None,
    error: "string",
  }
};

let updateFormState =
    (currentFields: ticketForm, field: ticketFormField, text) => {
  switch (field) {
  | Title => {...currentFields, title: {...currentFields.title,  value: text}}
  | ProjectName => {...currentFields, projectName: {...currentFields.projectName,  value: text}}
  | ProjectStartDate => {...currentFields, projectStartDate: {...currentFields.projectStartDate,  value: text}}
  | ClientName => {...currentFields, clientName: {...currentFields.clientName,  value: text}}
  | Agu => {...currentFields, agu: {...currentFields.agu,  value: text}}
  | Du => {...currentFields, du: {...currentFields.du,  value: text}}
  | Grade => {...currentFields, grade: {...currentFields.grade,  value: text}}
  | Priority => {...currentFields, priority: {...currentFields.priority,  value: text}}
  | PositionBrief => {...currentFields, positionBrief: {...currentFields.positionBrief,  value: text}}
  | IsBench => {...currentFields, isBench: {...currentFields.isBench,  value: text}}
  | ProjectCode => {...currentFields, projectCode: {...currentFields.projectCode,  value: text}}
  };
};
