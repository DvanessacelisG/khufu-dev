let nonEmptyValidation = (value: string) => {
  String.length(String.trim(value)) > 0 ? true : false;
};

let noDefaultValidation = (value: string) => {
  value == "-" ? false : true;
};

let isValidDate = (value: string) => {
  !Js.Float.isNaN(Js.Date.parseAsFloat(value));
};

let basicValidations = (ticket: Ticket.ticketForm) => {
  ticket.title.valid
  && ticket.du.valid
  && ticket.grade.valid
  && ticket.priority.valid;
};

let isBenchValidations = (ticket: Ticket.ticketForm) => {
  ticket.projectName.valid
  && ticket.projectCode.valid
  && ticket.clientName.valid
  && ticket.agu.valid
  && ticket.projectStartDate.valid;
};

let validateTicket = (ticket: Ticket.ticketForm): (bool, Ticket.ticketForm) => {
  let newTicket = {
    ...ticket,
    title: {
      ...ticket.title,
      valid: nonEmptyValidation(ticket.title.value),
    },
    du: {
      ...ticket.du,
      valid: nonEmptyValidation(ticket.du.value),
    },
    grade: {
      ...ticket.grade,
      valid: noDefaultValidation(ticket.grade.value),
    },
    priority: {
      ...ticket.priority,
      valid: noDefaultValidation(ticket.priority.value),
    },
  };

  if (ticket.isBench.value === "false") {
    (basicValidations(newTicket), newTicket);
  } else {
    let validatedTicket = {
      ...newTicket,
      projectName: {
        ...newTicket.projectName,
        valid: nonEmptyValidation(newTicket.projectName.value),
      },
      projectCode: {
        ...newTicket.projectCode,
        valid: nonEmptyValidation(newTicket.projectCode.value),
      },
      clientName: {
        ...newTicket.clientName,
        valid: nonEmptyValidation(newTicket.clientName.value),
      },
      agu: {
        ...newTicket.agu,
        valid: nonEmptyValidation(newTicket.agu.value),
      },
      projectStartDate: {
        ...newTicket.projectStartDate,
        valid: isValidDate(newTicket.projectStartDate.value),
      },
    };
    (
      basicValidations(validatedTicket) && isBenchValidations(validatedTicket),
      validatedTicket,
    );
  };
};
