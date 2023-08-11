# Minimize Max Distance to Gas Station
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">We have an horizontal number line. On that number line, we have gas <strong>stations </strong>at positions stations[0], stations[1], ..., stations[N-1], where <strong>N </strong>= size of the stations array. Now, we add <strong>K</strong> more gas stations so that <strong>D</strong>, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of D.&nbsp;Find the answer <strong>exactly</strong> to 2 decimal places.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 10</span>
<span style="font-size:18px">stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]</span>
<span style="font-size:18px">K = 9</span>
<span style="font-size:18px"><strong>Output:</strong> 0.50</span>
<span style="font-size:18px"><strong>Explanation: </strong>Each of the 9 stations can be added mid way between all the existing adjacent stations.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 10</span>
<span style="font-size:18px">stations = <code>[3,6,12,19,33,44,67,72,89,95]</code></span>
<span style="font-size:18px">K = 2</span>
<span style="font-size:18px"><strong>Output:</strong> 14.00</span>
<span style="font-size:18px"><strong>Explanation: </strong>C</span><code><span style="font-size:18px">onstruction of gas stations at 86 locations</span></code></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>findSmallestMaxDist()&nbsp;</strong>which takes a list of stations and integer K as inputs and returns the smallest possible value of D. Find the answer <strong>exactly</strong> to 2 decimal places.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity</strong>: O(N*log K)<br>
<strong>Expected Auxiliary Space</strong>: O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraint:</strong><br>
10 &lt;= N&nbsp;&lt;= 5000<sup>&nbsp;</sup><br>
0 &lt;= stations[i] &lt;= 10<sup>9&nbsp;</sup><br>
0 &lt;= K &lt;= 10<sup>5</sup></span></p>

<p><span style="font-size:18px"><strong><code>stations</code></strong>&nbsp;is sorted in a&nbsp;<strong>strictly increasing</strong>&nbsp;order.</span></p>
</div>