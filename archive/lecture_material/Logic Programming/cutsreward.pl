btech(tikku).
btech(ronu).
btech(pinki).
chessplayer(dillis).
chessplayer(pinki).
footballplayer(ronu).
athelete(pinki).
sportsperson(X):-chessplayer(X).
sportsperson(X):-footballplayer(X).
sportsperson(X):-athelete(X).
getsreward(X):-btech(X),sportsperson(X),!.
