#VERSION 1.1

make: ShapeAnimator.o TerminalAnimation.o TestShape.o
	g++ ShapeAnimator.o TerminalAnimation.o TestShape.o -o run.exe
	
ShapeAnimator.o: ShapeAnimator.cpp
	g++ -c ShapeAnimator.cpp
TerminalAnimation.o: TerminalAnimation.cpp
	g++ -c TerminalAnimation.cpp
TestShape.o: TestShape.cpp
	g++ -c TestShape.cpp

clean:
	rm *.o
	rm *.exe
dis:
	vi -p *.cpp *.h

run:
	./run.exe
