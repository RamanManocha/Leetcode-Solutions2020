

https://www.faceprep.in/dbms/dbms-keys-in-relational-model/


Candidate Key: The minimal set of an attribute which can uniquely identify a tuple is known as a candidate key. For Example, STUD_NO in STUDENT relation.

The value of Candidate Key is unique and non-null for every tuple.
There can be more than one candidate key in a relation. For Example, STUD_NO, as well as STUD_PHONE both, are candidate keys for relation STUDENT.
The candidate key can be simple (having only one attribute) or composite as well. For Example, {STUD_NO, COURSE_NO} is a composite candidate key for relation STUDENT_COURSE.


Super Key: The set of attributes which can uniquely identify a tuple is known as Super Key. For Example, STUD_NO, (STUD_NO, STUD_NAME) etc.



Adding zero or more attributes to candidate key generates a super key.
A candidate key is a superkey but vice versa is not true.


Primary Key: There can be more than one candidate key in a relation out of which one can be chosen as a primary key. For Example, STUD_NO as well as STUD_PHONE both are candidate keys for relation STUDENT but STUD_NO can be chosen as primary key (only one out of many candidate keys).



Alternate Key: The candidate key other than the primary key is called an alternate key. For Example, STUD_NO, as well as STUD_PHONE both, are candidate keys for relation STUDENT but STUD_PHONE will be alternate key (only one out of many candidate keys).



Foreign Key: If an attribute can only take the values which are present as values of some other attribute, it will be a foreign key to the attribute to which it refers. The relation which is being referenced is called referenced relation and the corresponding attribute is called referenced attribute and the relation which refers to referenced relation is called referencing relation and the corresponding attribute is called referencing attribute. The referenced attribute of referencing attribute should be the primary key. For Example, STUD_NO in STUDENT_COURSE is a foreign key to STUD_NO in STUDENT relation.

Dbms


