mylist(A,[A|L]).
mylist(A,[B|C]) :- myList(A,C).

%append function

myappend(A,[],[A]).
myappend(A,[P|Q],[P|R]) :- myappend(A,Q,R).

%reverse function
myreverse([],[]).
myreverse([A|B],P) :- myreverse(B,R), myappend(A,R,P).

%join list
myjoin([A|[]],C,[A|C]).
myjoin([A|B],C,[A|X]) :- myjoin(B,C,X). 

a(_).
