#ifndef _IO_h
#define _IO_h

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
//#include <sstream>


using std::cout;
using std::string;
using std::cin;
using std::fstream;

class IO
{
private:
	double percent_beginner;
	double percent_intermediate;
	double percent_advanced;
	double arrival_rate;

public:
	/**
	Gets the data from the user.
	*/
	void get_data()
	{
		input_beginner_percent();
		input_intermediate_percent();
		input_advanced_percent();
		input_arrival_rate();
	}

	/**
	Gets the percentage of beginner riders from the user.
	*/
	void input_beginner_percent()
	{
		try
		{
			cout << "Enter the percentage of beginner riders: ";
			cin >> percent_beginner;
		}
		catch (std::invalid_argument exp)
		{
			cout << "Please input a value as a double between 0 and 1.\n";
			cout << exp.what() << std::endl;
			input_beginner_percent();
		}
	}

	/**
	Gets the percentage of intermediate riders from the user.
	*/
	void input_intermediate_percent()
	{
		try
		{
			cout << "Enter the percentage of intermediate riders: ";
			cin >> percent_intermediate;
		}
		catch (std::invalid_argument exp)
		{
			cout << "Please input a value as a double between 0 and 1.\n";
			cout << exp.what() << std::endl;
			input_intermediate_percent();
		}
	}

	/**
	Gets the percentage of advanced riders from the user.
	*/
	void input_advanced_percent()
	{
		try
		{
			cout << "Enter the percentage of advanced riders: ";
			cin >> percent_advanced;
		}
		catch (std::invalid_argument exp)
		{
			cout << "Please input a value as a double between 0 and 1.\n";
			cout << exp.what() << std::endl;
			input_advanced_percent();
		}
	}

	/**
	Gets the arrival rate of riders from the user
	*/
	void input_arrival_rate()
	{
		int rate = 0;

		try
		{
			cout << "Enter the arrival rate of riders (riders/hour): ";
			cin >> rate;
			arrival_rate = rate / 60.0;
		}
		catch (std::exception exp)
		{
			cout << "Please input an integer value.\n";
			cout << exp.what() << std::endl;
			input_beginner_percent();
		}
	}


	/**
	@return string of what the user input
	*/
	string get_input()
	{
		string resp;
		cout << ">>: ";
		std::getline(cin, resp);

		return resp;
	}


	/**
	gets all of the names from the .txt file
	*/
	std::vector<string> input_data_from_file()
	{
		string s;
		std::vector<string> names;

		fstream myfile;

		try
		{
			myfile.open("resdients_273ville.txt", std::ios::in);

			while (!myfile.eof())
			{
				getline(cin, s);
				names.push_back(s);
			}

			myfile.close();
		}
		catch (std::exception exp)
		{
			cout << "Cannot find the file" << endl;
		}

		return names;
	}


	/**
	Outputs the data that we are going to process to a file.
	*/
	void output_data_to_file(int average_wait_time_chairlifts, int total_wait_time_chairlifts,
		int average_wait_time_trialheads, int total_wait_time_trailheads)
	{
		fstream out_file;

		out_file.open("Data_to_graph.txt", std::ios::out);

		out_file << "Percentage of beginner riders: " << percent_beginner << std::endl;
		out_file << "Percentage of intermedieate riders: " << percent_intermediate << std::endl;
		out_file << "Percentage of advancded riders: " << percent_advanced << std::endl;
		out_file << std::endl;

		/**FIX ME:
		Need to implement a way to print out all of the data from Simulator::process_data
		Probably use a vector for the parameters for this method. And then use for loops
		*/

		out_file.close();
	}

	double get_pbeginner(){ return percent_beginner; }
	double get_pintermediate(){ return percent_intermediate; }
	double get_padvanced(){ return percent_advanced; }

};

#endif