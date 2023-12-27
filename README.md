# cpp_05_09
C++ Module Projects. This collection of projects is designed to help to learn and practice Object-Oriented Programming concepts using C++. These projects are specifically configured to compile using the C++98 standard.

## ex02. Merge-insert sort or Ford-Johnson algorithm for _n_ elements:
1. Make pairwise comparisons of ⌊n/2⌋ (if number of elements is odd, leave one element out)
2. Sort the ⌊n/2⌋ larger numbers, using merge-insert sort (recursively)
3. Create a sorted sequence of ⌊n/2⌋ in ascending order
4. Insert at the start of this sequence the element that was paired with first and the smallest element
  and put in second sequence unpair element from step 1, if it exists
5. Insert the remaining elements in special order, using binary search in sorted array in range from 1 to (2<sup>k</sup>)-1 elements

   Use this for calculating this order:
     t<sub>k</sub> = (2<sup>k+1</sup> + (-1)<sup>k</sup>) / 3,

     where t<sub>k</sub> is index of element from which a new insertion group starts (if we consider that index starts from 1)

     Insertion goes in this order:
   b<sub>t<sub>k-1</sub>+1</sub>, b<sub>t<sub>k-1</sub>+2</sub> ...
