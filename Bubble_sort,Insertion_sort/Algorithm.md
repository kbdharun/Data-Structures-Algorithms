# Implementation of sorting techniques (Bubble Sort and Insertion Sort)

## Bubble Sort

### Algorithm bubbleSort (list, last)

- *Purpose:* sort an array using bubble sort, Adjacent elements are compared and exchanged until list is completely ordered.
- *Pre:* List must contain at least one item last contains index to last element in
the list.
- *Post:* List has been rearranged in sequence low to high.

1. set current to 0
2. set sorted to false
3. loop (current <= last and sorted false)
	1. Each iteration is one sort pass
	2. set walker to last
	3. set sorted to true
	4. loop (walker >current)
		1. if (walker data < walker-1 data)
			1. set sorted to false
			2. exchange (list,walker,walker-1)
		2. end if
		3. decrement walker
5. end loop
6. increment current
7. end loop

**End bubbleSort**

## Insertion Sort

### Algorithm InsertionSort (list, last)

Sort list array using insertion sort. The array is divided into sorted and
unsorted lists. With each pass, the first element in the unsorted list is inserted
into the sorted list.

- *Pre:*
  - list must contain atleast one element
  - last is an index to last element in
the list
- *Post:* list has been rearranged

1. set current to 1
2. loop (until last element sorted)
	1. move current element to hold
	2. set walker to current-1
	3. loop (walker>=0 and hold key < walker key)
		1. move walker element right one element
		2. decrement walker
	4. end loop
	5. move hold to walker+1 element
	6. increment current
3. end loop

**End InsertionSort**
