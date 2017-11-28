/*Group 49
 *Dylan Markovic, Charlotte Murphy, Terezie Schaller
 *CS325-400
 *Final
 *Due Date: 12.01.2017
 */
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <sstream>
 #include <string>
 #include <vector>
 #include <cmath>
 //change DEBUG to 0 to run without debugging output messages
 #define DEBUG 1

//struct city holds three ints, the id, the x coordinate, and the y coordinate
struct city{
	int id;
	int x;
	int y;
};

int distance(struct city a, struct city b);

int main(int argc, char *argv[]){
	//make sure number of arguments is correct
	if (argc != 2){
		std::cout<<"Invalid number of arguments\n";
		return 0;
	}
		
	std::string line; //var to hold each line of file being read
	std::ifstream inputFile;
	inputFile.open(argv[1]);
	//check for successful file open
	if(!inputFile.is_open()){
		std::cout<< "Could Not Open File: " <<argv[1]<<"\n";
		return 0;
	}

	//container to hold cities
	std::vector<city> cityList;
	int count = 0; //used for testing
	while(!inputFile.eof()){
		std::getline(inputFile, line);
		std::stringstream cityStrm(line);
		struct city temp;
		cityStrm>>temp.id>>temp.x>>temp.y;
		cityList.push_back(temp);
		count++;
	}
	if (DEBUG){
		struct city a, b, c;
		a.id = 1;
		a.x = a.y = 0;
		b.id = 2;
		b.x = 1;
		b.y = 3;
		c.id = 3;
		c.x = 6;
		c.y = 0;
		std::cout<< "distance from a to b should be 3.  It is calculated to be: " << distance(a,b) << "\n";
		std::cout<< "distance from b to c should be 6.  It is calculated to be: " << distance(b,c) << "\n";
		std::cout<< "distance from c to a should be 6.  It is calculated to be: " << distance(c,a) << "\n";
	}
	if(DEBUG)
		if(count == cityList.size())
			std::cout << "count matches cityList size\n";
		else
			std::cout << " count is " << count << " and cityList's size is " << cityList.size() << " !!!!!!!!\n";
	
	if(DEBUG){
		for(int i = 0; i < cityList.size(); i++)
			std::cout<< cityList[i].id << " " << cityList[i].x <<" " << cityList[i].y << "\n";
	}
	
	//close file
	inputFile.close();
	
	/*
	 * begin solving tsp problem below
	 */
	
	return 0;
	
}
 
int distance(struct city a, struct city b){
	return round(sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2)));
} 
