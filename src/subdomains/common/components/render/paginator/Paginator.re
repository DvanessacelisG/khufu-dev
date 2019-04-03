[%raw {| require("./Paginator.scss") |}];
let component = ReasonReact.statelessComponent("TicketViewPagination");

let make = (~next, ~prev, ~currentPage: int, _self) => {
  ...component,
  render: _self => {
    <div className="paginator__buttons">
      <a
        className="paginator__prev-button" onClick={_ev => prev()}>
        {ReasonReact.string("Prev")}
      </a>
      <a className="paginator__actual-page">{ReasonReact.string(string_of_int(currentPage))}</a>
      <a
        className="paginator__next-button" onClick={_ev => next()}>
        {ReasonReact.string("Next")}
      </a>
    </div>;
  },
};
