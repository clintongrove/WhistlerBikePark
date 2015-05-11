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
using std::vector;

class IO
{
private:
	double percent_beginner;
	double percent_intermediate;
	double percent_advanced;
	double arrival_rate;

public:
	IO(){}

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
			double x;
			cout << "Enter the percentage of beginner riders: ";
			cin >> percent_beginner;
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
	string print_menu()
	{
		cout << "Please choose what you would like to do.\n";
		cout << "1. Run simulation\n";
		cout << "2. Search for stats\n";
		cout << "3. Output data to file\n";
		cout << "4. Exit\n";

		string resp = get_input();
		return resp;
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


	/**
	gets all of the names from the .txt file
	*/
	std::vector<string> input_data_from_file()
	{
		//char* s = new char();
		string s;
		std::vector<string> names;

		fstream myfile;
		std::streamsize n = 100;

		try
		{
			myfile.open("residents_273ville.txt", std::ios::in);

			while (!myfile.eof())
			{
				std::getline(myfile, s);
				names.push_back(s);
			}

			myfile.close();
		}
		catch (std::exception exp)
		{
			std::cout << "Cannot find the file" << std::endl;
		}
		catch (...)
		{
			std::cout << "Don't know what is happening.\n" << std::endl;
		}

		//delete s;
		return names;
	}


	/**
	Outputs the data that we are going to process to a file.
	*/
	void output_data_to_file(vector<int> average_wait_time_chairlifts, vector<int> total_wait_time_chairlifts,
		vector<int> average_wait_time_trailheads, vector<int> total_wait_time_trailheads, vector<int> ticket_stats)
	{
		fstream out_file;

		out_file.open("Data_to_graph.txt", std::ios::out);

		out_file << "Percentage of beginner riders: " << percent_beginner << std::endl;
		out_file << "Percentage of intermedieate riders: " << percent_intermediate << std::endl;
		out_file << "Percentage of advancded riders: " << percent_advanced << std::endl;
		out_file << std::endl;

		out_file << "Average wait time for trailheads.\n";
		for (int i = 0; i < average_wait_time_trailheads.size(); i++)
		{
			out_file << average_wait_time_trailheads[i] << std::endl;
		}

		out_file << "Total wait time for trailheads.\n";
		for (int i = 0; i < total_wait_time_trailheads.size(); i++)
		{
			out_file << total_wait_time_trailheads[i] << std::endl;
		}

		out_file << "Average wait time for trailheads.\n";
		for (int i = 0; i < average_wait_time_chairlifts.size(); i++)
		{
			out_file << average_wait_time_chairlifts[i] << std::endl;
		}

		out_file << "Total wait time for trailheads.\n";
		for (int i = 0; i < total_wait_time_chairlifts.size(); i++)
		{
			out_file << total_wait_time_chairlifts[i] << std::endl;
		}

		out_file << "Beginner Rider average trailhead wait time: " << ticket_stats[0] << std::endl;
		out_file << "Beginner Rider average chairlift wait time: " << ticket_stats[1] << std::endl;
		out_file << "Intermdediate Rider average trailhead wait time: " << ticket_stats[2] << std::endl;
		out_file << "Intermdediate Rider average chairlift wait time: " << ticket_stats[3] << std::endl;
		out_file << "Advanced Rider average trailhead wait time: " << ticket_stats[4] << std::endl;
		out_file << "Advanced Rider average chairlift wait time: " << ticket_stats[5] << std::endl;


		out_file.close();
	}

	string search_name()
	{
		cout << "Enter name to search: \n";
		return get_input();
	}

	void clear_cmd()
	{
		system("cls");
	}

	double get_pbeginner(){ return percent_beginner; }
	double get_pintermediate(){ return percent_intermediate; }
	double get_padvanced(){ return percent_advanced; }
	double get_arrival_rate(){ return arrival_rate; }

};

#endif