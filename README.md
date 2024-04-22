# CS210
SNHU CS 210 - Programming Languages
C++ projects completed in CS210 during the 2024 Spring semester at SNHU. 

Mod 8 Journal Assignment:

Summarize the project and what problem it was solving.
  The final project was a program that took a text file of a list of produce items as input and analyzed the frequencies of the  items. It simulated a grocery store inventory program that produced output of each items frequency, a histogram listing all items in the output and symbols for each sale, and created a backup file to save results. 
  
What did you do particularly well?
  I think I did a good job of adhering to OOP principles and creating modular code that was well organized. This was really       helpful during debugging. I put more effort than usual into planning out my code before actually starting and debugging incrementally as I wrote. The result was that I had essentially no debugging to do after I was finished writing the program. Overall, the entire process went much more smoothly than usual for me. 
  
Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
  After submitting the program, I continued to do a bit of research and discovered that the ProduceItem class was probably unnecessary. I essentially just made a class that imitates the existing "map" container already built into the C++ standard library. I was unaware of maps at the time I wrote the program and my implementation probably uses much more memory than necessary. Still, it was good practice for making classes. 
  
Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  I struggled a bit dealing with certain details of the iostream, in particular handling error flags and clearing bad input from the stream. cplusplus.com and cppreference.com were helpful in pointing me in the right direction, and reviewing the zybooks helped as well. 

What skills from this project will be particularly transferable to other projects or course work?
  OOP principles have been mentioned in some of my previous courses, but they really started to sink in for me during this class. I suspect that will be the most useful skill in future courses and projects.  

How did you make this program maintainable, readable, and adaptable?
  The code is broken down into fairly small, modular parts. Any future errors that arise can be quickly narrowed down to being within a few lines of code. One advantage of implementing the ProduceItem class (instead of using a map) is that other derived classes could be implemented using ProduceItem as a base class or a new class could serve as a base class for both ProduceItem and other derived classes such as BakeryItem or DairyItem, etc. 
