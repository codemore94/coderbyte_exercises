.data
    INF:        .word 0x7FFFFFFF           # Infinity
    numVertices: .word 4                    # Number of vertices
    dist:       .space 16                  # Distance array (4 vertices)
    adjMatrix:  .word 0, 1, INF, 4          # Adjacency matrix row 1
                 .word INF, 0, 2, 5         # Adjacency matrix row 2
                 .word INF, INF, 0, 3       # Adjacency matrix row 3
                 .word INF, INF, INF, 0     # Adjacency matrix row 4
    visited:    .space 4*4                  # Visited array

.text
.global _start

_start:
    li t0, 0              # t0 = source vertex
    la t1, dist           # t1 = address of dist array
    la t2, adjMatrix      # t2 = address of adjMatrix
    la t3, visited        # t3 = address of visited array
    li t4, 4              # t4 = number of vertices (numVertices)

    # Initialize dist array
init_dist:
    li t5, INF            # Load INF value
    sw t5, 0(t1)          # dist[i] = INF
    addi t1, t1, 4        # Move to next dist[i]
    addi t0, t0, 1        # Increment vertex index
    bne t0, t4, init_dist # Loop until all vertices are initialized

    li t0, 0              # t0 = source vertex
    la t1, dist           # Reset t1 to start of dist array
    sw zero, 0(t1)        # dist[src] = 0

    # Initialize visited array to 0
init_visited:
    sw zero, 0(t3)        # visited[i] = 0
    addi t3, t3, 4        # Move to next visited[i]
    addi t0, t0, 1        # Increment vertex index
    bne t0, t4, init_visited # Loop until all vertices are initialized

    # Main loop
main_loop:
    li t6, INF            # t6 = min_distance = INF
    li t7, -1             # t7 = u = -1
    la t1, dist           # Reset t1 to start of dist array
    la t3, visited        # Reset t3 to start of visited array

find_min:
    lw t8, 0(t1)          # t8 = dist[i]
    lw t9, 0(t3)          # t9 = visited[i]
    beq t9, zero, not_visited
    j skip
not_visited:
    blt t8, t6, update_min
    j skip
update_min:
    mv t6, t8             # min_distance = dist[i]
    mv t7, t0             # u = i
skip:
    addi t1, t1, 4        # Move to next dist[i]
    addi t3, t3, 4        # Move to next visited[i]
    addi t0, t0, 1        # Increment vertex index
    bne t0, t4, find_min  # Loop until all vertices checked

    # If u == -1, all vertices processed
    li t0, -1
    beq t7, t0, end

    # Mark u as visited
    la t3, visited
    slli t7, t7, 2        # t7 = u * 4
    add t3, t3, t7        # &visited[u]
    li t0, 1
    sw t0, 0(t3)          # visited[u] = 1

    # Relaxation step for all vertices adjacent to u
    la t1, adjMatrix
    la t2, dist
    slli t7, t7, 2        # t7 = u * 4 * numVertices
    add t1, t1, t7        # &adjMatrix[u]
    la t3, dist

relax:
    lw t8, 0(t1)          # adjMatrix[u][i]
    lw t9, 0(t2)          # dist[i]
    beq t8, t5, skip_relax # If edge doesn't exist, skip
    add t10, t6, t8       # new_dist = dist[u] + weight(u, i)
    blt t10, t9, update_dist
    j skip_relax
update_dist:
    sw t10, 0(t2)         # dist[i] = new_dist
skip_relax:
    addi t1, t1, 4        # Move to next adjMatrix[u][i]
    addi t2, t2, 4        # Move to next dist[i]
    addi t0, t0, 1        # Increment vertex index
    bne t0, t4, relax     # Loop until all vertices relaxed

    j main_loop

end:
    # End program (In real code, you'd print or handle results)
    li a0, 10             # Syscall for exit
    ecall
