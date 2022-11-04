



function compute() {
	base = 8+2*(NR%3)
	loopCount = NF-1
	finalAns = 0
	for(i=1; i<=NF; i++){
		finalAns = finalAns + data[$i]*(base^loopCount)
		loopCount = loopCount - 1
	}
	print(finalAns)
	
}

BEGIN {
	data[1] = 1
	data[2] = 2
	data[3] = 3
	data[4] = 4
	data[5] = 5
	data[6] = 6
	data[7] = 7
	data[8] = 8
	data[9] = 9
	data["a"] = 10
	data["b"] = 11
	data["c"] = 12
	data["d"] = 13 
	data["e"] = 14 
	data["f"] = 15
	data["g"] = 16
	data["h"] = 17
	data["i"] = 18
	data["j"] = 19
	data["k"] = 20
	data["l"] = 21
	data["m"] = 22
	data["n"] = 23
	data["o"] = 24
	data["p"] = 25
	data["q"] = 26
	data["s"] = 27
	data["t"] = 28
	data["u"] = 29
	data["v"] = 30
	data["w"] = 31
	data["x"] = 32
	data["y"] = 33
	data["z"] = 34

}

{
	compute()
}

END{
	} 















