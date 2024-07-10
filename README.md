# Untangling Conway Rational Knot

## Basic Concept

The basic idea of Conway Rational Knot is that tangles can be representated as a fraction (from now on, I will use the term tangle-number), and tangles with same tangle-number is isomorphic.

Let's say we have four points A, B, C, D at left top corner, left bottom corner, right top corner, and right bottom corner. Initial status, where tangle-number is 0, is a situation where A and C, B and D are each connected to a string without entanglement.

From here, we can apply either T operation or R operation. Here is what they will do:
- T operation grabs end of the string in left bottom, and moves it to the left top side.
  - Tangle-number is increased by 1, and can be denoted as T(x)=x+1
- R operation will turn everything 90 degrees clockwise.
  - Tangle-number becomes negative reciprocal, and can be denoted as R(x)=-1/x

Now to untangle any knot, we can just apply series of operations that makes the initial tangle-number back to 0. Here's an example:

Let's say we have a knot with tangle-number of -5/2. Applying TTTRTT will make this number 0 (-5/2 -> -3/2 -> -1/2 -> 1/2 -> -2 -> -1 -> 0), so applying them will untangle the knot.

## Solution Algorithm

After some trials and errors, I have found this algorithm where you can apply to any initial tangle-number to make it 0:

- If tangle-number is greater than 0: Apply R
- If tangle-number is less than 0: Apply T

We can iterate this process until tangle-number becomes 0.
