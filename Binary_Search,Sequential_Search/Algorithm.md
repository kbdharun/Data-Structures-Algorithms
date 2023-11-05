# Implementation of searching techniques (Sequential search, Binary search)

## Sequential Search

### Algorithm seqSearch (list, last, target, locn)

- *Purpose:* Locate the target in an unordered list of elements.
- *Pre:* list must contain at least one element
  - last is index to last element in the list target contains the data to be located
  - locn is address of index in calling algorithm
- *Post:* if found: index stored in locn & found true
  - if not found: last stored in locn & found false
  - Return found true or false

1. set looker to 0
2. loop (looker < last AND target not equal list[looker])
	1. increment looker
3. end loop
4. set locn to looker
5. if (target equal list[looker])
	1. set found to true
6. else
	1. set found to false
7. end if
8. return found

End **seqSearch**

### Algorithm recursiveSeqSearch(list, index, last, locn, target)

- *Purpose:* Locate the target in an unordered list of elements.
- *Pre:* list must contain at least one element
  - index is the first element in the list
  - last is index to last element in the list
  - target contains the data to be located
  - locn is address of index in calling algorithm
- *Post:* if found: index stored in locn & found true

if not found: last stored in
	locn & found false Return found true or false
1. if(index>last)
	1. locn=-1
	2. return flase
2. end if
3. if(target==list[index])<br>
	1.locn= index<br>
	2.return true
4. end if
5. return recursiveSeqSearch (list, index+1, last, locn, target)

**End recursiveSeqSearch**

## Binary Search

### Algorithm binarySearch (list, last, target, locn)

- *Purpose:* Search an ordered list using Binary Search
- *Pre:* list is ordered; it must have at least 1 value
  - last is index to the largest element in the list
  - target is the value of element being sought
  - locn is address of index in calling algorithm  
- *Post:* if target found: locn assigned index to target element
  - if target not found: locn assigned
  - element below or above target
- *Return :* found as true or false

1. set begin to 0
2. set end to last
3. loop (begin <= end)
	1. set mid to (begin + end) / 2
	2. if (target > list[mid])
		1. set begin to (mid + 1)
	3. else if (target < list[mid])
		1. set end to mid - 1
	4. else
		1. set begin to (end + 1)
	5. end if
4. end loop
5. set locn to mid
6. if (target equal list [mid])
	1. set found to true
7. else
	1. set found to false
8. end if
9. return found

**End binarySearch**

### Algorithm recursiveBinarySearch (list, first, last, target, locn)

- *Purpose:* Search an ordered list using Binary Search
- *Pre:* list is ordered; it must have at least 1 value
  - first is index to the smallest element in the list
  - last is index to the largest element in the list
  - target is the value of element being sought
  - locn is address of index in calling algorithm
- *Post:* if target found: locn assigned index to target element
  - if target not found: locn assigned element below or above target
- *Return :* found as true or false

1. if last > first then
	1. locn=-1
	2. return false
2. else
	1. mid = (first + last) / 2
	2. if target< list[mid] then
		1. return recursiveBinarySearch (list, first, mid-1, target,locn)
	3. else if target >list[mid] then
		1. return recursiveBinarySearch (list, mid+1, last, target,locn)
	4. else
		1. locn=mid
		2. return true
	5. end if
3. end if

**End recursiveBinarySearch**
