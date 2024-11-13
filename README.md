<h1>Voting-System-Using-C-Language</h1>

<h2>Explanation of code:-</h2>

<ol>
  <li>Candidate Entry: <br>
  The program prompts for the number of candidates and reads each candidate's name, checking for duplicates using ‘isDuplicateCandidate’ and converting names to lowercase for consistency.
  <li>Voting Process: <br>
  The program enters a loop where users enter their names and cast votes.
  It checks if the voter has already voted using ‘hasVoted’ to prevent multiple votes from the same user.
  Votes are cast using the ‘castVote’ function, which matches votes to candidates case-insensitively.
  <li>Storing and Sorting Votes: <br>
  The ‘storeVotes’ function sorts candidates by name using ‘qsort’ and ‘compareCandidates’, and writes the sorted results to a file.
  <li>Determining the Winner: <br>
  The ‘findWinner’ function finds the candidate with the highest votes and handles ties by listing all candidates with the maximum votes.
</ol>

<h2>Results:-</h2>
<img width="594" alt="r1" src="https://github.com/user-attachments/assets/d19ca739-dfe0-4896-ad7d-36a589e3b5e4">
<br>
<img width="594" alt="r2" src="https://github.com/user-attachments/assets/d2f8782b-c5bc-4f68-a49a-02fdc0be1404">



