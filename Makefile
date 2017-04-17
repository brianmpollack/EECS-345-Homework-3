all: part1 part2

part1: doubly_linked_list.c
	gcc -o part1 doubly_linked_list.c -Wno-int-to-void-pointer-cast

part2: part_2_haskell_types.hs
	ghc -o part2 part_2_haskell_types.hs

clean:
	-rm part1
	-rm part2
