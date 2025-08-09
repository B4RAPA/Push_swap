# 42_push_swap
Push Swap - Project at 42 school (42 Wolfsburg)

![Bonus Completed](https://img.shields.io/badge/bonus-completed-brightgreen)

<h1 align="center">
	♻️ push_swap
</h1>

<p align="center">
	<b><i>Sorting data on a stack with a limited set of operations</i></b><br>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-What-I-Learned">What I Learned</a>
</h3>

---

## 💡 About the project

> _One of my most favorite projects, push_swap is an algorithmic project where the goal is to sort a stack of integers with the smallest possible number of moves, using only a limited set of stack operations. The challenge is to optimize algorithms and data structures to achieve efficient sorting under strict constraints, deepening your understanding of algorithmic problem-solving and resource management._
#### 🚀 Bonus
- [x] Checker program implemented

For more detailed information, look at the [**subject of this project**](https://github.com/jonona912/42_push_swap/blob/main/push_swap_subject.pdf).

## 🛠️ Usage

### Requirements

The project is implemented in C and requires the **`gcc` compiler** and standard **C libraries** to run.

### Instructions

**1. Compiling the project**

To compile, navigate to the project directory and run:

```shell
$ make
```

**2. Running the program**

To run the program and sort a list of integers, use:

```shell
$ ./push_swap [list of integers]
```

**Example:**

```shell
$ ./push_swap 3 2 1
```

### 🚀 Bonus

The bonus part of this project typically includes an additional checker program (usually called `checker`) that verifies if a series of instructions correctly sorts the stack.

**Compiling the bonus:**

```shell
$ make bonus
```

**Running the bonus checker:**

1. Generate instructions with `push_swap` and pipe them to `checker`:

    ```shell
    $ ./push_swap 3 2 1 | ./checker 3 2 1
    ```

2. `checker` will output `OK` if the stack is sorted or `KO` if not.

**Note:**  
Other bonus features may include support for additional commands or improved input handling. Please refer to the project subject or the repository's bonus files for further details.


## 📚 What I Learned

- Stack-based algorithms. Gained deeper understanding of sorting algorithms, especially Quick Sort and Merge Sort, both with arrays and linked lists
- Sorting techniques and optimization. Learned to modify standard algorithms to fit the specific requirements of the push_swap project
- Enhanced ability to visualize algorithms abstractly—solving problems on paper or in my head before coding
- Handling edge cases and input validation
- Improving problem-solving and debugging skills especially via GDB debugger


## 📝 Draft of what I felt right after completing the project

Objective is to come up with an algorithm that finds efficient number of operands on a stack to order numbers in an ascending order given one aditional stack. The operands are push from stack x to y, swap top to numbers of stack a or b, rotate or revese rotate stacks or operations where both stacks undergo same operation.

Personal Experience:
The project was interesting because I learned more about sorting algorithms, especially Quick Sort and Merge Sort both with an array and linked lists. Then I learned how the algorithm can be modified to meet my specific needs to solve the push swap project. Initially I made my own algorithm to sort stack which was extremely ineficient. The algorithm first found the min value from the stack a and rotated it until it was on top of the stack, then it was pushed to the top of stack b. When stack a was emptied this way, all the numbers from stack b was pushed back to stack a. Since the stack b was organized in descening order, pushing them back to stack a, the data was orginized in ascending order (from top of stack). This was easy to do, but then I had to choose whether I could find cases where I could optimize the code to decrease the number of operands. However, I saw myself being able to do this. I don't know if I would be successfull in finding sufficiently less number of operands to order the stack but I saw myself writing a lot of code but eventually not learning much except improving my code writing. Therefore, I wanted to integrate a sorting algorithm with the Push Swap project, because even though I learned this algorithms, I did not see how it could have been merged with the project. I am glad I made this decision because not only did I learn how to integrate two different concepts, but I also learned to visualize an algorithm in my head and solve it on a more abstract way in my head or on paper using diagrams before writing it into code. This is a skill that I see as important because as projects become bigger, I need to have a big picture view before solving a problem. Additionally, I face different types of bugs and since the number of files were becoming bigger, I could not longer use the debuging feature of VS Code because it does not work on multiple files (or at least I could not find a way to do it. I already had read about GDB debugger and now came the time when I had to implement it, facing bugs that I couldn't find with printf I had to search how to use GDB to debug my code. I used it, and each time I used it, I saw myself getting comfotable enough. since I was working with linked list, I could not print all the values at once as it is possible with an array of numbers. Therefore, I searched for ways to print linked list, I found that I need to create my own code to print linked list while debugging. Now I can see that if I use gdb another week, I will not want to debug with the inbuilt VS Code debugger anymore. These are some of the main things I learned from doing this project and I am glad that I kept trying to solve a problem, when I conceptually understood how to do it instead of using external source, because otherwise I wouldn't learn this.
