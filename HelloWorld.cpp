#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdlib>
#include<utility>
#include<conio.h>
#include<ctime>

#include "print.h"

#define separateRecords std::cout << std::endl << "**************************************" << std::endl;

class ReportCard
{
private:
	std::map<std::string, double> m_report_card;

public:

	std::map<std::string, double>& getReportCardInstance()
	{
		return m_report_card;
	}

};


class Student
{

private:
	int m_roll_no;
	std::string m_name;

	ReportCard m_reportCard;
	
public:
	Student(int inRollNo, const std::string& inName) : m_roll_no( inRollNo ), m_name(inName)
	{

	}
	 
	std::string getName() const
	{
		return m_name;
	}

	int getRollNo() const
	{
		return m_roll_no;
	}

	ReportCard& getReportCard()
	{
		return m_reportCard;
	}

	std::size_t getReportCardSize()
	{
		return m_reportCard.getReportCardInstance().size();
	}
};

class Driver
{
private:
	char input;
	std::vector<Student> student_list;
	std::vector<Student> temp;

public:
	void studentTestPopulate()
	{
		student_list.emplace_back(1, "Tim");
		student_list.emplace_back(2, "Matt");
		student_list.emplace_back(100, "Luke");
		student_list.emplace_back(68, "Lissy");
		student_list.emplace_back(20, "Tony");
		student_list.emplace_back(33, "Joseph");
		student_list.emplace_back(14, "Sid");
		student_list.emplace_back(15, "Roby");
		student_list.emplace_back(44, "Rohan");
		student_list.emplace_back(11, "Kevin");
		student_list.emplace_back(19, "George");
	}

	void reportCardPopulate()
	{
		for (auto& student : student_list)
		{
			student.getReportCard().getReportCardInstance().emplace("Math", generateMark);
			student.getReportCard().getReportCardInstance().emplace("Geography", generateMark);
			student.getReportCard().getReportCardInstance().emplace("French", generateMark);
			student.getReportCard().getReportCardInstance().emplace("History", generateMark);
		}
	}

	void showAllStudentDetails()
	{
		for (auto& student : student_list)
		{
			std::cout << student.getName() << std::endl;
			std::cout << student.getRollNo() << std::endl;

			std::cout << "REPORT CARD : " << std::endl;
			
			for (auto& mark : student.getReportCard().getReportCardInstance())
			{
				std::cout << mark.first << std::endl;
				std::cout << mark.second << std::endl;
			}

			separateRecords

		}
	}

	void showTemp()
	{
		for (auto& t : temp)
		{
			std::cout << t.getName() << std::endl;
			std::cout << t.getRollNo() << std::endl;

			for (auto& mark : t.getReportCard().getReportCardInstance())
			{
				std::cout << mark.first << std::endl;
				std::cout << mark.second << std::endl;
			}

			separateRecords
		}
	}

	inline void clearTemp()
	{
		temp.clear();
	}

	void drawGUI()
	{
		double math_total = 0.0;

		showAllStudentDetails();

		do
		{

			std::cout << "a. Copy To Temp" << std::endl;
			std::cout << "b. Copy To Temp If Marks in Math < 50 " << std::endl;
			std::cout << "c. Remove Student name Kevin From Temp" << std::endl;
			std::cout << "d. Remove From Temp If Marks in Math < 50 " << std::endl;
			std::cout << "e. Sort According To Math Marks" << std::endl;
			std::cout << "f. Find Total Marks of Class in Math" << std::endl;
			std::cout << "g. See Temp" << std::endl;
			std::cout << "h. See Student List" << std::endl;

			separateRecords

			std::cout << "Enter choice: ";
			std::cin >> input;

			switch (input)
			{
			case 'a':
				std::copy(student_list.begin(), student_list.end(), std::back_inserter(temp));
				break;

			case 'b':
				std::copy_if(student_list.begin(), student_list.end(), std::back_inserter(temp), 
					[](Student s1) { return s1.getReportCard().getReportCardInstance()["Math"] < 50; });
				break;

			case 'c':
				break;

			case 'd':
				std::remove_if(student_list.begin(), student_list.end(), 
					[](Student s1) { return s1.getReportCard().getReportCardInstance()["Math"] < 50; });
				break;

			case 'e':
				std::sort(student_list.begin(), student_list.end(),
					[](Student s1, Student s2) { return s1.getReportCard().getReportCardInstance()["Math"] <
					s2.getReportCard().getReportCardInstance()["Math"]; });
				break;

			case 'f':
				std::for_each(student_list.begin(), student_list.end(),
					[&math_total](Student s1) {math_total + s1.getReportCard().getReportCardInstance()["Math"]; return math_total; } );
				std::cout << "\n\nTotal Math Mark : " << math_total << std::endl;
				break;

			case 'g':
				showTemp();
				break;

			case 'h':
				showAllStudentDetails();
				break;
			}

			separateRecords

		} while (input != 'x');
	}
};

int main()
{
	srand(time(NULL));

	Driver driver;
	driver.studentTestPopulate();
	driver.reportCardPopulate();
	driver.drawGUI();
}