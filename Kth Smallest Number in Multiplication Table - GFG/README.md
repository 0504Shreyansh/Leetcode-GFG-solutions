# Kth Smallest Number in Multiplication Table
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given three integers <strong>M, N </strong>and<strong> K</strong>. Consider a grid of <strong>M * N</strong>, where <strong>mat[i][j] = i * j</strong> (1 based index). The task is to return the <strong>K<sup>th</sup></strong>&nbsp;smallest element in the <strong>M * N</strong> multiplication table.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
M = 3, N = 3
K = 5
<strong>Output: </strong>3
<strong>Explanation:</strong> 
<img alt="" src="https://media.geeksforgeeks.org/img-practice/multtable1-grid-1637617528.jpg" style="height:204px; width:400px">
The 5<sup>th</sup>&nbsp;smallest element is 3.&nbsp;


</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
M = 2, N = 3
K = 6
<strong>Output: </strong>6&nbsp;

</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>KthSmallest</strong><strong>()</strong>&nbsp;which takes three integers as input and returns an integer as output.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(M * log(M * N))<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= M, N&nbsp;&lt;= 3 * 10<sup>4</sup><br>
1 &lt;= K&nbsp;&lt;= M * N</span></p>
</div>