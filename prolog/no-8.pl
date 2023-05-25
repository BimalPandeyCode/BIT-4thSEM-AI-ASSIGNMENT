% Predicates to solve the 8-queen problem
solve_queens(Board) :-
    length(Board, 8),    % Board is a list of 8 rows
    place_queens(Board).

place_queens([]).
place_queens([Row|Rest]) :-
    place_queens(Rest),
    member(Row, [1, 2, 3, 4, 5, 6, 7, 8]),
    is_safe(Row, Rest, 1).

is_safe(_, [], _).
is_safe(Row, [PrevRow|Rest], ColDiff) :-
    Row #\= PrevRow,                        % Queens in different rows
    Row + ColDiff #\= PrevRow,               % Queens not on the same upward diagonal
    Row - ColDiff #\= PrevRow,               % Queens not on the same downward diagonal
    NextColDiff is ColDiff + 1,
    is_safe(Row, Rest, NextColDiff).

% Predicate to display the solution
display_solution([]).
display_solution([Row|Rest]) :-
    display_row(Row),
    display_solution(Rest).

display_row(Row) :-
    display_row_helper(1, Row).

display_row_helper(9, _) :-
    write('|'), nl.
display_row_helper(Col, Row) :-
    (Col == Row -> write('|Q'); write('|_')),
    NextCol is Col + 1,
    display_row_helper(NextCol, Row).
