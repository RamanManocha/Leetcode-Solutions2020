




https://leetcode.com/discuss/interview-question/object-oriented-design/1177601/flipkart-machine-coding-design-online-coding-platform-coding-blox-leetcode-lld





Design Online Coding Platform CODING BLOX / Design Leetcode LLD

Coding Blox is an Online Coding Platform that allows a user to Sign Up, Create Contests and participate in Contests hosted by Others.
Each contest can have a level (LOW, MEDIUM, HIGH) and will contain a set of questions.
Each question will have different levels of difficulty(LOW, MEDIUM, HIGH) and score.
Based on the contest level, the question set is going to be decided. Contest level with LOW difficulty will have questions with LOW difficulty level.
Final score will be decided based on the difficulty LEVEL chosen for a contest
Users solve problems and get points based on the difficulty of the problems and after the contests scores of the users are updated.
functionalities:

CreateUser <user_name>
CreateQuestion <difficulty_level>
ListQuestion <difficulty_level>
CreateContest <contest_name> <contest_level> <contest_creator_user_name>
ListContest <difficulty_level>
AttendContest <contest_id> <user_name>
RunContest <contest_id> <contest_creator_user_name>
LeaderBoard <sorting order asc/desc>
ContestHistory <contest_id>
WithdrawContest <contest_id>
full problem statement & solution (Time given 90min) : http://bit.ly/leetcode-low-level-design

Simply I follow these steps for any LLD.

Find out entities
Find out the relationship between entities
Write entities CRUD (use hashmap or JPA)
Start implementing requirements
Step 1,2 and 3 => approx 30min
Step 4 => +1hr

Step 1, 2: Domain layer
Step 3: database layer
Step 4: Service layer

Step 0: understand the problem statement and requirements

Step 1: List down important entities/model/domain
In the above question list of entities are -> User, Contest, and Question
image

Step 2: List down the relationship between entities.
e.g.
User can register for multiple contests

User:
	List<Contest> contests
The contest can have multiple Questions

Contest:
	List<Question> questions
Now Add other fields of entities

User:
	username
	score
	List<Contest> contests -- (A)
Contest:
	name
	level
	status
	List<Question> questions -- (B)
Question:
	question
	level
	score
image

image

Step 3: Store entities and write entities CRUD methods (use method 1)
Store entities Method 1: Use hashMap to store entities,

Map<Long, User> userDb
Map<Long, Question> questionDb
Map<Long, Contest> contestDb
Write CRUD method for each entity

Store entities Method 2: Use H2 in memory using JPA, (simple to use but need to practice more)
Create 3 DAO class, internally with the help of the JPA class we can get all CRUD methods so no need to create any methods

Step 4: Create a service class for each entity and start implementing the requirement

UserService:
	createUser(username)
	attendContest(contest id or contest object, username)
	leaderBoard()
	withdrawContest(contest id or contest object, username)
QuestionService:
	createQuestion(question)
	listAllQuestion()
ContestService:
	createContest(contestId or contest object, username)
	listAllContest()
	runContest(contestid or contest object, username)
	contestHistory()
add logic for above methods plus entity validation

image

Step 5: Refactor code: extract class to an interface, add enum, add exceptions, add constant
List<Contest> contests --(A) become--> List<ContestQue> contestQuestions
List<Question> questions --(B) becomes --> List<ContestQue> contestQuestions

ContestQue:
	contest id
	List<Questions>
  
    
