member(P,[P|L]).
member(P,[Q|L]):-member(P,L).
