#include "website.h"

Website::Website() : topic(nullptr), address(nullptr), summary(nullptr),
					 review(nullptr), rating(-1) {
}

Website::Website(const char * topic, const char * address, 
				const char * summary, const char * review, const int rating)
				: topic(nullptr), address(nullptr), summary(nullptr),
			      review(nullptr), rating(-1)  {
	init(topic, address, summary, review, rating);
}

Website::Website(const Website& aSite) {
}

Website::~Website() {
	// setting non-dynamic variables to null values
	rating = -1;

	// Deleting dynamic memory
	if (topic) {
		delete [] topic;
	}

	if (address) {
		delete [] address;
	}

	if (summary) {
		delete [] summary;
	}

	if (review) {
		delete [] review;
	}

	topic = nullptr;
	address = nullptr;
	summary = nullptr;
	review = nullptr;
}

// Getters
const char * Website::getTopic() const {
	return topic;
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

// Setters
void Website::setTopic(const char * topic) {
	if (this->topic) {
		delete[] this->topic;
		this->topic = nullptr;
	}
	this->topic = new char [strlen(topic) + 1];
	strcpy(this->topic, topic);
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

// Private helper
void Website::init(const char * topic, const char * address, 
				   const char * summary, const char * review, const int rating) {
	setTopic(topic);
	setAddress(address);
	setSummary(summary);
	setReview(review);
	setRating(rating);
}

// Operator
const Website& Website::operator= (const Website& aSite) {
	if (this == &aSite) {
		return *this;
	}
	init(aSite.topic, aSite.address, aSite.summary, aSite.review, aSite.rating);
	return *this;	
}

