father(dasharath,rama).
father(janak,sita).
father(rama,luv).
grandfather(X,Y):-father(Z,X),father(Y,Z).

likes(mary,chocolates).
likes(dolly,dollars).
likes(john,movies).
likes(don,cars).
likes(john,X):-likes(X,chocolates).
likes(don,X):-likes(X,mary).


mother(sita,luv).

married(X,Y):-mother(X,C),father(Y,C).

%the below tries symmetric relation but gets into infinite recursion
%married(X,Y):-married(Y,X).

% this is a solution
married(X,Y):-mother(Y,C),father(X,C).


