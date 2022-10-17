mylast([A|[]],A).
mylast([A|L],E) :- mylast(L,E).
cutList([A|[]],[]).
cutList([A|B],[A|C]):-cutList(B,C).
appendList(A,B,C):- cutList(C,B),mylast(C,A).


myreverse([A|L],D):- myreverse(L,R),appendList(A,R,D).
myreverse([A|[]],[A]).



