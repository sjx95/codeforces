import Data.Char

main = do
	getLine
	interact $ unlines.map solve.lines

solve :: String -> String
solve s = dispatch $ foldr cvt [] s

cvt :: Char -> [String] -> [String]
cvt c [] = [[c]]
cvt c (x:xs) = if (isDigit c) == ((isDigit.head) x)
									then [[c]++x] ++ xs
									else [[c], x] ++ xs

dispatch :: [String] -> String
dispatch ["R", r, "C", c] = fromRC (read c) "" ++ r
dispatch [c, r] = "R" ++ r ++ "C" ++ (show.toRC) c

fromRC :: Int -> String -> String
fromRC 0 a = a
fromRC i a = fromRC ((i - 1) `div` 26) a ++ [sfRC ((i - 1) `mod` 26)]
	where sfRC x = chr $ ord 'A' + x

toRC :: String -> Int
toRC c = foldl op 0 c
	where op b a = b * 26 + ord a - 64
