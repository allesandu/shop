clean:
	rm *.o 
compile_all:
	
	c++ ParentClass.cpp -c
	c++ Item.cpp -c
	c++ Category.cpp -c
	c++ Customer.cpp -c
	c++ Order.cpp -c
all:compile_all
	g++ run.cpp *.o