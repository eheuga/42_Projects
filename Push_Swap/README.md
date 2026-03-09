# Push Swap - K-Sort (Chunk Sort)

## About
This is my first implementation of the push_swap project.
I chose to implement a chunk-based sorting algorithm before moving on to a more optimized approach.

## How it works

### Indexing
Before sorting, all values are replaced by their rank (0 to N-1).
This makes the algorithm work with any range of integers.

### Phase 1 - Push to B by chunks
The indices are divided into chunks of equal size.
For each chunk, instead of blindly rotating, `find_closest_in_chunk` finds
the element of the current chunk that is closest to the top of the stack,
whether from the top (ra) or from the bottom (rra).
This avoids unnecessary rotations.

### Phase 2 - Push back to A
Once all elements are in B, `push_max` brings them back to A
by always pushing the maximum value, using rb or rrb depending
on which is closer.

### Small cases
- 2 values : sa
- 3 values : hardcoded cases
- 4 values : push min → sort 3 → pa
- 5 values : push 2 mins → sort 3 → pa x2

## Performance
| Input size | Operations | 42 limit |
|------------|------------|----------|
| 100 values | ~750 ops   | 700      |
| 500 values | ~7300 ops  | 5500     |

The 500 values benchmark does not reach the bonus score.
This is why I moved on to the Turkish sort algorithm (see `turkish-sort` branch).

## Why I moved on
The chunk sort has a structural limitation — it optimizes chunk by chunk
without a global view of the cost. The Turkish sort fixes this by calculating
the exact cost of every possible move at each step.

## What I learned
- Linked list manipulation in C
- Stack operations (push, rotate, reverse rotate)
- Chunk-based sorting logic
- Cost optimization with ra/rra selection