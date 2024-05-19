// Author: Jamie Dang
// Date: 5/14/2024
// Program Number: CS260 Project 3
// Purpose: header file for the Website class. 
// Module name: website.h

#ifndef WEBSITE_H
#define ENTRY_H

#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

// Constants
const int TOPIC_WIDTH = 20;
const int ADDRESS_WIDTH = 25;
const int SUMMARY_WIDTH = 45;
const int REVIEW_WIDTH = 35;
const int RATING_WIDTH = 7;	

class Website {
	private:
		// Data members
		char * topic;
		char * address;
		char * summary;
		char * review;
		int rating;

		// Helper function to initialize website data 
		void init(const char * topic, const char * address, const char * summary, const char * review, const int rating);
	public:	
		// Constructors and destructors
		Website();
		Website(const char * topic, const char * address, 
				const char * summary, const char * review, const int rating);
		Website(const Website& aSite);
		~Website();

		// Getters
		const char * getTopic() const;
		const char * getAddress() const;
		const char * getSummary() const;
		const char * getReview() const;
		int getRating() const;	

		// Setters
		void setTopic(const char * topic);
		void setAddress(const char * address);
		void setSummary(const char * summary);
		void setReview(const char * review);
		void setRating(const int rating);

		// Operators
		const Website& operator= (const Website& aSite);
		friend ostream& operator<< (ostream& out, const Website& aSite);	
};

#endif
