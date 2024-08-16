# CS 695 Assignment 2 
## Linux Kernel Modules
#### (Shivansh Dhiman - 22m2120)
___


## LKM-1
- Output from the module:
```
    [ 6103.881956] Printing running and runnable processes
    [ 6103.881971] 6822     sudo
    [ 6103.881972] 6823     insmod
    [ 6111.465315] Exiting module
```
- In this question, we use `task_struct` structure to get the state of the process. Since at the time of running this, the only two processes in RUNNING and RUNNABLE state are `sudo` and `insmod`, only these two get printed from the module.


## LKM-2
- Output from the module:
```
    [ 6568.325969] Task with maximum heap size is:
    [ 6568.325971] PID: 800
    [ 6568.325972] Heap size: 187281
    [ 6572.583789] Exiting module
```
- In this question, we use `task_struct` and `mm_struct` structures to get the heap memory bounds of the processes. Out of all the processes, the one with highest usage of heap memory is printed along with the size of heap memory.


## LKM-3
- Output from the module:
```
    [ 7240.890629] PID: 1
    [ 7240.890632] Process name: systemd
    [ 7240.890633] Kernel Stack pointer: 0000000057ae7162
    [ 7247.500238] Exiting module
```
- In this question, `task_struct` structure is used to get the kernel stack pointer of the process with PID=1, i.e, `init` process.


## LKM-4
- Output from the module:
```
    [  262.837685] PID:1
    [  262.837687] Virtual addr:    0x55c431a710b2
    [  262.837688] Physical addr:   0x11ea1d0b2
    [  264.275515] Exiting module
```
- In this question, a page-table walk is performed to get the physical address from a virtual memory address of a given process. Structures like `pgd`, `p4d`, `pud`, `pmd` and `pte` represent various levels of the page table and the page table entry. After this, offset is calculated and added to the physical frame address to get the physical memory address.


## LKM-5
- Output from the module before the array is created:
```
    [ 5383.441381] Virtual address space: 6189056
    [ 5383.441384] Physical address space: 1994752
    [ 5387.978531] Exiting module
```
- Output from the module after the array is initialized:
```
    [ 5395.843778] Virtual address space: 46190592
    [ 5395.843780] Physical address space: 1994752
    [ 5396.961575] Exiting module
```
- Output from the module after the array is looped over:
```
    [ 5403.296180] Virtual address space: 46190592
    [ 5403.296183] Physical address space: 43442176
    [ 5404.907910] Exiting module
```
- Yes! It can seen in the output that, only when the array is looped over, the physical memory of that process increases dramatically. This proves that Linux implements lazy memory allocation.

