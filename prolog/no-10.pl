criminal(X) :- american(X), sells_weapons(X, Y), hostile(Y).

american(george).

sells_weapons(george, Y) :- country(Y), enemy(Y, america).

hostile(Y) :- missile(Y).

missile(iraq).

enemy(iraq, america).

country(iraq).
