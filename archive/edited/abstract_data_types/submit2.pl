mylast([A|[]],A).
mylast([A|L],E) :- mylast(L,E).

cutList([A|[]],[]).
cutList([A|B],[A|C]):-cutList(B,C).

pushback(A,B,C):- cutList(C,B),mylast(C,A).


myreverse([A|L],D):- myreverse(L,R),pushback(A,R,D).
myreverse([A|[]],[A]).

equal([A|L],[A|L]).

myappend([A],B,[A|B]).
myappend([A|B],[C|D],[A|E]) :- myappend(B,[C|D],E).

palindrome(A) :- myreverse(A,B),equal(A,B).
