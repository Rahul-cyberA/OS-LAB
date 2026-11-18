# OS Lab Practical Checklist

The programs are written in basic C with straightforward loops, arrays, functions and system calls. They are separate implementations based on the practical topics and question sheets in the reference repository.

## Process management
- [x] Display process ID and parent process ID.
- [x] Use fork() to identify parent and child.
- [x] Demonstrate wait() with a child printing numbers.
- [x] Parent prints even numbers and child prints odd numbers.
- [x] Find odd and even sums using fork().
- [x] Child prints Fibonacci and parent calculates factorial.
- [x] Child checks prime and parent calculates factorial.
- [x] Create three child processes.
- [x] Read a child's exit status using wait().
- [x] Demonstrate an orphan process.
- [x] Demonstrate a zombie process.
- [x] Execute the date command using fork(), exec() and wait().
- [x] Child prints Fibonacci and parent prints Armstrong numbers.

## File handling
- [x] Child writes even numbers to a file and parent reads them.
- [x] Child opens and reads a file.

## Inter-process communication
- [x] Pipe: send a message from parent to child.
- [x] Pipe: send an array sum to child and check whether it is prime.
- [x] FIFO / named pipe (writer and reader).
- [x] Message queue (sender and receiver).
- [x] Shared memory (writer and reader).
- [x] Print string permutations in a child process.

## CPU scheduling
- [x] FCFS.
- [x] SJF (non-preemptive, all arrival times treated as zero).
- [x] Priority (non-preemptive, smaller number means higher priority).

## Page replacement
- [x] FIFO.
- [x] LRU.
