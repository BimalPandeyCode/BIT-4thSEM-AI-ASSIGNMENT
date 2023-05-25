gcd(X, 0, X) :- !.
gcd(X, Y, GCD) :-
    Z is X mod Y,
    gcd(Y, Z, GCD).

lcm(X, Y, LCM) :-
    gcd(X, Y, GCD),
    LCM is abs(X * Y) / GCD.
