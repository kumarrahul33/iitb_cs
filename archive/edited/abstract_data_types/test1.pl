person(john).
person(bob).
person(reena).
person(leena).

mother(leena,reena).
father(bob,john).
father(reena,bob).

grandfather(X,Y):-person(X),person(Y),mother(X,Z),father(Z,Y).
grandfather(X,Y):-person(X),person(Y),father(X,Z),father(Z,Y).
