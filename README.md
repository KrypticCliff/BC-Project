# LIDAR-Scan-Generator
Program creates a simulated LIDAR scan and includes a Max/Min and Mean filter.

<b>Filters_Cliff.cpp</b>

	Filters_Cliff.cpp contains the source code for two functions that return a 1D vector: range_update(std::vector) and tm_update(std::vector<std::vector>). Both functions manipulate a passed vector (range_update) or vector of vectors (tm_update) according to the design mentioned within the challenge.

	<b>std::vector<float> range_update(std::vector<float> )</b>
	
		The range_update function is used for scanning a list of vectors and converting any simulated distance value that exceeds the max (50.0) or minimum (0.03) value to the required value. The function requires a 1D vector that contains N amount of values. A for-loop is used to iterate through each index based on  “vector size – 1”. 
		If the value of vector[xi] is below float value 0.03, the value within the vector is modified to be exactly 0.03. If the value of vector[xi] is above 50.0, the value within the vector is modified to be exactly 50.0. Once the loop is completed, the modified vector is returned.

	std::vector<float> tm_update(std::vector<std::vector<float> > )
		
		The tm_update function iterates through a 2D vector and creates a new 1D vector containing the medians of previously combined 2D vectors. Two variables will need to be passed into the function: a 2D vector (which continuously increases its row size within the main.cpp file) and an integer containing N amount of distance values within each vector.

		The function first checks whether the passed 2D vector contains the size of “0”. If so, the program will exit the program due to an invalid number. If the 2D vector size is “1”, the first vector it reaches will be immediately returned since there are no vectors before that instance.

		If the vector size is even (size/2 has a remainder of 0), the vector contains two middle values. The function iterates through the “x” index of the passed 2D vector (vec_scan[x][y]) and places each value into a temporary vector (v_temp). In other words, the inner loop grabs all values in vec_scan[xi][0] and sends them to v_temp. The v_temp vector is then sorted in descending order to grab the middle values which are located at index “((v_temp size / 2) -1)” and “(v_temp size / 2) ”. The middle values are added together and divided by 2 to get the median. The median value is pushed into a the vector lr_median and increments the “y” index (vec[xi][1]) for the next vector value. The process is continued until the end of the vector index “yn” is reached.

		If the vector size is odd (size/2 has a remainder of 1), the vector only has one middle value. The loop iterates through all of “x” indexed values and placed into v_temp. The vector undergoes sorting then has its middle value extracted using v_temp index “(size/2)”. The value is pushed into lr_median and continues the iteration through the “y” index. After reaching the end of “yn” index, lr_median is returned.







<b> ScanSim_Cliff.cpp </b>
	
	ScanSim_Cliff.cpp contains the source file of two functions: scanGen(int) which returns a randomly generated 1D vector and getScan(std::vector<std::vector> >) for displaying the contents of a 2D vector to the terminal. 

	scanGen(int)

		This function is used to create a 1D vector of randomly generated numbers (between 0.0 and 60.0). An integer must be passed into the function to indicate the length of simulated values (N_DIST) needed to be inserted into the vector. A loop based on N_DIST will continuously push random values into a vector (f_vec). Once the loop finishes, the program will pause for approximately one second (usleep(1 x 106)) to create a new set of random numbers the next time the function is ran. 

	getScan(std::vector<std::vector<float> > )

		getScan displays each value displayed in a 2D vector. A filled 2D vector must be passed into the function. The outer loop iterates through the “x” index of the passed 2D vector (lr_scan[x][y]) and also outputs which numbered set of vectors is displayed. The inner loop iterates through the “y” index of the 2D vector and displays the simulated value up to the third decimal place.

Rawlings-Clifton-Main.cpp
	
	This file contains the instructions to create the distance value generator and apply each filter to the values. 

	N_VEC_LIST is the amount of vectors the file will create. Increasing the value will increase the amount of rows the 2D vector will have. The N_DIST variable is the amount of values the vectors will have in each set. Increasing the value will increase the column of all created vectors. These values are set to a low number for testing purposes and readability.

	A loop is created using N_VEC_LIST which makes N amount of vectors inside a 2D vector. The vector “temp” is created to grab a randomly generated vector list. Temp is passed into the 2D vector lr_scan to display the original set of values within the vector. Temp is also passed into the range_update function which is then pushed into the 2D vector lr_range. A temporal 2D vector is used to keep track of all the vectors {N, N-1, N-2, … , N-D} created in previous iterations. The temporal vector is passed into the tm_update function, along with N_DIST and pushed into the 2D vector lr_median. Lastly, the getScan() function will display all 2D vectors in a slightly readable manner.
