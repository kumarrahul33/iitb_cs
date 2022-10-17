course(DistributedSystems).
course(AdvancedStatistics).
course(OpticalNetworks).
course(Combinatorics).
selectelective(X,Y):-course(X),course(Y).

