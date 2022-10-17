fact(N,S):-N>0, T is N-1, fact(T,U), S is N*U.
fact(0,1).
fact(1,1).
