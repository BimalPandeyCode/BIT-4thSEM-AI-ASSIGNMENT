roman(X) :- pompeian(X).
roman(X) :- loyal_to_caesar(X).
roman(X) :- hated_caesar(X).

loyal_to_caesar(X) :- roman(X), \+ hated_caesar(X).
hated_caesar(X) :- roman(X), \+ loyal_to_caesar(X).

pompeian(marcus).
tried_to_assassinate(marcus, caesar).

did_hate(X, Y) :- tried_to_assassinate(X, Y).

did_hate(marcus, caesar) :-
    pompeian(marcus),
    roman(marcus),
    \+ loyal_to_caesar(marcus),
    tried_to_assassinate(marcus, caesar).
