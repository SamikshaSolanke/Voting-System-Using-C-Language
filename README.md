<h1>Voting-System-Using-C-Language</h1>

<h2>Explanation of code:-
</h2>

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


