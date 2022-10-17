%if the element is at head, membership is asserted
listmember(X,[X|_]).
listmember(X,[Y|Z]):-listmember(X,Z).
