all_test_run : all_tests_run.cpp test_CH2d_dlclist.o test_K2d_tree.o Point2d.o BasicCalcandPred.o Edge2d.o
	 g++ -std=c++11 all_tests_run.cpp test_CH2d_dlclist.o test_K2d_tree.o Point2d.o Edge2d.o BasicCalcandPred.o -o all_tests_run -lcppunit

Point2d.o : ../cgfunctionality/basic/Point2d.cpp
	g++ -std=c++11 -c ../cgfunctionality/basic/Point2d.cpp 

Edge2d.o : ../cgfunctionality/basic/Edge2d.cpp
	g++ -std=c++11 -c ../cgfunctionality/basic/Edge2d.cpp

BasicCalcandPred.o : ../cgfunctionality/basic/BasicCalcandPred.cpp
	g++ -std=c++11 -c 	../cgfunctionality/basic/BasicCalcandPred.cpp

test_CH2d_dlclist.o : test_CH2d_dlclist.cpp
	g++ -std=c++11 -c test_CH2d_dlclist.cpp

test_K2d_tree.o : test_K2d_tree.cpp
	g++ -std=c++11 -c test_K2d_tree.cpp

clean : 
	rm all_tests_run test_CH2d_dlclist.o Point2d.o Edge2d.o BasicCalcandPred.o test_K2d_tree.o