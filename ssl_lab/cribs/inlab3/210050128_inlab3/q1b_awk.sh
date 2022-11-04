awk 'function parseWord() {
	for(i = 1; i <= NF; i++) {
		wordCount[$i] = wordCount[$i] + 1
	}
}

BEGIN {
}
{

parseWord()

}
END{
	for(var in wordCount) {
		print(var," ",wordCount[var])
	}
}' *.txt | sort
