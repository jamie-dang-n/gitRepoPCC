// Author: Jamie Dang
// Date: 5/22/24
// Program Number: Project 4
// Purpose: header file for the Website class. 
// Module name: website.h

#ifndef WEBSITE_H
#define WEBSITE_H

#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

// Constants
const int TOPIC_WIDTH = 25;
const int KEY_WIDTH = 25;
const int ADDRESS_WIDTH = 30;
const int SUMMARY_WIDTH = 45;
const int REVIEW_WIDTH = 35;
const int RATING_WIDTH = 7;	

class Website {
	private:
		// Data members
		char * topic;
		char * key;
		char * address;
		char * summary;
		char * review;
		int rating;

		// Helper function to initialize website data 
		void init(const char * topic, const char * key, const char * address, const char * summary, const char * review, const int rating);
	public:	
		// Constructors and destructors
		Website();
		Website(const char * topic, const char * key, const char * address, 
				const char * summary, const char * review, const int rating);
		Website(const Website& aSite);
		~Website();

		// Getters
		const char * getTopic() const;
		const char * getKey() const;
		const char * getAddress() const;
		const char * getSummary() const;
		const char * getReview() const;
		int getRating() const;	

		// Setters
		void setTopic(const char * topic);
		void setKey(const char * key);
		void setAddress(const char * address);
		void setSummary(const char * summary);
		void setReview(const char * review);
		void setRating(const int rating);

		// Operators
		const Website& operator= (const Website& aSite);
		friend ostream& operator<< (ostream& out, const Website& aSite);	
};

#endif
