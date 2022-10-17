%[] is a list builder
%[X|_]  means X is head and the tail is anonymous in this list
listlen([],0).
listlen([X|Y],L):-listlen(Y,Tmp),L is Tmp+1.
