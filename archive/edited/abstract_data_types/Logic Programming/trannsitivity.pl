r(a,b).
r(b,c).
r(c,d).
r(d,e).
r1(X,Y):-r(X,Y).
r1(X,Y):-r(X,Z),r(Z,Y).
