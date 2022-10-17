animal(cat).
animal(dog).
animal(rat).
animal(bird).
animal(elephant).
plant(bush).
plant(banana).
eats(cat,rat).
eats(dog,meat).
eats(dog,bird).
eats(cow,bush).
eats(elephant,banana).
herbi(X):-animal(X),plant(Y),eats(X,Y).
carni(X):-animal(X),animal(Y),eats(X,Y).

