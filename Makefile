DOXYGEN = doxygen



all: collegemain.o college.o course.o
	g++ collegemain.cpp college.cpp course.cpp -o myexe

collegemain.o: collegemain.cpp course.h node.h tarray.h
	g++ -c collegemain.cpp

college.o: college.cpp college.h
	g++ -c college.cpp

course.o: course.cpp course.h
	g++ -c course.cpp

doczip: collegemain.cpp college.cpp course.cpp
	cd ..
	tar -cvf college.tar CS3560Quiz2/

myexe: all
	./myexe

build: all

doc:
	@doxygen
	@open doxygen/html/index.html

clean:
	rm myexe collegemain.o college.o course.o

