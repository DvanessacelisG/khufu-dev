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
};

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
    valid: true,
    value: "",
    inputType: "text",
    placeHolder: "Title",
    options: None,
    error: "",
  },
  projectName: {
    label: "Project Name",
    valid: true,
    value: "",
    inputType: "text",
    placeHolder: "Project Name",
    options: None,
    error: "",
  },
  projectStartDate: {
    label: "Project Start Date",
    valid: true,
    value: "",
    inputType: "text",
    placeHolder: "Start Date",
    options: None,
    error: "",
  },
  clientName: {
    label: "Client Name",
    valid: true,
    value: "",
    inputType: "text",
    placeHolder: "CLient Name",
    options: None,
    error: "",
  },
  agu: {
    label: "Agu",
    valid: true,
    value: "",
    inputType: "text",
    placeHolder: "Agu",
    options: None,
    error: "",
  },
  du: {
    label: "Du",
    valid: true,
    value: "",
    inputType: "text",
    placeHolder: "Du",
    options: None,
    error: "",
  },
  grade: {
    label: "Grade",
    valid: true,
    value: "-",
    inputType: "text",
    placeHolder: "Grade",
    options:
      Some([
        "DR (Director)",
        "BD (Business Director)",
        "BM (Business Manager)",
        "SM (Senior Manager)",
        "ML (Manager)",
        "SC (Senior Consultant)",
        "CL (Consultant)",
        "SE (Senior Engineer)",
        "EN (Engineer)",
        "ST (Senior Technician)",
        "TL (Technician)",
        "JT (Junior Technician)",
        "IN (Intern-Bench NC)",
      ]),
    error: "",
  },
  priority: {
    label: "Priority",
    valid: true,
    value: "-",
    inputType: "text",
    placeHolder: "Priority",
    options: Some(["A (High)", "B (Medium)", "C (Low)"]),
    error: "",
  },
  positionBrief: {
    label: "Position Brief",
    valid: true,
    value: "",
    inputType: "text",
    placeHolder: "Position Brief",
    options: None,
    error: "",
  },
  isBench: {
    label: "Is in bench",
    valid: true,
    value: "false",
    inputType: "checkbox",
    placeHolder: "Title",
    options: None,
    error: "",
  },
  projectCode: {
    label: "Project Code",
    valid: true,
    value: "",
    inputType: "text",
    placeHolder: "Project Code",
    options: None,
    error: "",
  },
};

let updateFormState =
    (currentFields: ticketForm, field: ticketFormField, text) => {
  switch (field) {
  | Title => {
      ...currentFields,
      title: {
        ...currentFields.title,
        value: text,
      },
    }
  | ProjectName => {
      ...currentFields,
      projectName: {
        ...currentFields.projectName,
        value: text,
      },
    }
  | ProjectStartDate => {
      ...currentFields,
      projectStartDate: {
        ...currentFields.projectStartDate,
        value: text,
      },
    }
  | ClientName => {
      ...currentFields,
      clientName: {
        ...currentFields.clientName,
        value: text,
      },
    }
  | Agu => {
      ...currentFields,
      agu: {
        ...currentFields.agu,
        value: text,
      },
    }
  | Du => {
      ...currentFields,
      du: {
        ...currentFields.du,
        value: text,
      },
    }
  | Grade => {
      ...currentFields,
      grade: {
        ...currentFields.grade,
        value: text,
      },
    }
  | Priority => {
      ...currentFields,
      priority: {
        ...currentFields.priority,
        value: text,
      },
    }
  | PositionBrief => {
      ...currentFields,
      positionBrief: {
        ...currentFields.positionBrief,
        value: text,
      },
    }
  | IsBench => {
      ...currentFields,
      isBench: {
        ...currentFields.isBench,
        value: text,
      },
    }
  | ProjectCode => {
      ...currentFields,
      projectCode: {
        ...currentFields.projectCode,
        value: text,
      },
    }
  };
};
