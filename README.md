# FourStrategies

I've been thinking some more about what the techniques for reading complex code in _The Programmer's Brain_ might tell us about writing complex code. Or even simple code.


Consider the problem of summing a sequence of values (or concatenating a sequence of strings, or aggregating anything else in the monoid ⟨S,+:S→S→S,0:S⟩ it's all the same pattern). There are four strategies:

	
|	                         | :**iterative process**:	| :**recursive process**: |
|                          |          :----:          |         :----:          |
| **iterative	defintion**: |          :iPiD:	        |         :rPiD:          |
| **recursive defintion**: |	        :iPrD:	        |         :rPrD:          |

Here I take "recursive" to mean _does not name partial sums_, where iterative does, and "iterative" to mean _explicitly loops_ where recursive doesn't. 

The example code here, in C 23 so that no one might imagine that anything clever is happening behind the scenes, I think demonstrates that:

* rPrD is by far the easiest to understand, and given the infrastructure is also easy to write and be confident that it's correct. The definition of the process follows the definition of the datatype very closely, but to do that you first need to be comfortable with recursive definitions of types.
* iPrD is a bit harder to read and write than rPrD, but there's a well-known idiom for doing it that may be memorized
* iPiD is in fact very hard to understand and notoriously easy to get wrong even though the idiom for doing it is baked in to almost every imperative language.
* rPiD is very hard to read or write (and is rightly almost never seen in practice). It took me longer to figure out how to do it than doing all the others combined.
*  
The order of teaching these in the education of most programmers seems to be:
1. iPiD, followed by a huge gap, possibly just a cliff with no other side in sight
2. rPrD
3. iPrD
4. no, just no.
   
Is there a better justification for that than habit and historical precedent? What can we do about it?
