member :: Int -> [Int] -> Bool

member n [] = False

member n (x:tail) 
 | (x == n ) = True
 | otherwise = member n tail


main =
 print (member 3 [2,3,33])
