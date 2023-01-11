


Name: Neel Parikh

-----------------------------------------------

Please confirm that you compiled your solution with test cases exercising ALL
functions using g++ -std=c++11.  Confirm this statement by typing YES below.
(If you did not do this, compilation errors may result in an overall grade of
zero!)

YES




Describe what augmentations to the bst data structures you made to complete the 
project -- i.e., what types / data members did you change and why?

I added num_left which count left node and also same for num_right which count right node.
I also added int nikesize which count the size of tree.





-----------------------------------------------
Which functions did you need to modify as a result of the augmentations from the previous
question?  

I changed insert and remove both private and public function.







-----------------------------------------------
For each function from the previous question, how did you ensure that the (asymptotic) runtime 
remained the same?


I mostly made it as the if else statement which will be 0(1) time so runtime remained same.





-----------------------------------------------
For each of the assigned functions, tell us how far you got using the choices 0-5 and
answer the given questions.  


0:  didn't get started
1:  started, but far from working
2:  have implementation but only works for simple cases
3:  finished and I think it works most of the time but not sure the runtime req is met. 
4:  finished and I think it works most of the time and I'm sure my design leads to 
       the correct runtime (even if I still have a few bugs).
5:  finished and confident on correctness and runtime requirements


to_vector level of completion:  5 


-----------------------------------------------
get_ith level of completion:  5  

    How did you ensure O(h) runtime?

    ANSWER: I made the recursive function which works based on the height of the tree
            by which i can ensure that it is o(h) runtime.
-----------------------------------------------
position_of level of completion:  5  

    How did you ensure O(h) runtime?

    ANSWER:I made the recursive function which works based on the height of the tree
            by which i can ensure that it is o(h) runtime. And also first it was not
            working but when I did tirnary statement inside tirnary then it started
            working.
-----------------------------------------------
num_geq level of completion:  5  

    How did you ensure O(h) runtime?

    ANSWER:I made the recursive function which works based on the height of the tree
            by which i can ensure that it is o(h) runtime. And also I did the same for
            this one that I did tirnary statement inside tirnary because it was cool
            also it was working without that too.

-----------------------------------------------
num_leq level of completion:  5

    How did you ensure O(h) runtime?

    ANSWER:I made the recursive function which works based on the height of the tree
            by which i can ensure that it is o(h) runtime. And also I did the same for
            this one that I did tirnary statement inside tirnary because it was cool
            also it was working without that too.

-----------------------------------------------
num_range level of completion:  5

    How did you ensure O(h) runtime?

    ANSWER: In num_range I called num_geq and num_leq which is o(h) in my opinion
            so this function will be o(h) too bacause we are addind runtime and
            addition gives the same runtime.

-----------------------------------------------
extract_range level of completion:  5

    How did you ensure O(h+k) runtime?

    ANSWER: I taked a look at professor code which was in file and thought that it is
            o(h) runtime by which this function will be o(h) too.

Implementation of size-balanced criteria according to 
the given guidelines:

    Level of completion: 5











