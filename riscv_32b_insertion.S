    .data
array:  .word 8, 5, 3, 7, 2, 6, 4, 1  # Array of 8 elements to be sorted
n:      .word 8                       # Number of elements in the array

    .text
    .globl _start

_start:
    la      t0, array          # Load the address of the array into t0
    lw      t1, n              # Load the size of the array into t1
    addi    t1, t1, -1         # Decrease size by 1 for loop boundary

# Outer loop: Iterate over the array starting from the second element
outer_loop:
    addi    t2, t0, 4          # t2 = t0 + 4, pointer to the second element
    addi    t3, t0, 4          # t3 = t0 + 4, pointer to the current element
    beq     t1, zero, done     # If array size is zero, exit

    lw      t4, 0(t2)          # Load current element into t4

# Inner loop: Compare the current element with the previous elements
inner_loop:
    lw      t5, -4(t2)         # Load the previous element into t5
    blt     t5, t4, insert     # If t5 < t4, go to insert
    sw      t5, 0(t2)          # Otherwise, shift the element to the right
    addi    t2, t2, -4         # Move to the previous element
    bne     t2, t0, inner_loop # Repeat until the start of the array

# Insert the element in the correct position
insert:
    sw      t4, 0(t2)          # Place t4 in its correct position

# Move to the next element in the array
    addi    t3, t3, 4          # t3 = t3 + 4, move to the next element
    addi    t1, t1, -1         # Decrease the counter
    bnez    t1, outer_loop     # If there are elements left, continue sorting

done:
    # Exit the program (using ecall)
    li      a7, 10             # Exit system call number
    ecall                       # Make the system call

