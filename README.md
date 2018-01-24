# Description
Students Enroller (Hash Table Version) is a C++ program that allows the user to add students, remove students, or print students' information using a Finite Set data structure (represented as a Hash Table using closed hashing). This program is made-from-scratch and does not utilize the C++ Standard Template Library (STL).

# Compilation and Execution
* Compile: g++ \*.cpp
* Run Program: ./a.out

# Program Commands
* add <first-name> <last-name> <student-id> <classification> <major>: Adds a student to the Finite Set.
	* Examples:
		<pre>
		set> add James Bond 7 Sophomore Dance
		set> add Bugs Bunny 3229 Junior Business
		set> add Donald Duck 230 Junior ComputerScience
		</pre>
* remove <student-id>: Removes a student from the Finite Set. Returns true if that student has been removed. Returns false if that student does not exist.
	* Examples:
		<pre>
		set> remove 123
		false
		set> remove 7
		true
		</pre>
* print: Prints all students' information in the order they appear in the Finite Set (Hash Table).
	* Notes:
		* When a student is found in a Hash Table bucket, the output printed is in the following tuple notation: (firstname,lastname,student-id,classification,major)
		* When there is no student in a Hash Table bucket, the output printed is (NULL)
		* When a student was previously deleted from a Hash Table bucket, the output printed is (DEL)
		* The print command takes no arguments.
	* Example:
		<pre>
		set> print
		(Donald,Duck,230,Junior,ComputerScience)(NULL)(NULL)(NULL)(NULL)(NULL)(NULL)(DEL)(NULL)(Bugs,Bunny,3229,Junior,Business)
		</pre>
* quit: Exits the program.

# Technologies Used
* C++
* Linux
* PuTTY
* WinSCP

# Data Structures Used
* Finite Set
* Hash Table (using closed hashing)
	* Hash Table size: B = 10
	* Hash Functions:
		* h(x) = x mod B
		* hi(x) = (h(x) + i^2) mod B

# Notes
* This program should be compiled and executed in a Linux Operating System environment.
* This program has been tested extensively, without error, through the University of North Texas's Praktomat testing system.