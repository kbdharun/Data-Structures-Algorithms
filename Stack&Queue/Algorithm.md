# Demonstration of Stack and Queue operations using array

## Stack operations

### Push

#### Algorithm PushStack( stack, data)

1. if (stack is full)
	1. set success to false
2. else
	1. increment top
	2. store data at stack[top]
	3. set success to true
3. end if
4. return success
**end PushStack**

### Pop

#### Algorithm PopStack (stack, dataOut)

1. if (stack empty)
	1. set success to false
2. else
	1. set dataOut to data in top node
	2. decrement top
	3. set success to true
3. end if
4. return success
   
**End PopStack**

### StackTop

#### Algorithm StackTop (stack, dataOut)

1. if (stack empty)
	1. set success to false
2. Else
	1. set dataOut to data in top node
	2. set success to true
3. end if
4. return success

**End StackTop**

### EmptyStack

#### Algorithm EmptyStack(queue)**

1. if (Top is -1)
	1. set empty to true
2. else
	1. set empty to false
3. end if
4. return empty
**end EmptyStack**

### FullStack

#### Algorithm FullStack(Stack)

1. if (Top equals to MAXSIZE)
	1. set full to true
2. else
	1. set full to false
3. endif
4. return full
**End FullStack**

## Queue operations

### Enqueue

#### Algorithm enqueue(queue, dataIn)

1. if (queue is full)
	1. set success to false
2. else
	1. increment rear
3. set queue[rear] to data in dataIn
4. set success to true
5. return success
**End enqueue**

### Dequeue

#### Algorithm dequeue(queue, dataOut)

1. if (queue is empty)
	1. set success to false
2. else
	1. set dataOut to data in queue[front]
	2. increment front
	3. set success to true
3. end if
4. return success
**End dequeue**

### QueueFront

#### Algorithm QueueFront (queue, dataOut)

1. if (queue empty)
	1. set success to false
2. else
	1. set dataOut to data in front node
	2. set success to true
3. end if
4. return success
**end QueueFront**

### QueueRear

#### Algorithm QueueRear (queue, dataOut)

1. if ( queue empty)
	1. set success to false
2. else
	1. set dataOut to data in Rear node
	2. set success to true
3. end if
4. return success

**End QueueRear**

### EmptyQueue

#### Algorithm EmptyQueue(queue)

1. if (front and rear are -1)
	1. set empty to true
2. else
	1. set empty to false
3. end if
4. return empty
**end EmptyQueue**

### FullQueue

#### Algorithm FullQueue(queue)

1. if (rear equals to MAXSIZE)
	1. set full to true
2. else
	1. set full to false
3. endif
4. return full

**End FullQueue**

### QueueCount

#### Algorithm QueueCount(Queue)

1. if (Queue Empty)
	1. Display ‘Queue is Empty’
	2. Return
2. else
	1. Return rear – front + 1
3. endif

**End Display**
