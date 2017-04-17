data SubList a = Element a | SubList [SubList a] deriving Show

main = do
  print([Element 1,Element 3,SubList [Element 4,SubList [SubList [Element 5],SubList []]],Element 6])
