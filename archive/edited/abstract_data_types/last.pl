mylast([A|[]],A).
mylast([A|L],E) :- mylast(L,E).



