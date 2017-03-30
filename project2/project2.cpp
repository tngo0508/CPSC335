// Assignment 2: Topology recognition problem
// THOMAS NGO
// VAN DO                                                                                                     
// Given a network with n>3 nodes and a weight matrix W[0..n−1, 0..n−1] of      
// positive integers, of a weighted, connected undirected graph modeling        
// a network, decide whether the network is one of the topologies, if any:      
// ring, star, fully connected mesh. Note: represent infinity by the value 100.
// INPUT: a positive integer n and a list of n^2 positive values          
// OUTPUT: message "ring" or "star" or "complete" or "neither"                  

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
	int n, i, j, count, center;
	int W[100][100];
	bool cond = true;
                                                       
	cout << endl << "CPSC 335-x - Programming Assignment #2" << endl;
	cout << "Topology recognition algorithm" << endl;
	cout << "Enter the number of nodes in the topology" << endl;                                                   
	cin >> n;                                                 
	cout << "Enter the positive weights, 100 for infinity" << endl;
	for(i=0; i < n; i++)
		for(j=0; j < n; j++)
			cin >> W[i][j];

	// Start the chronograph to time the execution of the algorithm               
	auto start = chrono::high_resolution_clock::now();

	cout <<"The topology is"<< endl;

	// loop to check whether the topology is a RING      
	/*
    	0   2   100 100 5
        2   0   3   100 100
        100 3   0   1   100
        100 100 1   0   4
        5   100 100 4   0
	*/
	for (i=0;  i < n ; i++)
	{
		// YOU NEED TO IMPLEMENT THIS LOOP.
		// Set inital count of edge when checking a new row/node.
		count = 0;
		// check each value in each row/node, increase edge count if the weight
		// is not 0 and 100.
        	for(j=0; j < n; j++)
        		if (W[i][j] > 0 && W[i][j] < 100)
                		count++;
		// In a ring graph, each node has exact 2 edges. Consider not a ring if violated this rule.
        	if (count != 2)
        	{
            		cond = false;
			//  Exit the ring loop.
            		i = n;
        	}
	}
 
	if (cond) {
		cout <<"ring" << endl;
		auto end = chrono::high_resolution_clock::now();
		int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
		  double seconds = microseconds / 1E6;
		    cout << "elapsed time: " << fixed << setprecision(6) << seconds << " seconds" << endl;
		return EXIT_SUCCESS;
	}

	cond = true;
	center = 0;
	// loop to check whether the topology is a STAR        
	/*
        0  2    3      4  5
        2  0    100  100  100
        3  100  0    100  100
        4  100  100  0    100
        5  100  100  100  0
	*/
	for (i=0;  i < n ; i++) 
	{
		// YOU NEED TO IMPLEMENT THIS LOOP
		// Set inital count of edge when checking a new row
		count = 0;
		// check each value in each row/node, increase edge count if the value
			// is not 0 and 100
		for(j=0; j < n; j++)
		    if (W[i][j] > 0 && W[i][j] < 100)
		        count++;
			
		// In star graph, the center node has (n - 1) edges while all other has only 1.
		if (count != 1 && center == 1)
		{
            		cond = false;
			// Exit the star loop
			i = n;
		}
		// if a node has n - 1 edge and there is no other similar node,
		// we found the center node
        	if (count == n - 1 && center == 0)
            		center = 1;
	}

	if (cond && (center == 1)) {
		cout <<"star" << endl;
		auto end = chrono::high_resolution_clock::now();
		int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
		  double seconds = microseconds / 1E6;
		    cout << "elapsed time: " << fixed << setprecision(6) << seconds << " seconds" << endl;
		return EXIT_SUCCESS;
	}

	cond = true;
	// loop to check whether the topology is a fully connected MESH               
	for (i=0;  i < n ; i++) {
		// YOU NEED TO IMPLEMENT THIS LOOP
		// Set inital count of edge when checking a new row
		count = 0;
		// check each value in each row/node, increase edge count if the value
			// is not 0 and 100
		for(j=0; j < n; j++)
		    if (W[i][j] > 0 && W[i][j] < 100)
		        count++;
			
		// In a complete graph, all nodes have (n - 1) edge.
		if (count != n - 1)
		    cond = false;
	}

	if (cond)
		cout << "fully connected mesh" << endl;
	else
		cout << "neither" << endl;

	// End the chronograph to time the loop                                       
	auto end = chrono::high_resolution_clock::now();
	int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
	double seconds = microseconds / 1E6;
	cout << "elapsed time: " << fixed << setprecision(6) << seconds << " seconds" << endl;
	return EXIT_SUCCESS;
}
