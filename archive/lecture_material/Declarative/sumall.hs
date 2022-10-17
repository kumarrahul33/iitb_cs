sumall(l) 
 | (l==[]) = 0
 | otherwise = head(l)+sumall(tail(l))

main =
 print(sumall([1,2,3]))
