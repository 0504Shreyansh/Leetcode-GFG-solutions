# Depth of node
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a binary tree, find&nbsp;the <strong>depth of the deepest odd level leaf</strong> node in a binary tree. If there is <strong>no leaf </strong>at odd level then<strong> return 0</strong>.<br>
Consider that level starts with 1.&nbsp;Depth of a leaf node is number of nodes on the path from root to leaf (including both leaf and root).</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input: </span></strong><span style="font-size:18px">
&nbsp;         1
&nbsp;       /    \
&nbsp;      2      3
&nbsp;     / \    / \
&nbsp;    4   5  6   7</span>
<strong><span style="font-size:18px">Output: </span></strong><span style="font-size:18px">3</span>
<span style="font-size:18px"><strong>Explanation: </strong>In the above tree 4,5,6 and 7 are</span>
<span style="font-size:18px">odd level leaf nodes at depth 3.So the answer is 3.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><strong><span style="font-size:18px">Input: </span></strong><span style="font-size:18px">
     1
    / \</span>
   <span style="font-size:18px"> 2   4</span>
<span style="font-size:18px"><strong>Output:</strong> 0</span>
</pre>

<p><strong><span style="font-size:18px">Your task:</span></strong></p>

<p><span style="font-size:18px">You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>depthOfOddLeaf</strong></span><span style="font-size:18px"><strong>()&nbsp;</strong>which takes root node of the tree as input parameter and returns an integer denoting the maximum depth of a odd level&nbsp;leaf node of the tree. If there is no such leaf node return 0.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=T&lt;=1000<br>
1&lt;=n&lt;=1000<br>
1&lt;=data of node&lt;=1000</span></p>
</div>