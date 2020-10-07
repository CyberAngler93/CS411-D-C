# CS411-D-C

This repository contains the solutions to CS411-HW3 consisting of exercise A contiguous sums and exercise B inverions counting from stable sorts.

## Exercise A

Find the greatest contiguous sum of a list of integers.

### Algorithm

The algorithm is based on Prof. Hartman's notes in the HW pdf:

Here is an idea for an efficient algorithm to find the GCS using
the Divide-and-Conquer strategy. Given a sequence of
numbers, our algorithm computes and returns the following
four values.
A. The GCS of the sequence.
B. The greatest possible sum of a contiguous subsequence
that includes the first value in the sequence, or zero if all
such sums are negative.
C. The greatest possible sum of a contiguous subsequence
that includes the last value in the sequence, or zero if all
such sums are negative.
D. The sum of the entire sequence.

### About 

This algorithm utilizes a data struct to hold the 4 values outlined above.
Using divide and conquer and a combination logic for determining the max utilizing std::max.
The combination logic is as follows:
gcs = left.a or right.a or left.c+right.b
gpsf = left.b or left.d + right.b
rpsl = right.b or right.d + left.b
sum = right.d + left.d

## Exervise B

Find the number of inversions by adding during a stable sort

### Algorithm

The algorithm is based on Prof. Hartman's note sin the HW pdf:

We can design an algorithm to count the inversions in a
sequence based on any stable sort. Whenever the sort moves 
an item x to a different place in the sequence, we count the
number of other items that item x skipped over. The total of all
such counts is the number of inversions.

### About

This algorithm utilizes Dr. Chappell's mergsort with some small modifications. The global using in headers were removed as well as adding in the inversions counter logic to the stable sort.
The inversions can be counter as a distance that they must be moved. Based on this we can count how far things are moved as inversions as long as they are moving to the left.

