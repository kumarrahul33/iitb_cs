mylast([A|[]],A).
mylast([A|L],E) :- mylast(L,E).
cutList([A|[]],[]).
cutList([A|B],[A|C]):-cutList(B,C).
appendList(A,B,C):- cutList(C,B),mylast(C,A).


reversal([A|L],D):- reversal(L,R),appendList(A,R,D).
reversal([A|[]],[A]).

equal([A|L],[A|L]).

palindrome(A) :- reversal(A,B),equal(A,B).

