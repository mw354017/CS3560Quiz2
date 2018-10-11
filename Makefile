DOXYGEN = doxygen



all: collegemain.o college.o course.o
	g++ collegemain.cpp college.cpp course.cpp -o myexe

collegemain.o: collegemain.cpp course.h node.h tarray.h
	g++ -c collegemain.cpp

college.o: college.cpp college.h
	g++ -c college.cpp

course.o: course.cpp course.h
	g++ -c course.cpp

doczip: $(/html /latex)
	tar -cvf collegedoxy.tar html latex

myexe: all
	./myexe

build: all

doc:
	@doxygen
	@open doxygen/html/index.html

clean:
	rm myexe collegemain.o college.o course.o

