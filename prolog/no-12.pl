autocrat(X) :- greedy_leader(X).
evil(X) :- autocrat(X).

greedy_leader(shyam).
honest_leader(gopal).

is_evil(X) :- evil(X), greedy_leader(X).
