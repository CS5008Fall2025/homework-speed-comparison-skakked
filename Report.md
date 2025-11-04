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
   The most surprising result is how closely Sorted Vector and Sorted Linked List perform for insertion operations despite their fundamentally different architectures. At N=99,999, Sorted Vector takes 17.75 seconds while Sorted Linked List takes 21.56 seconds—only about 20% difference. The similar performance suggests that the cost of maintaining sorted order (finding the correct position and inserting) dominates over the structural differences between arrays and linked lists at this scale.

2. What data structure is the fast at adding elements (sorted)? Why do you think that is?

3. What data structure is the fastest at removing elements (sorted)? Why do you think that is?

4. What data structure is the fastest at searching? Why do you think that is?

5. What data structure is the fastest for adding elements to the front? Why do you think that is?

6. What data structure is the fastest for adding elements to the back? Why do you think that is?

7. What data structure is the fastest for removing elements from the front? Why do you think that is?

8. What data structure is the fastest for removing elements from the back? Why do you think that is?

### Deeper Thinking

#### Double Linked List vs Single Linked List

1. If you wrote your linked list as a single linked list, removing from the back was expensive. If you wrote it as a double linked list, removing from the back was cheap. Why do you think that is?

2. When running most functions, at least ~30% of the tests were worse case scenarios. Why do you think that is? 

3. What was done in the code to encourage that? 

4. How did this particularly influence the linked list searches?

#### Test Bias

1. The tests were inherently biased towards the BST to perform better due the setup of the experiment. Explain why this is the case.  (hint: think about the randomization of the data, and the worst case scenario for BST).

2. What would generate the worst case scenery for a BST?

3. Researching beyond the module, how would one fix a BST so the worst case scenario matches (or at least i closer to) the average case.[^1^]

## Scenario

Fill out the table below. This is a common technical interview topic!

| Structure          | Good to use when                                                                 | Bad to use when                                                                  |
| ------------------ | -------------------------------------------------------------------------------- | -------------------------------------------------------------------------------- |
| Vector             |                                                                                  |                                                                                  |
| Linked List        | Good for stacks with frequent front only access                                  |                                                                                  |
| Sorted Vector      | When values coming in are already mostly sorted and we need quick search access. | When space is limited and the dataset is extremely large causing memory to swap. |
| Sorted Linked List |                                                                                  |                                                                                  |
| BST                |                                                                                  | data is presorted                                                                |

## Conclusion

Summarize your findings. Where there any surprises?  What did you end up learning by comparing speeds?

## Technical Interview Practice Questions

For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 

## References

Add your references here. A good reference includes an inline citation, such as [1] , and then down in your references section, you include the full details of the reference. Computer Science research often uses [IEEE] or [ACM Reference format].

[1] Reference info, date, etc.

[^1^]: Implementing a BST with a self-balancing algorithm, such as AVL or Red-Black Trees is a great research paper topic!

<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->

[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images

[ACM Reference Format]: https://www.acm.org/publications/authors/reference-formatting
[IEEE]: https://www.ieee.org/content/dam/ieee-org/ieee/web/org/conferences/style_references_manual.pdf
