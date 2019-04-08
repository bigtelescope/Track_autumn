My own vector with templates.
You can find more simple project without templates in my repository "Vector" 

I've realized some thing:

1)Copying and assignation constructors using deep copying

2)Weird move semantics

3)Reloaded operators of input, output and so on

4)I use my own exception class for errors handling. This class and it's basic methods you can find in Exceptional.h file.

By the way:
There is ".hpp" file (included in ".h") that involves implementations of MyVector class functions. It's done so due to impossibility of separate compilation of this library files.

And one more moment:
There is addition.cpp file. There are few functions for artificial errors in it.
