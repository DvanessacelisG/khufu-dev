type ticketForm = {
  title: string,
  discipline: string,
  projectName: string,
  grade: string,
  projectRole: string,
  priority: string,
  numberPositions: string,
  recruiter: string,
};
type ticketFormField =
  | Title
  | Discipline
  | ProjectName
  | Grade
  | ProjectRole
  | Priority
  | NumberPositions
  | Recruiter;
type ticketsList = {tickets: list(ticketForm)};
