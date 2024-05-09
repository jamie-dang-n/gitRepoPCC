#include <cstring>

class Website {
	private:
		// Data members
		char * topic;
		char * address;
		char * summary;
		char * review;
		int rating;

		// Helper function to initialize website data 
		void init(const char * topic, const char * address, 
				  const char * summary, const char * review, const int rating);

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
			
};
