mylast([A|[]],A).
mylast([A|L],E) :- mylast(L,E).
cutList([A|[]],[]).
cutList([A|B],[A|C]):-cutList(B,C).

myappend(A,B,C):- cutList(C,B),mylast(C,A).






