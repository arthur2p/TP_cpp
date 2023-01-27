/**
  * @File: date.h
  * @Author: d0m <dginhac@u-bourgogne.fr>
  * @Created on : 2022-10-03 09:12:05
  * @Last Modified time: 2022-10-03 15:15:03
  *
  * @Description: Date Class Declaration
  */


#pragma once
#include <iostream>

class Date {
public:
	Date(int year = 1900, int month = 1, int day = 1);
	int year() const;
	int month() const;
	int day() const;
	void updateYear(int year);
	void updateMonth(int month);
	void updateDay(int day);
	void next();
	void back();
	Date operator+(int days) const;
	Date operator-(int days) const;
	int operator-(const Date& date) const;
	
	bool operator>=(const Date& date) const;
	bool operator<=(const Date& date) const;
	bool operator>(const Date& date) const;
	bool operator<(const Date& date) const;
	bool operator==(const Date& date) const;
	
private:
	int _year;
	int _month;
	int _day;

};

bool isDate(int year, int month, int day);
bool isYearbissextiles(int year);
int getDaysInMonth(int year, int month);
int dayOfYear(Date d);
std::string toString(Date d);

