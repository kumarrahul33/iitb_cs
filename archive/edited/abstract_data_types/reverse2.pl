mylast([A|[]],A).
mylast([A|L],E) :- mylast(L,E).
reversal([A|L],[U|A]):-reversal(L,U).
reversal([A|[]],A).

