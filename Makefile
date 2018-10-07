all_test_run : all_tests_run.cpp test_CH2d_dlclist.o test_K2d_tree.o Point2d.o Pred.o Edge2d.o
	 g++ all_tests_run.cpp test_CH2d_dlclist.o test_K2d_tree.o Point2d.o Edge2d.o Pred.o -o all_tests_run -lcppunit

Point2d.o : ../cgfunctionality/basic/Point2d.cpp
	g++ -c ../cgfunctionality/basic/Point2d.cpp 

Edge2d.o : ../cgfunctionality/basic/Edge2d.cpp
	g++ -c ../cgfunctionality/basic/Edge2d.cpp

Pred.o : ../cgfunctionality/preds/Pred.cpp
	g++ -c 	../cgfunctionality/preds/Pred.cpp

test_CH2d_dlclist.o : test_CH2d_dlclist.cpp
	g++ -c test_CH2d_dlclist.cpp

test_K2d_tree.o : test_K2d_tree.cpp
	g++ -c test_K2d_tree.cpp

clean : 
	rm all_tests_run test_CH2d_dlclist.o Point2d.o Edge2d.o Pred.o CH2d_dlclist.o