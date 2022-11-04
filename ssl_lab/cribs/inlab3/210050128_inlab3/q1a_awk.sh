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
		count++
	}
	print(count)
}' *.txt 
