data NestedList a = Element a | SubList [NestedList a] deriving Show


flatten :: [NestedList a] -> [NestedList a]
flatten [] = []
flatten [Element a] = [Element a]
flatten [SubList a] = (flatten a)
flatten list = (flatten [(head list)]) ++ (flatten (tail list))

myreverse :: [NestedList a] -> [NestedList a]
myreverse [] = []
myreverse [Element a] = [Element a]
myreverse [SubList a] = [SubList (myreverse a)]
myreverse list = (myreverse (tail list)) ++ (myreverse [(head list)])

main = do
  print(flatten ([Element 1,Element 3,SubList [Element 4,SubList [SubList [Element 5],SubList []]],Element 6]))
  print(myreverse ([Element 1,Element 3,SubList [Element 4,SubList [SubList [Element 5],SubList []]],Element 6]))
