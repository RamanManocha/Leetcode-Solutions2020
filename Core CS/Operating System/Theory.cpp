


https://towardsdatascience.com/all-you-should-know-about-operating-systems-in-technical-interviews-4dcc55210fea


All You Should Know About Operating Systems in Technical Interviews
A complete guide to handle common operating system problems in technical interviews
Jack Tsai
Jack Tsai

Nov 9, 2020·11 min read



Photo by Markus Spiske on Unsplash
“Are you ready for the interview now?”
“Yes, of course.”
“Great. Could you please tell me about your understanding of operating systems?”
“Umm…Umm...”
“Okay, thanks for your time today. Please wait for our further notice in the next few days.”
Does this seem similar to you?
Don’t give up. You definitely can do it better.
Here are some common operating system problems you would face in technical interviews. You can follow this guide to learn operating systems from scratch and clearly explain them to your interviewer.
1. What are operating systems?
The definition of operating systems can be divided into three parts:
An operating system provides an interface for users to interact with the computer hardware.
An operating system (OS) is a program managing hardware and software resources of the computer.
An operating system is structured by a kernel and some other basic components. In general, the kernel is a bridge between applications and hardware. It is responsible for managing stuff like process, internal memory, file, and network, which has the direct access to hardware and maintains stability and performance of the system.








Operating system architecture. Image by Author
2. How do users access computer resources?
The computer operation can be divided into two modes:
User mode: The process under this level can only access the data that users provide.
Kernel mode: The process under this level has complete access to computer hardware and can execute some special operations of the machine (e.g. I/O).
The typical applications often run under the user mode. When there is a demand for service under kernel mode, a system call should be issued. It is a request asking kernel process to execute functions such as device management, file management, process management, and memory management.
The scope of user & kernel mode
The scopes of user & kernel mode (Image by Author)
3. What is the difference between processes and threads?
In short, a process is an active program. It can generate multiple threads while executing. Processes are usually independent of each other, but threads are not necessary. Processes will lead to more overhead, but are also more convenient for the management, and threads are just the opposite.
Take JVM process as an example, threads inside are sharing global variables such as heap space and method area (metaspace), but the Program Counter Register, JVM stack, and native method stack are private.














JVM process structure (Image by Author)
4. What are states of the process?
There are 7 states of the process, which are:
New: The process is creating.
Ready: The process is ready to run, i.e., it is waiting the resources (e.g. time slices) from the processor.
Run: The process is currently running under the CPU. Only one process is allowed at a time.
Wait (or Block): The process is paused and waiting for the required resources to be available.
Complete (or Terminated): The process has finished executing. It might be interrupted by some reasons or normal exit.
Suspended Ready: The process is suspended while the ready queue is full.
Suspended Block: The process is suspended while the waiting queue is full.







Process lifecycle (Image by Author)
5. What is context switching? When will it happen?
Context switching means saving the running process state and loading the state of another process. This usually happens while a higher-priority process comes into the ready state or an interrupt occurs.
6. What is a race condition?
A race condition happens while more than one process are sharing the same code or resources. In this case, an unexpected result might occur as each process could access the shared variables at any time.
7. How do processes communicate with each other?
There are six ways of inter-process communications (IPC):
Pipe: It enables the output of a process become the input of another process that has a common origin, i.e., the same process. The data flow by using pipe is one direction only (e.g., command “|” in Linux).
Names pipe: This allows communication of processes from different origin. It follows first in first out (FIFO) rules.
Message queueing: Both types of pipes are inefficient as the process that sends data into the buffer needs to wait until another process retrieves it. Message queueing is able to solve this problem, which producers do not need to wait for consumers retrieving data.
Shared memory: There is also a disadvantage of message queueing, which is time-consuming while the size of sending data is too large. Hence an idea of shared memory came up. It allows multiple processes access the same area of memory. This is the most efficient way as each process can see the update of data immediately.
Semaphore: The biggest issue of shared memory is that multiple processes will compete for resources. Semaphore is a program counter used in process synchronization to control the number of processes accessing shared memory and avoid race condition. It represents how much resources are available in shared memory.
Socket: All communication methods mentioned above are based on only one device. Socket is an interface which allows communicating between multiple device remotely. It is mainly used in the client/server communication.





8. How do threads synchronize with each other?
The purpose of thread synchronization is similar to inter-process communication, which avoid competing shared resources between concurrent threads. There are three common ways of thread synchronization:
Mutex: It is a mechanism of mutual exclusion. Mutex only allows one thread accesses the shared resources at a time (e.g., synchronized in Java).
Semaphore: It is quite similar to mutex, but its value could be larger than 1 and allows multiple threads enter shared resources at a time.
Event: It remains thread synchronization by notification (wait/notify).





9. How does the CPU schedule processes?
There are several CPU scheduling algorithms in order to achieve maximum CPU utilization:
First Come First Serve (FCFS): Allocate resources to a process within the ready queue that requests the CPU first. It is a non-preemptive algorithm (the scheduled process will run until completed or blocked).
Shortest Job First (SJF): Allocate resources to a process within the ready queue that has shortest execution time. It is a non-preemptive algorithm. Besides, there is also a longest job first (LJF) scheduling algorithm.
Shortest Remaining Time First (SRTF): Allocate resources to a process within the ready queue that has shortest remaining execution time. It is a preemptive algorithm (the scheduled process can be preempted while a higher priority process enters). There is also a longest remaining time first (LRTF) scheduling algorithm.
Round Robin: Each process is allocated to a given time called time slice and executes until the time runs out.
Priority Based: Each process is assigned with a given priority. The higher the priority, the earlier to be selected.
Multilevel Queue: Processes are allocated in different queues in terms of their priority. Processes in lower level queues are allowed to execute until the processes in higher level queues are completed.
Multilevel Queue Feedback: This is the scheduling algorithm used in the UNIX system, which allows processes moving between each level queue. The process will be moved to the lower level queue if it costs too much execution time.








10. How does the memory model designed in operating systems?
There are two types of memory in operating systems:
Primary memory (internal memory): CPU registers, cache memory and main memory, which are directly accessible by the processor.
Secondary memory (external memory): different types of disk (magnetic, optical), which are some storage devices that can accessed by the processor through I/O.

Operating system memory model (Image by Author)
11. How does memory management work in operating systems?
The memory management of operating systems is responsible for allocating memory to processes, including converting logical addresses into physical addresses or swapping processes between internal and external memory.
12. What are virtual address and physical address?
Take a common example, the pointer concept we see in some programming languages stores the virtual address of memory, which is decided by operating systems. The physical address is the address in physical memory, i.e., memory address registers.

Virtual address (Image by Author)
Modern processors use virtual addressing technique to translate a virtual address into a physical address via MMU (memory management unit). The process of virtual addressing is shown in the image below:
13. How do operating systems allocate memory?
There are four types of common memory allocation techniques:
Partitioned allocation: Divide memory by blocks and each of them contains one process. Space would be wasted if the process only needs a small memory to run. This is a contiguous allocation as those blocks are consecutive in memory.
Paged memory management: Divide memory by page frames, which are units smaller than blocks. This increases the use of memory and reduces internal fragmentation. It is non-contiguous allocation as page frames are allowed to be separated. Paged tables are used to map virtual addresses to physical addresses.
Segmented memory management: Divide memory by segments, which are logical groups of the data or code. It is non-contiguous allocation as segments are allowed to be separated. Segment tables are used to map virtual addresses to physical addresses.
Segmentation with paging: Combines the advantages of paged and segmented memory management. It divides memory by several segments, then separates each segment into several page frames.

  
  
  
14. What is TLB (Translation Lookaside Buffer)?
In paged memory management, there are two issues need to be handled:
The virtual-to-physical mapping should be fast.
The page table will become larger while the virtual address space is large.
TLB could be applied to speed up the transition between virtual and physical memory. It could be regarded as a cache, which stores a part of the data in a page table. With this cache, we only need to access the main memory once instead of twice while executing I/O.
The process of translating a virtual address into a physical address is:
Search for the page number inside TLB.
If the given page is found, read the corresponding physical address from the TLB.
If the given page cannot be found, read the corresponding physical address inside the page table and store it into TLB.
Eliminate a page inside TLB by certain strategies while it is full.
  
  
  
  
  
15. What is a multilevel page table?
Besides speeding up mapping, we can use a multilevel page table to handle the issue caused by the large virtual address space. It avoids always placing all the page tables in main memory, which could save up more space.

  
  
 16. What is virtual memory?
This is common while the memory cost of a software exceeds the space of a computer. The reason why this can be implemented is because of the virtual memory. It divides a program into several pieces and allows them to be temporarily stored in the external memory (disk) before the program needs it. By doing this, the program will regard itself to own a piece of continuous space.
17. How to implement virtual memory?
There are two common types of virtual memory implementation:
Demand paging: It is based on the paging technique and has the page replacement function. If we cannot find the required page before a process starts, the operating system will search it in the secondary memory and swap the page found in the main memory depending on the given page replacement algorithm.
Demand segmentation: It is a technique similar to demand paging. The only difference between them is that demand segmentation swap segments instead of pages into the main memory depending on the given segment replacement algorithm.
18. What is the page replacement algorithm?
Page fault happens while a required page is not in the main memory. And we need page replacement algorithms to swap the page from the secondary memory into the main memory. Some common types of page replacement algorithms are listed below:
Optimal page replacement: Replace the page that is no longer used or will not be used for the longest time. This will ensure the lowest possibility of the page fault existence. However, OPT replacement cannot be achieved so far as people cannot predict which page will not be used again in the future.
FIFO (First-In-First-Out) page replacement: Eliminate the page that stays in the main memory for the longest time.
LRU (Least Recently Used) page replacement: Eliminate the page with the longest elapsed time since it was last accessed.
LFU (Least Frequently Used) page replacement: Eliminate the least used page in a period of time.
19. What is deadlock in operating systems?
Deadlock is a situation when more than two processes are waiting for the resource holding by each other, but no one is going to release first.
Deadlock will appear if the system satisfies all of the following conditions:
Mutual exclusion: Only one process is allowed to access at a time.
Hold & wait: A process is holding a resource that might be required by others, and also waiting for resources holding by others.
No preemption: A resource cannot be accessed by other processes unless the owner process releases it.
Circular wait: Each of the processes is waiting for the resource holding by another process.

Deadlock example (Image by Author)
20. How to handle deadlock?
There are three methods to handle deadlock:
Deadlock prevention and avoidance: Deadlock is not allowed and should be prevented or avoided.
Deadlock prevention is to eliminate one of the deadlock conditions mentioned above as a deadlock will occur once four of them are all met.
Deadlock avoidance is a technique to test whether each of the requests sent by processes will cause a deadlock state.
Deadlock detection and recovery: Deadlock is allowed. Preempt the process once a deadlock has been detected.
Ignore problems: Simply reboot the system while deadlock is rare.
