<h1>Cricket Scoreboard Simulator</h1>
<p>This project is a simulated cricket scoreboard designed for the 8051 microprocessor as part of the EE337 course. The scoreboard displays the current score and the number of overs bowled on the first line, in the format Runs/Wickets (Overs.Balls). For example, 45/3 (15.2) means that 45 runs have been scored in 15 overs and 2 balls for the loss of 3 wickets.</p>
<p>The events of the current over are displayed on the second line of the LCD in the following format:</p>
<ul>
  <li>The event that occurred on a ball is denoted by a single character</li>
  <li>A dot ball is denoted by a period symbol (also called the fullstop symbol)</li>
  <li>Runs scored on a ball are denoted by a single-digit number</li>
  <li>If a wicket falls on a ball, it is denoted by the W character</li>
  <li>A wide ball is denoted by the E character</li>
  <li>A no-ball is denoted by the N character</li>
  <li>At the start of the game, the first line will show 0/0 (0.0). The scorer will press a series of keys that will move the game forward and change the scoreboard state.</li>
</ul>
<p>There are a few exceptions to keep in mind:</p>
<ul>
  <li>No bowler bowls more than 16 balls in an over</li>
  <li>No extra runs are scored on the NO Ball. The scorer can note this down and add it manually at the end.</li>
</ul>
<h2>Usage</h2>
<p>To use this cricket scoreboard simulator, follow these steps:</p>
<ol>
  <li>Set up the 8051 microprocessor and LCD display according to the hardware specifications.</li>
  <li>Clone this repository onto your local machine.</li>
  <li>Open the source code and edit it according to your requirements. The code is well-commented and easy to understand.</li>
  <li>Compile the code and load it onto the microprocessor.</li>
  <li>Use the keys to move the game forward and update the scoreboard state.</li>
</ol>
<h2>Contributing</h2>
<p>Contributions to this project are always welcome! If you find a bug or have a feature request, please open an issue. If you want to contribute code, fork this repository, make your changes, and create a pull request.</p>






