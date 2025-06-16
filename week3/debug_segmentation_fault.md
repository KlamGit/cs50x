## Segmentation Fault
# A segmentation fault (or "segfault") occurs when your program tries to access memory it doesn’t have permission to use. In my linear_string.c case, the issue was in the loop condition:

'''
for (int i = 0; i < sizeof(strings); i++)

'''

sizeof(strings) returns the total bytes of the array, not the number of elements.
Since strings[] is an array of pointers (string is an alias for char *), sizeof(strings) gives:

    8 elements × 8 bytes (on 64-bit systems) = 64 bytes.

My loop ran 64 times instead of 8, causing it to read invalid memory (strings[8] to strings[63]), leading to the crash.

How to Fix It
Option 1: Use sizeof with division (best for static arrays)
'''

int size = sizeof(strings) / sizeof(strings[0]);  // Correctly computes 8
for (int i = 0; i < size; i++)

'''

Why it works:

    1. sizeof(strings) = 64 (total bytes).
    2. sizeof(strings[0]) = 8 (size of one char * pointer).
    3. 64 / 8 = 8 (the actual number of elements).

## Why My Expected Output Didn’t Happen

The segfault crashed the program before reaching printf("Not found").
After fixing the loop, searching for "oops" will correctly return:

    Not found

## Key Takeaways
1. sizeof(array) returns bytes, not elements.
    - Use sizeof(array) / sizeof(array[0]) for element count.
2. Segfaults happen when accessing invalid memory.
    - Here, the loop went out of bounds.
3. Test edge cases:
    - Empty input, non-existent words, and exact matches.