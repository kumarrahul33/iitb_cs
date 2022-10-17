myfact(0,1):-!.
myfact(N,S):-N>0, T is N-1, myfact(T,U), S is N*U.
