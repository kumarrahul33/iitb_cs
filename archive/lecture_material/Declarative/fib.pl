myfib(0,0):-!.
myfib(1,1):-!.
myfib(N,S):-N>1,T is N-1,U is N-2,myfib(T,K), myfib(U,L),S is K+L.
