# OS Lab

Small C exercises exploring processes, `fork()`, pipes, and file I/O.

## Programs

### July 31
- [Child prints numbers; parent waits](July31/child_print_numbers_parent_wait.c)
- [Child Fibonacci; parent factorial](July31/child_fibonacci_parent_factorial.c)
- [Create three child processes](July31/create_three_child_processes.c)
- [Fork: parent and child messages](July31/fork_parent_child_messages.c)
- [Orphan process demonstration](July31/orphan_process_demo.c)
- [Parent and child PIDs/PPIDs](July31/parent_child_pid_ppid.c)
- [Parent prints evens; child prints odds](July31/parent_even_child_odd.c)
- [Parent reads child exit status](July31/parent_reads_child_exit_status.c)
- [Parent sum, child Fibonacci, grandchild factorial](July31/parent_sum_child_fibonacci_grandchild_factorial.c)
- [Zombie process demonstration](July31/zombie_process_demo.c)

### August 7
- [Child Fibonacci; parent Armstrong numbers](August7/child_fibonacci_parent_armstrong_numbers.c)
- [Child checks prime; parent calculates factorial](August7/child_prime_parent_factorial.c)

### August 17
- [Child sums an array and checks whether the sum is prime](August17/child_sum_array_check_prime.c)
- [Array sum and prime-check variant](August17/child_sum_array_check_prime_variant.c)

### September 18
- [Parent writes a file; child reads it](September18/parent_write_child_read_file.c)
- [Parent sums an array; child checks primality via pipe](September18/parent_sum_array_child_check_prime_pipe.c)

### September 25
- [Child sends even numbers to parent through a pipe](September25/child_write_even_numbers_pipe.c)
- [Pipe example with child exit-status checking](September25/child_write_even_numbers_pipe_wait_status.c)
- [Zombie process placeholder (empty)](September25/zombie_process_demo.c)
  # Operating Systems Lab Programs in C

This repository contains a structured collection of C programs demonstrating core Operating Systems concepts. Topics include process management, inter-process communication (IPC), file handling, CPU scheduling, and memory page replacement algorithms.
# Operating Systems Lab Programs in C

A collection of C programs covering process management, inter-process communication (IPC), file handling, CPU scheduling, and page replacement algorithms.

---

### July 31
- [Child prints numbers; parent waits](July31/child_print_numbers_parent_wait.c)
- [Child Fibonacci; parent factorial](July31/child_fibonacci_parent_factorial.c)
- [Create three child processes](July31/create_three_child_processes.c)
- [Fork: parent and child messages](July31/fork_parent_child_messages.c)
- [Orphan process demonstration](July31/orphan_process_demo.c)
- [Parent and child PIDs/PPIDs](July31/parent_child_pid_ppid.c)
- [Parent prints evens; child prints odds](July31/parent_even_child_odd.c)
- [Parent reads child exit status](July31/parent_reads_child_exit_status.c)
- [Parent sum, child Fibonacci, grandchild factorial](July31/parent_sum_child_fibonacci_grandchild_factorial.c)
- [Zombie process demonstration](July31/zombie_process_demo.c)

### August 7
- [Child Fibonacci; parent Armstrong numbers](August7/child_fibonacci_parent_armstrong_numbers.c)
- [Child prime check; parent factorial](August7/child_prime_parent_factorial.c)

### August 17
- [Child sums array and checks prime](August17/child_sum_array_check_prime.c)
- [Child sums array and checks prime (variant)](August17/child_sum_array_check_prime_variant.c)

### Process Communication
- [Pipe: parent and child communication](02_Process_Communication/01_pipe_parent_child.c)
- [Pipe: array sum and prime check](02_Process_Communication/02_array_sum_prime_pipe.c)
- [FIFO (named pipe) writer](02_Process_Communication/03_fifo_writer.c)
- [FIFO (named pipe) reader](02_Process_Communication/04_fifo_reader.c)
- [Message queue sender](02_Process_Communication/05_message_sender.c)
- [Message queue receiver](02_Process_Communication/06_message_receiver.c)
- [Shared memory writer](02_Process_Communication/07_shared_writer.c)
- [Shared memory reader](02_Process_Communication/08_shared_reader.c)
- [String permutations](02_Process_Communication/09_string_permutations.c)

### File Handling
- [Child writes even numbers; parent reads](03_File_Handling/01_child_write_even_parent_read.c)
- [Child opens file](03_File_Handling/02_child_open_file.c)
- [Parent writes to file; child reads](03_File_Handling/03_parent_write_child_read.c)

### CPU Scheduling
- [First-Come, First-Served (FCFS)](04_CPU_Scheduling/01_fcfs.c)
- [Shortest Job First (SJF) – Non-Preemptive](04_CPU_Scheduling/02_sjf_non_preemptive.c)
- [Priority Scheduling – Non-Preemptive](04_CPU_Scheduling/03_priority_non_preemptive.c)

### Page Replacement
- [First-In, First-Out (FIFO)](05_Page_Replacement/01_fifo.c)
- [Least Recently Used (LRU)](05_Page_Replacement/02_lru.c)


---

## 📁 Repository Structure

### 1. Process Management & `fork()` Basics
Organized by lab session dates, these programs explore process creation, parent-child synchronization, and process states.

#### 📅 July 31
* **`fork_parent_child_messages.c`** – Demonstrates basic `fork()` usage where parent and child processes print separate messages.
* **`parent_child_pid_ppid.c`** – Prints the Process ID (`PID`) and Parent Process ID (`PPID`) for both parent and child processes.
* **`child_print_numbers_parent_wait.c`** – Uses `wait()` to ensure the parent waits until the child finishes printing a sequence of numbers.
* **`parent_reads_child_exit_status.c`** – Shows how a parent process captures and reads the exit status of a terminated child process.
* **`create_three_child_processes.c`** – Spawns three distinct child processes from a single parent process.
* **`parent_even_child_odd.c`** – Splits tasks so the parent prints even numbers while the child prints odd numbers.
* **`child_fibonacci_parent_factorial.c`** – Concurrent execution where the child generates a Fibonacci series and the parent computes a factorial.
* **`parent_sum_child_fibonacci_grandchild_factorial.c`** – Multi-level process hierarchy involving a parent (sum), child (Fibonacci), and grandchild (factorial).
* **`orphan_process_demo.c`** – Simulates an orphan process by terminating the parent before the child finishes execution.
* **`zombie_process_demo.c`** – Simulates a zombie process where a child terminates but remains in the process table until reaped.

#### 📅 August 7
* **`child_fibonacci_parent_armstrong_numbers.c`** – Child process generates Fibonacci numbers while the parent checks for Armstrong numbers.
* **`child_prime_parent_factorial.c`** – Child process checks for prime numbers while the parent calculates factorials.

#### 📅 August 17
* **`child_sum_array_check_prime.c`** – Child process calculates the sum of an array and checks whether the total is a prime number.
* **`child_sum_array_check_prime_variant.c`** – An alternative implementation for summing an array and verifying primality in a child process.

---

### 2. Inter-Process Communication (`02_Process_Communication`)
Programs demonstrating how independent or related processes exchange data.

* **`01_pipe_parent_child.c`** – One-way data transfer between a parent and child process using an unnamed `pipe()`.
* **`02_array_sum_prime_pipe.c`** – Sends array data or results through a pipe to compute sums and check for prime numbers.
* **`03_fifo_writer.c`** – Writes data into a named pipe (FIFO) for another process to consume.
* **`04_fifo_reader.c`** – Reads data transmitted through a named pipe (FIFO).
* **`05_message_sender.c`** – Sends structured messages to a System V/POSIX message queue.
* **`06_message_receiver.c`** – Retrieves and displays messages from a message queue.
* **`07_shared_writer.c`** – Allocates a shared memory segment and writes data into it.
* **`08_shared_reader.c`** – Attaches to an existing shared memory segment to read the stored data.
* **`09_string_permutations.c`** – Generates string permutations, often paired with process or IPC exercises.

---

### 3. File Handling (`03_File_Handling`)
Programs illustrating concurrent file access and system-level file operations across processes.

* **`01_child_write_even_parent_read.c`** – Child writes even numbers to a file, and the parent reads the contents back.
* **`02_child_open_file.c`** – Demonstrates file opening and descriptor behavior inside a forked child process.
* **`03_parent_write_child_read.c`** – Parent writes data to a file, and the child reads from it after synchronization.

---

### 4. CPU Scheduling Algorithms (`04_CPU_Scheduling`)
Simulations of standard OS process scheduling algorithms to calculate waiting and turnaround times.

* **`01_fcfs.c`** – First-Come, First-Served (FCFS) non-preemptive scheduling simulation.
* **`02_sjf_non_preemptive.c`** – Shortest Job First (SJF) non-preemptive scheduling simulation.
* **`03_priority_non_preemptive.c`** – Priority-based non-preemptive scheduling simulation.

---

### 5. Page Replacement Algorithms (`05_Page_Replacement`)
Memory management simulations tracking page hits and page faults.

* **`01_fifo.c`** – First-In, First-Out (FIFO) page replacement algorithm.
* **`02_lru.c`** – Least Recently Used (LRU) page replacement algorithm.

---

## 🚀 How to Compile and Run

These programs are designed for **Linux / Unix** environments using `gcc`.

1. **Navigate to a directory:**
   ```bash
   cd 04_CPU_Scheduling
