#ifndef _IO_h
#define _IO_h

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <set>
#include <string>
//#include <ios>
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

		if (!(get_pbeginner() + get_pintermediate() + get_padvanced()) == 1)
			throw std::invalid_argument("Percentages don't add to 1.\n");

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
			std::cin >> percent_beginner;
			if (percent_beginner > 1)
				throw std::invalid_argument("Percent is too big.\n");
		}
		catch (std::invalid_argument exp)
		{
			cout << exp.what() << "Please input a value as a double between 0 and 1.\n";
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
			if (percent_intermediate > 1)
				throw std::invalid_argument("Percent is too big.\n");
		}
		catch (std::invalid_argument exp)
		{
			cout << exp.what() << "Please input a value as a double between 0 and 1.\n";
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
			if (percent_advanced > 1)
				throw std::invalid_argument("Percent is too big.\n");
		}
		catch (std::invalid_argument exp)
		{
			cout << exp.what() << "Please input a value as a double between 0 and 1.\n";
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
		Prints the options that the user can do.
	*/
	void print_menu()
	{
		cout << "Please choose what you would like to do.\n";
		cout << "1. Run simulation\n";
		cout << "2. Search for stats\n";

	}

	/**
		Gets input from the user
	*/
	string get_input()
	{
		string resp;
		std::cout << ">>: ";
		std::cin >> resp;
		return resp;
	}

	void check_input(string resp)
	{
		if (resp == "1" || resp == "run simulation" || resp == "Run Simulation")
		{
			//FIXME
		}
		else if (resp == "2" || resp == "search" || resp == "Resp")
		{
			//FIXME
		}
		else
		{
			//FIXME
		}
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
				std::getline(cin, s);
				names.push_back(s);
			}

			myfile.close();
		}
		catch (std::exception exp)
		{
			std::cout << "Cannot find the file" << std::endl;
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

	void clear_cmd()
	{
		system("cls");
	}

	double get_pbeginner(){ return percent_beginner; }
	double get_pintermediate(){ return percent_intermediate; }
	double get_padvanced(){ return percent_advanced; }

};

#endif