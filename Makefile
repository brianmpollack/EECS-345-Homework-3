all: part1 part2 part3

part1: doubly_linked_list.c
	gcc -o part1 doubly_linked_list.c -Wno-int-to-void-pointer-cast

part2: part_2_haskell_types.hs
	ghc -o part2 part_2_haskell_types.hs

part3: part_3_haskell_monads.hs
	ghc -o part3 part_3_haskell_monads.hs

clean:
	-rm part1
	-rm part2
	-rm part3
