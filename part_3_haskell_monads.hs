myfunction :: a -> Maybe [a] -> (a -> Bool) -> Maybe [a]
myfunction x v f = do
    v1 <- v
    if (f x) then return (x : v1)
        else Nothing

checklist [] f = Just []
checklist ls f = (myfunction (head ls) (checklist (tail ls) f) f)

checkappend v1 v2 f = do
    vo1 <- v1
    vo2 <- v2
    if (checklist vo1 f) == Nothing then Nothing
        else return (vo1 ++ vo2)

main = do
  print(checklist "aaaaa" (\x -> x == 'a'))
  print(checklist "abcde" (\x -> (x >= 'a' && x <= 'z')))
  print(checklist "abcDe" (\x -> (x >= 'a' && x <= 'z')))
  print(checklist [1,-2,3] (\x -> x > 0))
  print(checkappend (Just [1,1,1]) (checkappend (Just [2,3,4]) (Just [8,9]) (\v -> v >= 0)) (\v -> v == 1))
  print(checkappend (Just [1,1,1]) (checkappend (Just [2,3,4]) (Just [8,9]) (\v -> v <= 0)) (\v -> v == 1))
