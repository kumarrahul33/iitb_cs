pushback(E,[],[E]).
pushback(E,[A|B],[A|C]) :- pushback(E,B,C). 

