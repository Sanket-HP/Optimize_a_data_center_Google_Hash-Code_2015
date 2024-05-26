# Optimize_a_data_center_Google_Hash-Code_2015

# Problem Overview
You are given a schema of a data center and a list of available servers. The data center is structured into rows, each row containing slots where servers can be placed. Some slots may be unavailable. Servers are also logically divided into pools, and your task is to assign each server to a slot and a pool such that the lowest guaranteed capacity of any pool is maximized. The guaranteed capacity of a pool is the minimum capacity it maintains when any single row fails.

# Key Concepts
1. Rows and Slots:

- The data center is divided into rows (R), each with a number of slots (S).
- Some slots may be unavailable (U), specified by their row and slot indices.
  
2. Servers:

- Each server has a size (number of consecutive slots it occupies) and a capacity (amount of computing resources it provides).
- Servers need to be assigned to specific slots within rows without overlapping unavailable slots or extending beyond the row boundaries.
  
3. Pools:

- Servers are assigned to pools (P).
- The goal is to distribute servers across different rows such that if any single row fails, the loss of capacity is minimized.
  
# Input Format
- The input consists of multiple lines in a text file:
- The first line contains five integers: R, S, U, P, M (number of rows, slots per row, number of unavailable slots, number of pools, and number of servers, respectively).
- The next U lines contain the coordinates of the unavailable slots.
- The following M lines contain the size and capacity of each server.

# Example Input
2 5 1 2 5
0 0
3 10
3 10 
2 5 
1 5
1 1

# Output Format
- The output is a plain text file with M lines, each containing either:
- Three integers: the row index, the slot index (starting slot of the server), and the pool index.
- A single 'x' if the server is not allocated.
  
# Example Output
0 1 0
1 0 1
1 3 0
0 4 1
x












































