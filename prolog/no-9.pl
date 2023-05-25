mammal(horse).
mammal(cow).
mammal(pig).

offspring(X, Y) :- parent(Y, X).

parent(bluebeard, charlie).

has_parent(X) :- mammal(X).

is_horse(X) :- offspring(bluebeard, X).
is_horse(X) :- offspring(Y, X), is_horse(Y).
