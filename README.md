<h1 align="center">🍝 Philosophers — Dining Philosophers Problem</h1>

<p align="center">
  <strong>42 Project</strong> — A multithreaded simulation of the classic Dining Philosophers problem, focusing on synchronization, mutexes and thread-safe behavior.
</p>

<p align="center">
  🧵 Threads • 🔒 Mutexes • ⏱️ Timing • ⚙️ Synchronization • 💀 Death Detection
</p>

<hr>

<h2>📌 About the Project</h2>
<p>
The <strong>Philosophers</strong> project simulates the famous problem introduced by Edsger Dijkstra, known as the
<em>"Dining Philosophers Problem"</em>. Around a circular table, each philosopher repeatedly performs three actions:
</p>

<ul>
  <li>💭 <strong>thinking</strong></li>
  <li>🍽️ <strong>eating</strong></li>
  <li>😴 <strong>sleeping</strong></li>
</ul>

<p>
To eat, a philosopher must pick up <strong>two forks</strong> — one on the left and one on the right.
The challenge lies in preventing:
</p>

<ul>
  <li>⚠️ <strong>deadlocks</strong></li>
  <li>🚫 <strong>race conditions</strong></li>
  <li>🧯 <strong>starvation</strong></li>
</ul>

<hr>

<h2>🧠 Core Concepts</h2>

<ul>
  <li>🧵 <strong>pthread_create</strong> — one thread per philosopher</li>
  <li>🔒 <strong>pthread_mutex</strong> — one mutex per fork</li>
  <li>🖨️ <strong>synchronized output</strong> — no overlapping messages</li>
  <li>⏱️ <strong>monitoring loop</strong> — detect when a philosopher dies</li>
</ul>

<hr>

<h2>🚀 How to Run</h2>

<p><strong>Compile:</strong></p>

bash make

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
