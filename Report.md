Siddharth Kakked
CS 5008
Fall 2025

# Report for Data Structure Speed Comparison Homework

Make sure to answer every question in this homework. You should not bullet point your answers, but
instead write them as a full report format. This doesn't mean you have to be wordy, as concise is good,
but it does mean you need to use proper grammar, spelling, and be complete. For question that just
ask for a short answer, answer accordingly. Make sure to include references where appropriate.

## Algorithmic Analysis - Big $O$

Complete the Big O table below for the following functions. You may use any resource you like, but
for the SortedVector and SortedList, you should use the Big O for the functions you wrote in the
the homework. Both Single and Double Linked List you can assume head and tail pointers are available. 
Don't forget to use latex math notation (example in the table).

### Big $O$ Table

| -                         | Add/Insert        | Remove            | Search/Find       | Sort              | Add Front    | Add Back     | Remove Front | Remove Back  | Get by Index |
| ------------------------- |:-----------------:|:-----------------:|:-----------------:|:-----------------:|:------------:|:------------:|:------------:|:------------:|:------------:|
| Vector                    | $O(n)$            | $O(n)$            | $O(n)$            | $O(n \log n)$     | $O(n)$       | $O(1)^*$     | $O(n)$       | $O(1)$       | $O(1)$       |
| Single Linked List        | $O(n)$            | $O(n)$            | $O(n)$            | $O(n \log n)$     | $O(1)$       | $O(1)$       | $O(1)$       | $O(n)$       | $O(n)$       |
| Double Linked List        | $O(n)$            | $O(n)$            | $O(n)$            | $O(n \log n)$     | $O(1)$       | $O(1)$       | $O(1)$       | $O(1)$       | $O(n)$       |
| Sorted Vector             | $O(n)$            | $O(n)$            | $O(\log n)$       | $O(n)$            | ---          | ---          | ---          | ---          | ---          |
| Sorted Single Linked List | $O(n)$            | $O(n)$            | $O(n)$            | $O(n)$            | ---          | ---          | ---          | ---          | ---          |
| Sorted Double Linked List | $O(n)$            | $O(n)$            | $O(n)$            | $O(n)$            | ---          | ---          | ---          | ---          | ---          |
| Binary Search Tree        | $O(\log n)^{**}$  | $O(\log n)^{**}$  | $O(\log n)^{**}$  | $O(n)$            | ---          | ---          | ---          | ---          | ---          |


For Sort, we are asking for the Big $O$ for taking the current data structure and writing it 'sorted' to a file. However, not the file writes. For example, if you have a vector of 1000 elements, and you want to write it to a file, you would need to sort it first. So, the Big $O$ for this would be the Big $O$ for sorting. For BST, you have to convert the tree to a sequential structure, so the cost of doing that.  

### Assumptions with Sort

Since the worst case can change considerably based on what sort you use for sorting (if any), list each algorithm below, and specify the algorithm used in your assumption.  For BST, write which  method of traversal you would use to sort it.  

* Vector: $O(nlogn)$ (mergesort)
* Single Linked List: $O(n log n)$ (mergesort)
* Double Linked List: $O(n log n)$ (mergesort)
* Sorted Vector - already sorted: $O(n)$
* Sorted Single Linked List - already sorted: $O(n)$
* Sorted Double Linked List - already sorted: $O(n)$
* Binary Search Tree:  In-order traversal produces sorted output - $O(n)$

### Worst Case vs. Average Case

There are a few functions whose worse case is very different than the average case. Name at least two of them, and explain why the worse case is so much worse than the average case. 

1. Binary Search Tree Operations (Add/Remove/Search)
   
   Average Case: $O(log n)$ 
   
   Worst Case: $O(n)$

   Binary Search Tree operations (add, remove, and search) achieve $O(log n)$ complexity in the average case when the tree is balanced. However, the worst case slows to $O(n)$ when inserting already-sorted data like 1, 2, 3, 4, 5, which creates a completely unbalanced tree resembling a linked list. This causes operations to traverse all n nodes instead of just the logarithmic height.

2. Quicksort 

   Average Case: $O(n log n)$

   Worst Case: $O(n^2)$

   When the pivot selections result in relatively balanced partitions, the recursion tree has logarithmic depth with O(n) work at each level and when the pivot is consistently the smallest or largest element, the partitions become extremely unbalanced. This creates a recursion depth of n with O(n) work at each level, resulting in quadratic time.


## Empirical Analysis - Speed Comparison

For this section, you will need to have run the speed compare program and generated the output into a CSV file.

### Empirical Results Table

Add a link from this document to the CSV file you generated. The CSV file must have at least 15 different N values, but
often can have a lot more depending on what you ran. 

  > CSV file 10k: [results_10k.csv](https://github.com/CS5008Fall2025/homework-speed-comparison-skakked/blob/main/results_10k.csv)

   > CSV file 100k: [results_100k.csv](https://github.com/CS5008Fall2025/homework-speed-comparison-skakked/blob/main/results_1000000.csv)

### Analysis

Create *at least three* graphics that each visually explain an aspect of your data related to an operation or data structure. Under each one, explain what the graphic is showing, and what you can conclude from it/what you find interesting about it.

> [!IMPORTANT]
> 
> Make sure you are comparing apples to apples and not apples to oranges when choosing what to put in the same graph. 
> 
> **:x: different data structures *and* different operations**
> 
> - Vector Add Front versus BST Add
> 
> **:white_check_mark: different operations *but* same data structure**
> 
> - BST Add versus Remove, and Search for BST
> 
> **:white_check_mark: different data structures *but* same operation**
> 
> - BST Add versus Add for Sorted Vector, and Sorted Single/Double Linked List
> 
> - Vector Add Front versus Add Front for Single/Double Linked List

> [!TIP]
> 
> To create the graphics you can use a third party program like Microsoft Excel or Google Sheets. (Completely optional if you want extra coding: you can use python libraries such as matplotlib, seaborn, or plotly)
> 
> Make sure you can see the image embedded in the Report.md using [image markdown] when you upload it to github, and get help if it doesn't show! 

#### Graphic 1 Insertion Performance Comparision
![Insertion Performance Graph](https://github.com/CS5008Fall2025/homework-speed-comparison-skakked/blob/main/Files/Insertion%20Performance%20Comparision.png)

> This graph compares insertion performance for Sorted Vector, Linked List, and BST. The three structures show distinctly different growth patterns. BST maintains a nearly flat line around 0.002 seconds throughout the dataset range. In contrast, both Sorted Vector and Linked List exhibit steep upward curves, reaching approximately 0.16 and 0.15 seconds respectively at N=10,000. The curves for Sorted Vector and Linked List track closely together, suggesting similar algorithmic complexity despite their different underlying structures. The visual separation between BST's flat trajectory and the curved growth of the sequential structures indicates BST scales more favorably as dataset size increases.


#### Graphic 2 Removal Performance Comparison
![Removal Performance Graph](https://github.com/CS5008Fall2025/homework-speed-comparison-skakked/blob/main/Files/Removal%20Performance%20Comparision.png)

> This graph illustrates removal performance across the three sorted structures. Three distinct performance tiers are visible: BST maintains a nearly horizontal line at approximately 0.002 seconds, Sorted Vector shows moderate upward growth reaching 0.018 seconds at N=10,000, and Sorted List exhibits the steepest growth curve climbing to 0.20 seconds.

#### Graphic 3 Search Performance Comparison
![Removal Performance Graph](https://github.com/CS5008Fall2025/homework-speed-comparison-skakked/blob/main/Files/Search%20Performance%20Comparision.png)


> This graph presents search performance across the three structures, revealing the most pronounced performance differences of the three operations. BST and Sorted Vector both produce nearly flat lines that remain close to the x-axis throughout the dataset range, hovering around 0.002 seconds. Linked List search, however, shows a steep linear climb reaching approximately 0.23 seconds at N=10,000.

## Critical Thought

### Data Evaluation

Answer the questions below. Make sure to answer each question fully, and explain your reasoning. Indent your answers immediately below the question, for it to line up with the bullet point.

For example:

```markdown
1. What is the most surprising result from the data? Why is it surprising?
   Answer here
```

1. What is the most surprising result from the data? Why is it surprising?
   
   The most surprising result is how closely the Sorted Vector and Sorted Linked List perform for insertion operations, despite their very different internal structures. This is surprising because, in theory, a linked list should benefit from $O(1)$ insertions once the position is found, whereas a vector (array) requires $O(n)$ shifting of elements. However, in both structures, the dominant cost comes from finding the correct sorted position $(O(n))$, so the structural advantage of the linked list doesn’t meaningfully improve total insertion time at these data sizes.

2. What data structure is the fast at adding elements (sorted)? Why do you think that is?
   
   The Binary Search Tree (BST) is the fastest at adding elements when maintaining sorted order. A balanced BST can insert elements in approximately $O(log n)$ time because it uses structural ordering rather than searching through all elements. The vector and linked list both require a linear search $(O(n))$ to find the correct insertion point, making them slower as $n$ increases.


3. What data structure is the fastest at removing elements (sorted)? Why do you think that is?

   The BST is also the fastest at removing elements in sorted order. Removal in a balanced BST typically involves $O(log n)$ search and local restructuring. In contrast, vectors require shifting elements $(O(n))$, and linked lists require traversal to find the target node $(O(n))$, even though the removal itself is $O(1)$ once found.


4. What data structure is the fastest at searching? Why do you think that is?

   Sorted Vector is fastest at searching, completing lookups in 0.027 seconds at N = 99,999, slightly outperforming the BST’s 0.044 seconds. While both support $O(log n)$ searches, vectors leverage contiguous memory.

5. What data structure is the fastest for adding elements to the front? Why do you think that is?

   Linked List is the fastest for adding elements to the front, requiring only 0.006 seconds at N = 99,999 compared to 3.65 seconds for Vector. This is because a linked list simply allocates a new node and updates a single head pointer (an $O(1)$ operation).

6. What data structure is the fastest for adding elements to the back? Why do you think that is?

   Vector slightly outperforms the Linked List for adding to the back, taking 0.0007 seconds versus 0.0015 seconds at N = 99,999. Both structures support amortized $O(1)$ insertion, but vectors benefit from contiguous memory, which improves cache efficiency and allows quick appends until a resize is required.


7. What data structure is the fastest for removing elements from the front? Why do you think that is?

   Linked List is fastest for removing elements from the front, taking 0.004 seconds at N = 99,999 compared to 3.94 seconds for Vector. The list simply updates its head pointer and frees the first node (an $O(1)$ operation). Vectors, however, must shift all remaining elements left, performing n – 1 copy operations, making this an $O(n)$ task.

8. What data structure is the fastest for removing elements from the back? Why do you think that is?

   The Vector is the fastest data structure for removing elements from the back, taking 0.00027 seconds at N = 99,999 compared to the Linked List’s 32.30 seconds. This is because removing the last element from a vector is an $O(1)$ operation. It decrements the size counter without reallocating memory.

### Deeper Thinking

#### Double Linked List vs Single Linked List

1. If you wrote your linked list as a single linked list, removing from the back was expensive. If you wrote it as a double linked list, removing from the back was cheap. Why do you think that is?

   In a singly linked list, even with a tail pointer, you cannot access the node before the tail because you can only traverse forward. You must walk through all n-1 nodes from the head to find the second-to-last node to update its next pointer. A doubly linked list has prev pointers, so you can directly access tail->prev, making removal $O(1)$ instead of $O(n)$.

2. When running most functions, at least ~30% of the tests were worse case scenarios. Why do you think that is? 

   With random selection of movies for operations, approximately 30% of items statistically fall in the last third of the data structure. These require near-maximum traversal in linear structures, creating worst-case scenarios. It's a natural result of uniform random distribution across all positions.

3. What was done in the code to encourage that? 

   The code likely uses random movie selection rather than always picking the first element or following a predictable pattern. This could be implemented by generating random indices or shuffling the movie list before operations.

4. How did this particularly influence the linked list searches?
   
   For linked lists with 30% of searches targeting the last third, these operations require traversing 70,000-99,999 nodes in a list of 99,999 elements. Since linked lists must check every node sequentially without the ability to skip ahead, this 30% of expensive operations dramatically increases average search time, contributing to the 45+ second search times observed.



#### Test Bias

1. The tests were inherently biased towards the BST to perform better due the setup of the experiment. Explain why this is the case.  (hint: think about the randomization of the data, and the worst case scenario for BST).

   The tests are biased toward BST because the movie data is randomized during insertion. Random insertion order keeps a BST relatively balanced, maintaining $O(log n)$ performance. If movies were inserted in alphabetical order (sorted), the BST would degenerate into a linked list with $O(n)$ operations, performing terribly. The random data order prevents this worst-case scenario.

2. What would generate the worst case scenery for a BST?

   The worst case for BST occurs when data is inserted in sorted order (ascending or descending). For example, inserting movies alphabetically A, B, C, D creates a tree where every node has only a right child, forming a linear chain with height = n. All operations then become $O(n)$ instead of $O(log n)$.

3. Researching beyond the module, how would one fix a BST so the worst case scenario matches (or at least i closer to) the average case.[^1^]

   Self-balancing tree structures solve this problem. AVL trees maintain strict balance through rotations after each insertion/deletion, keeping height difference between subtrees at most 1. Red-Black trees use color properties and rotations to maintain approximate balance with less strict requirements. Both guarantee $O(log n)$ height even with sorted insertions, making worst-case performance match average-case at the cost of more complex insertion/deletion logic.

## Scenario

Fill out the table below. This is a common technical interview topic!

| Structure          | Good to use when                                                                 | Bad to use when                                                                  |
| ------------------ | -------------------------------------------------------------------------------- | -------------------------------------------------------------------------------- |
| Vector             | Need fast random access by index; mostly read operations; data size is known or grows predictably; frequent add/remove from back | Frequent insertions or deletions at front or middle; unpredictable size growth causing many reallocations; memory is fragmented |
| Linked List        | Good for stacks with frequent front only access                                  | Need random access by index; frequent searching; cache performance is critical; need to frequently access end of list |
| Sorted Vector      | When values coming in are already mostly sorted and we need quick search access. | When space is limited and the dataset is extremely large causing memory to swap. |
| Sorted Linked List | Need sorted order with frequent insertions/deletions; can't use contiguous memory; don't need fast search performance | Need fast searching (cannot use binary search); performance is critical; random access required; memory overhead is a concern |
| BST                | Mixed operations (add/search/remove) with random data; need sorted traversal output; data arrives in unpredictable order | Data is presorted                                                                |

## Conclusion

> The most striking finding was how the Sorted Vector and Sorted Linked List performed almost identically for insertions despite different architectures, showing that the cost of keeping data sorted outweighs structural differences at this scale. Sorted Vector slightly outperformed the BST in searches, reminding that cache locality can matter more than theory. The extreme slowdown of Sorted Linked List searches, about a thousand times slower than BST, showed the real cost of sequential access. Front and back operations made the tradeoffs clear. Linked List handled the front in constant time, while Vector struggled with shifting elements. These differences showed how structure directly shapes performance.

## Technical Interview Practice Questions

For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

   > Discuss the differences of an array and a linked list. When would you want to use one over the other?

   > An array stores elements in contiguous memory, which allows instant access by index in $O(1)$ time. However, inserting or deleting in the middle is costly because elements must be shifted to keep order. Arrays are efficient when the size is fixed or changes infrequently, and when random access or cache performance matters. A linked list stores elements as nodes connected by pointers. Each node can be anywhere in memory, and access is sequential, taking $O(n)$ time to reach a position. Insertions and deletions are efficient once the position is known since only pointers change. Linked lists are useful when frequent insertions or deletions occur, especially at the front, or when the total size is unknown. We use an array for fast lookups and predictable size, and a linked list for flexible, frequent modifications.



2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others.

      

## References

Add your references here. A good reference includes an inline citation, such as [1] , and then down in your references section, you include the full details of the reference. Computer Science research often uses [IEEE] or [ACM Reference format].

[1] Reference info, date, etc.

[^1^]: Implementing a BST with a self-balancing algorithm, such as AVL or Red-Black Trees is a great research paper topic!

<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->

[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images

[ACM Reference Format]: https://www.acm.org/publications/authors/reference-formatting
[IEEE]: https://www.ieee.org/content/dam/ieee-org/ieee/web/org/conferences/style_references_manual.pdf
