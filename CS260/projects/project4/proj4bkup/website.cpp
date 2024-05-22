// Author: Jamie Dang
// Date: 5/22/24
// Program Number: Project 4
// Purpose: implementation file for Website class.
// Module name: website.cpp

#include "website.h"

// Default Constructor
Website::Website() : topic(nullptr), key(nullptr), address(nullptr), 
				     summary(nullptr), review(nullptr), rating(-1) {
}

// Parameterized Constructor
Website::Website(const char * topic, const char * key, const char * address, 
				 const char * summary, const char * review, const int rating)
				 : topic(nullptr), key(nullptr), address(nullptr), 
				   summary(nullptr), review(nullptr), rating(-1)  {
	init(topic, key, address, summary, review, rating);
}

// Copy Constructor
Website::Website(const Website& aSite) {
	init(aSite.topic, aSite.key, aSite.address, aSite.summary, aSite.review, aSite.rating);
}

// Destructor
Website::~Website() {
	// setting non-dynamic variables to null values
	rating = -1;

	// Deleting dynamic memory
	if (topic) {
		delete[] topic;
	}

	if (key) {
		delete[] key;
	}

	if (address) {
		delete[] address;
	}

	if (summary) {
		delete[] summary;
	}

	if (review) {
		delete[] review;
	}

	topic = nullptr;
	key = nullptr;
	address = nullptr;
	summary = nullptr;
	review = nullptr;
}

// **** Getters
const char * Website::getTopic() const {
	return topic;
}

const char * Website::getKey() const {
	return key;
}

const char * Website::getAddress() const {
	return address;
}

const char * Website::getSummary() const {
	return summary;
}

const char * Website::getReview() const {
	return review;
}

int Website::getRating() const {
	return rating;
}	

// **** Setters
void Website::setTopic(const char * topic) {
	if (this->topic) {
		delete[] this->topic;
		this->topic = nullptr;
	}
	this->topic = new char [strlen(topic) + 1];
	strcpy(this->topic, topic);
}

void Website::setKey(const char * key) {
	if(this->key) {
		delete[] this->key;
		this->key = nullptr;
	}
	this->key = new char [strlen(key) + 1];
	strcpy(this->key, key);
}

void Website::setAddress(const char * address) {
	if (this->address) {
		delete[] this->address;
		this->address = nullptr;
	}
	this->address = new char [strlen(address) + 1];
	strcpy(this->address, address);
}

void Website::setSummary(const char * summary) {
	if (this->summary) {
		delete[] this->summary;
		this->summary = nullptr;
	}
	this->summary = new char [strlen(summary) + 1];
	strcpy(this->summary, summary);
}

void Website::setReview(const char * review) {
	if (this->review) {
		delete[] this->review;
		this->review = nullptr;
	}
	this->review = new char [strlen(review) + 1];
	strcpy(this->review, review);
}

void Website::setRating(const int rating) {
	this->rating = rating;
}

// **** Private Methods

// Name:    init
// Purpose: helper function that calls all setters to set data members to arguments given
void Website::init(const char * topic, const char * key, const char * address, 
				   const char * summary, const char * review, const int rating) {
	setTopic(topic);
	setKey(key);
	setAddress(address);
	setSummary(summary);
	setReview(review);
	setRating(rating);
}

// **** Operators

// Assignment operator overload
const Website& Website::operator= (const Website& aSite) {
	if (this == &aSite) {
		return *this;
	}
	init(aSite.topic, aSite.key, aSite.address, aSite.summary, aSite.review, aSite.rating);
	return *this;	
}

// Insertion operator overload
ostream& operator<< (ostream& out, const Website& aSite) {
	out << left << setw(KEY_WIDTH) << aSite.key << ';';
	out << setw(TOPIC_WIDTH) << aSite.topic << ';';
	out << setw(ADDRESS_WIDTH) << aSite.address << ';';
	out << setw(SUMMARY_WIDTH)  << aSite.summary << ';';
	out << setw(REVIEW_WIDTH) << aSite.review << ';';
	out << setw(RATING_WIDTH) << aSite.rating << endl;

	return out;	
}

