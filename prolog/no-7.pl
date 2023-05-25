calculate :-
    write('Enter the first number: '),
    read(X),
    write('Enter the second number: '),
    read(Y),
    sum(X, Y),
    difference(X, Y),
    product(X, Y),
    division(X, Y).

sum(X, Y) :-
    Sum is X + Y,
    write('Sum: '),
    write(Sum),
    nl.

difference(X, Y) :-
    Diff is X - Y,
    write('Difference: '),
    write(Diff),
    nl.

product(X, Y) :-
    Prod is X * Y,
    write('Product: '),
    write(Prod),
    nl.

division(X, Y) :-
    Y =\= 0,
    Div is X / Y,
    write('Division: '),
    write(Div),
    nl.
division(_, 0) :-
    write('Cannot divide by zero.'),
    nl.
