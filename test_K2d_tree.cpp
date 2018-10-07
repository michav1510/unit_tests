#include "test_K2d_tree.hpp"

#include <iostream>
#include <fstream>
#include "../cgfunctionality/datastructs/K2d_tree.hpp"
#include "../cgfunctionality/basic/Point2d.hpp"

void test_K2d_tree::test_param_constr_case1()
{
    std::vector<Point2d> vec1;
	vec1.push_back(Point2d(2,1));
	vec1.push_back(Point2d(1,0));
	vec1.push_back(Point2d(3,-5));
	vec1.push_back(Point2d(-1,2));
	vec1.push_back(Point2d(4,-3));
	K2d_tree tree1(vec1);
			
	K2d_tree::tree_iterator it1 = tree1.begin();
	CPPUNIT_ASSERT( it1.getSplitCoord() == 1 && it1.getSplitValue() == 2
                        && it1.getLeafPoint() == Point2d(0,0) && it1.isInternalNode() == true );
	
	K2d_tree::tree_iterator it12 = it1.getLeftChild();
	CPPUNIT_ASSERT(it12.getSplitCoord() == 2 && it12.getSplitValue() == 1 
                        && it12.getLeafPoint() == Point2d(0,0) && it12.isInternalNode() == true);
	
    K2d_tree::tree_iterator it13 = it1.getRightChild();
	CPPUNIT_ASSERT(it13.getSplitCoord() == 2 && it13.getSplitValue() == -5 
                        && it13.getLeafPoint() == Point2d(0,0) && it13.isInternalNode() == true);
	
    K2d_tree::tree_iterator it14 = it1.getLeftChild().getLeftChild();
	CPPUNIT_ASSERT(it14.getSplitCoord() == 1 && it14.getSplitValue() == 1 
                        && it14.getLeafPoint() == Point2d(0,0) && it14.isInternalNode() == true);
	
    K2d_tree::tree_iterator it15 = it1.getLeftChild().getRightChild();
	CPPUNIT_ASSERT(it15.getSplitCoord() == 0 && it15.getSplitValue() == 0 
                        && it15.getLeafPoint() == Point2d(-1,2) && it15.isInternalNode() == false);
	
    K2d_tree::tree_iterator it16 = it1.getRightChild().getLeftChild();
	CPPUNIT_ASSERT(it16.getSplitCoord() == 0 && it16.getSplitValue() == 0 
                        && it16.getLeafPoint() == Point2d(3,-5) && it16.isInternalNode() == false);
	
    K2d_tree::tree_iterator it17 = it1.getRightChild().getRightChild();
	CPPUNIT_ASSERT(it17.getSplitCoord() == 0 && it17.getSplitValue() == 0 
                        && it17.getLeafPoint() == Point2d(4,-3) && it17.isInternalNode() == false);
	
    K2d_tree::tree_iterator it18 = it1.getLeftChild().getLeftChild().getLeftChild();
	CPPUNIT_ASSERT(it18.getSplitCoord() == 0 && it18.getSplitValue() == 0 
                        && it18.getLeafPoint() == Point2d(1,0) && it18.isInternalNode() == false);
	
    K2d_tree::tree_iterator it19 = it1.getLeftChild().getLeftChild().getRightChild();
	CPPUNIT_ASSERT(it19.getSplitCoord() == 0 && it19.getSplitValue() == 0 
                        && it19.getLeafPoint() == Point2d(2,1) && it19.isInternalNode() == false);
	
    CPPUNIT_ASSERT(tree1.size() == 5);
}