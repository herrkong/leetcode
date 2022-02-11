package main

import (
	"fmt"
	"sort"
	//"github.com/goombaio/orderedmap"
	//"github.com/goombaio/orderedset"
)

// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["KFC", "Shogun", "Burger King"]

func main() {
	var list1 = []string{"Shogun", "Tapioca Express", "Burger King", "KFC"}
	var list2 = []string{"KFC", "Shogun", "Burger King"}
	r := findRestaurant(list1, list2)
	fmt.Println(r)
}

func findRestaurant(list1 []string, list2 []string) []string {
	idx_map := map[int][]string{}

	//ordered_map := orderedmap.NewOrderedMap()
	//odered_set := orderedset.NewOrderedSet()

	for idx1, name1 := range list1 {
		for idx2, name2 := range list2 {
			if name1 == name2 {
				idx_map[idx1+idx2] = append(idx_map[idx1+idx2], name1)
			}
		}
	}

	if len(idx_map) == 0 {
		return nil
	}

	index_sum := make([]int, 0, len(idx_map))

	for k := range idx_map {
		index_sum = append(index_sum, k)
	}
	sort.Ints(index_sum)

	return idx_map[index_sum[0]]
}
