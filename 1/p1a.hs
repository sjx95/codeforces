main = do
	interact $ show.solve.map read.words

solve [m, n, a] = (m `div` a + fromEnum (m `mod` a > 0)) * (n `div` a + fromEnum (n `mod` a > 0))
