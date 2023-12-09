# ESEP: Data Processing and Storage

<h2>Running Instructions</h2>
<ul>
  <li>Move <code>CMakeLists.txt</code> to the directory above the program files.</li>
  <li>The program's driver is <code>main.cpp</code>.</li>
  <li> Compile main with <code>g++ -o main main.cpp</code> and run with <code>./main</code></li>
  <li> If running in CLion, <code>CMakeLists.txt</code> is already configured for the environment. Just hit run.</li>
</ul>

<h2>Expected Commands</h2>
<ul>
  <li><code>BEGIN TRANSACTION</code> starts a transaction.</li>
  <li><code>PUT [key] [value]</code> creates/ add key-value pairing to map.</li>
  <li><code>GET [key]</code> retrieves the value associated with the key.</li>
  <li><code>COMMIT</code> commits the transaction to the main state.</li>
  <li><code>ROLLBACK</code> reverts all changes made in the most recent transaction.</li>
  <li><code>END</code> to exit the program.</li>
</ul>

<h2>Assignment Suggestions</h2>
To improve this assignment, I would clarify how the program is going to be tested and graded. I implemented <code>main.cpp</code> according to Fig 2 in the assignment instructions, but it's unclear whether that's what the grader would be doing to test my functionality. I did thoroughly enjoyed working on this assignment, so I look forward to it becoming an official assignment in the future!
