
// This is start of the header guard. 
#ifndef PRESIDENT_H
#define PRESIDENT_H

class Country {
	public:
		Country(int a, int b);
		int aliens;
		int jobs;
		bool invasion;
		bool job_message;
};

class President {

	public:
		// President constructor
		President();
		
		// executes proper action based on user selection
		void action(int sel, Country &a);
		
	    // triggers a random event every 3 moves
		void rand_event(Country &a);
		
		// used to monitor President's stats
		// as well as the country's
		void monitor(Country &a);
		
		void goals(Country &a);
		
		bool success;
		
		
	private:
	
		// these are the countries that President can get into
		// a Twitter war with
		struct countries{
			bool china;
			bool isis;
			bool libya;
			bool n_korea;
		} war;
		
		// these are actions the user can choose, program remembers
		// if the user has been through that menu before 
		struct text{
			bool eat;
			bool tweet;
			bool wall;
			bool attack;
			bool jobs;
			bool pamper;
			bool deport;
		} did;
		
		// these are certain actions the user
		// can accomplish which need to be stored
		struct progress{
			bool calmed; 		// get rid of Trump's anger
			bool max_health; 	// get Trump's health to 100
			bool max_ego; 		// get Trump's ego to 100
			bool chef;			// fire the chef
		} has;
		
		// stats that will increase/decreased based
		// on how the user plays the game
		int health;
		int ego;
		int anger;
		int score;
		
		// President's action choices
		void stats(Country &a);
		void attack();
		void eat();
		void tweet();
		void jobs(Country &a);
		void pamper();
		void wall();
		void deport(Country &a);				
};
 
// This is the end of the header guard
#endif