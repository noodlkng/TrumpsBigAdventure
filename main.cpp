/******************************************************
** Program: main.cpp
** Author: Matt Shilling
** Date: 1/18/2017
** Description: Play as Trump and try to go down as the best president in history
				by completing certain goals
** Input: 1-9 controls many actions that Trump can do
** Output: Random numbers control most of the outcomes of the user's choices
******************************************************/


// TRUMP'S BIG WHITEHOUSE ADVENTURE
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string>
#include <limits>

#include "president.h"

using namespace std;

/* INFRASTRUCTURE */

// "clears" screen by clearing a lot of lines
void clear_screen() {
	for(int i = 0; i < 100; i++) {
		cout << endl;
	}
}

// sleep function with seconds
void Sleep(float s){
	int sec = int(s*1000000);
	usleep(sec);
}

// prints a tab 
void tab(int x){
	for(int i=0;i<x;i++){
		cout << "	";
	}
}

// makes text look like its being typed
void scroll(string text, float time = 0.02){
	tab(1);
	for (int i=0; i<text.length();i++){
		Sleep(time);
		cout << text[i] << flush;
	}
}


/* CLASS COUNTRY */
Country::Country(int a, int b){
	aliens = a;
	jobs   = b;
	invasion = true;
	job_message = false;
}

/* CLASS PRESIDENT */
President::President() {
	
	// seed rand
    srand(time(NULL));
	
	// give ego a rand value between 0 and 30
	ego = rand()%30;
	score    = 0;
	// trump is 75% angry
	anger    = 75;
	
	// init booleans
	has.calmed  = false;
	has.max_ego = false;
	has.chef    = true;
	success     = false;
	 
	war.china   = false;
	war.isis    = false;
	war.libya   = false;
	war.n_korea = false;
	
	did.eat     = false;
	did.tweet   = false;
	did.wall    = false;
	did.attack  = false;
	did.jobs    = false;
	did.pamper  = false;
	did.deport  = false;
}

// function of President that monitors the stats
void President::monitor(Country &a){
	
	// if user found all aliens 
	if(a.aliens <= 0 && a.invasion){
		scroll("You have found all the aliens! Congratulations!\n");
		a.aliens = 0;
		a.invasion = false;
		score += 3;
	}
	
	// if user calmed trump
	if(anger <= 0 && !has.calmed){
		scroll("You have calmed Trump's anger! Congratulations!\n");
		has.calmed = true;
		score++;
	}
	
	// user got trump's ego to 100
	if(ego >= 100 && !has.max_ego){
		scroll("You have maximized Trump's ego! Congratulations!\n");
		has.max_ego = true;
		score++;
	}
	
	// if user created 15000 jobs
	if(a.jobs > 115000 && !a.job_message){
		scroll("Congratulations! You have brought back 15,000 jobs\n");
		scroll("Be careful though, jobs will keep decreasing each turn...\n");
		a.job_message = true;
	}
	
	// jobs have fallen back under 15000
	if(a.job_message && a.jobs < 115000){
		scroll("Warning!! Job's have decreased and you must add more\n");
	}
	
	// user has succeeded with all goals 
	if(has.max_ego && !a.invasion && a.jobs > 115000 
		&& did.wall && did.pamper && !has.chef && did.tweet){
		cout << endl;
		for(int i = 0; i < 4; i++) {
			scroll("Congratulations!\n");
			clear_screen();
			Sleep(.5);
		}
		
		/* PRINT CONGRATULATION MESSAGE */
		scroll("You have succeeded in accomplishing everything\n");
		scroll("you needed to, President Trump!\n");
		scroll("[x] Maximize Trump's ego\n");
		scroll("[x] Build a wall\n");
		scroll("[x] Send a tweet\n");
		scroll("[x] Become orange\n");
		scroll("[x] Fire the chef\n");
		scroll("[x] Find all space aliens\n");
		scroll("[x] Bring back 15,000 jobs\n\n");
		
		scroll("You will go down in history as the greatest\n");
		scroll("President of the United States of America!\n");
		for(int i = 0; i < 10; i++){
			scroll("\n", 0.1); 
		}
		
		scroll("THANKS FOR PLAYING!\n");
		
		for(int i = 0; i < 10; i++){
			scroll("\n", 0.1);
		}
		success = true;
		/* END CONGRATS */
	}
	
	
}

// function of President that displays stats
void President::stats(Country &a){
	cout << endl;
	
	/* PRINT OUT STATS OF TRUMP */
	scroll("Trump's anger: ");
	if(!has.calmed) cout << anger << endl;
	else scroll("You've calmed Trump!\n");
	
	scroll("Trump's ego: ");
	if(!has.max_ego) cout << ego << endl;
	else scroll("You've maxed Trump's ego!\n");
	
	scroll("Job's you've brought back to the US: ");
	cout << a.jobs - 100000 << endl;
	
	scroll("Aliens in the US: ");
	if(a.invasion) cout << a.aliens << endl;
	else scroll("You've found all aliens!\n");
	/* END STATS */
	
	cout << endl;
	
}

// function of President that shows the goals
// and which ones the user needs to complete
void President::goals(Country &a){
	
	/* PRINT OUT THE GOALS NEEDED */
	scroll("Do the following to become the best President in history:\n");
	
	if(has.max_ego) scroll("[x] Maximize Trump's ego\n");
	else scroll("[ ] Maximize Trump's ego\n");
	
	if(did.wall) scroll("[x] Build a wall\n");
	else scroll("[ ] Build a wall\n");
	
	if(did.tweet) scroll("[x] Send a tweet\n");
	else scroll("[ ] Send a tweet\n");
	
	if(did.pamper) scroll("[x] Become orange\n");
	else scroll("[ ] Become orange\n");
	
	if(!has.chef) scroll("[x] Fire the chef\n");
	else scroll("[ ] Fire the chef\n");
	
	if(!a.invasion) scroll("[x] Find all space aliens\n");
	else scroll("[ ] Find all space aliens\n");
	
	if(a.jobs > 115000) scroll("[x] Bring back 15,000 jobs\n");
	else scroll("[ ] Bring back 15,000 jobs\n");
	
	cout << endl;
}

// function of President that initiates a twitter war
void President::attack(){
	
	int choice;
	cout << endl;
	// list "enemies" of Trump
	scroll("Here are a list of your enemies sir:\n");
	scroll("1.) North Korea\n");
	scroll("2.) China\n");
	scroll("3.) Libya\n");
	scroll("4.) ISIS\n");
	scroll("5.) Russia\n");
	scroll("Which country do you want to attack, Mr. Trump? ");
	// give user a choice
	cin >> choice;
	cout << endl;
	if(choice < 6 && choice > 0){
		
		// each selection will set the appropriate bool to true
		// and manipulate ego/anger
		switch (choice) {
			
			// user selects n korea
			case 1:
				if(!war.n_korea) {
					scroll("You just attacked North Korea with an angry tweet\n");
					war.n_korea = true;
					anger -= 10;
					ego += 5;
				}
				else scroll("You're already in a Twitter war with North Korea\n");
				break;
			
			// user selects china
			case 2:
				if(!war.china) {
					scroll("You just attacked China with a mean tweet!\n");
					war.china = true;
					anger -= 10;
					ego += 5;
				}
				else scroll("You're already in a Twitter war with China\n");
				break;
				
			// user selects libya
			case 3:
				if(!war.libya) {
					scroll("You just attacked Libya with a furious tweet!\n");
					war.libya = true;
					anger -= 10;
					ego += 5;
				}
				else scroll("You're already in a Twitter war with Libya\n");
				break;
				
			// user selects isis
			case 4:
				if(!war.isis) {
					scroll("You just attacked ISIS with a raging tweet!\n");
					war.isis = true;
					anger -= 10;
					ego += 5;
				}
				else scroll("You're already in a Twitter war with ISIS\n");
				break;
			
			// user selects russia	
			case 5:
				scroll("Putin says you can't say anything bad about Russia!\n");
				scroll("'Don't try this again, puppet'\n");
				scroll("-Putin\n");
				ego -= 10;
				break;
		}
	}
	else {
		scroll("\n");
		// please add else statement
	}

}

// function of President that gives user choices to eat
void President::eat(){
	
	int choice;
	
	// speed of text
	float speed = 0.01;
	cout << endl;
	
	// increase speed if user has already read menu
	// saves time
	if (did.eat){
		speed = 0.0001;
	}
	
	// chef has been fired
	if (!has.chef){
		scroll("I'm sorry, Mr. Trump. We fired your chef. Please wait until we\n");
		scroll("hire a new one to order any food. Thanks for your patience...\n");
	}
	else {
		
		// give user a selection
		while(!(choice < 7 && choice > 0)){
			scroll("Here is the menu today, President Trump:\n");
			scroll("1.) Cherry-Vanilla Ice Cream\n", speed);
			scroll("2.) Buttered Toast Crispy Fishwiches\n", speed);
			scroll("3.) Butter-Basted Rib Eye Steaks\n", speed);
			scroll("4.) Meatloaf Sandwich\n", speed);
			scroll("5.) Fried Mac and Cheese Bites\n", speed);
			scroll("6.) Bacon, Egg, and Toast Cups\n", speed);
			scroll("What would you like? ");
			cin >>  choice;
			scroll("\n");
			if(choice < 7 && choice > 0){
				
				// random chance of user getting food
				if(rand()%2) {
					
					scroll("Coming right up, sir...\n");
					Sleep(.25);
					scroll("Here is your food, Mr. President. Enjoy!\n");
					anger -= 20;
					Sleep(.5);
					char ans;
					
					scroll("Did you like your food, sir? (y)es or (n)o: ");
					cin >> ans;
					
					// user enjoyed the meal
					if(ans == 'y') {
						scroll("I'm glad you enjoyed it, I'll give my compliments to the cheff.\n");
					}
					
					// user didn't enjoy
					else {
						scroll("Oh no.. We will have to fire the chef immediately!\n");
						Sleep(.5);
						scroll("The chef has been fired.\n");
						has.chef = false;
						
						
					}
				}
				
				// out of the selection the user wanted 
				// random choice
				else {
					scroll("I'm so sorry, sir. We are all out!\n");
					scroll("Trump's anger rises...\n");
					anger += 10;
				}
				did.eat = true;
				Sleep(.5);
			}
			
			// user failed input
			else{
				clear_screen();
				scroll("Please choose again...\n");
			}
		}
	}
}


// function of President that gives user real quotes to tweet
void President::tweet(){ 
	int choice;
	float speed = 0.02;
	cout << endl;
	
	// speed of scrolling text changes
	if (did.tweet){
		speed = 0.0001;
	}
	
	// present tweet options to user
	// real quotes from D Trump
	while(!(choice < 7 && choice > 0)){
		scroll("Opening Twitter...\n");
		scroll("What would you like to tweet, Mr. Trump?\n");
		scroll("1.) 'All of the women on The Apprentice flirted with me -\n", speed);
		scroll("     consciously or unconsciously. That's to be expected.'\n\n", speed);
		scroll("2.) 'It's freezing and snowing in New York - we need global warming'\n\n", speed);
		scroll("3.) 'I've said if Ivanka weren't my daughter, perhaps I'd be\n");
		scroll("     dating her'\n\n", speed);
		scroll("4.) 'My fingers are long and beautiful, and it has been well\n", speed);
		scroll("     documented, like various other parts of my body'\n\n", speed);
		scroll("5.) 'My IQ is one of the highest - and you all know it! Please\n", speed);
		scroll("     don't feel so stupid or insecure; it's not your fault'\n\n", speed);
		scroll("6.) 'I have never seen a thin person drinking Diet Coke'\n\n", speed);
		scroll("What will you tweet? ");
		cin >>  choice;
		
		// if user response fits query
		if(choice < 7 && choice > 0){
			
			// random chance decides if the media likes the tweet
			if(rand()%2){
				scroll("Excelent choice, sir. The media loves it!\n");
				scroll("Trump's ego rises...\n");
				ego += 10;
			}
			
			// media doesn't like it based on rand
			else {
				scroll("Oh no! SNL is making fun of your tweet!\n");
				scroll("Trump's anger rises...\n");
				ego -= 10;
				
			}
			
			// the user has already been down this menu so save them some time
			did.tweet = true;
			Sleep(.5);
		}
		
		// user put in wrong input
		else{
			clear_screen();
			scroll("Please choose again...\n");
		}
	}
}

// function of President that can change the ammount of jobs in the country
// that is passed to it
void President::jobs(Country &a){
	
	cout << endl;
	scroll("Meeting with businesses to persuade them into bringing jobs back...\n");
	Sleep(.5);
	
	// rand to decide if the meeting is successful 
	if(rand()%2){
		
		// job increase by 0 to 10000
		int job_inc = rand()%10000;
		scroll("Your meeting was a success!\n");
		
		Sleep(0.5);
		
		scroll("You brought ");
		cout << job_inc;
		
		// add the job increase
		a.jobs += job_inc;
		
		cout << " jobs back to the USA!\n";
		scroll("Trump's ego rises...\n");
		
		// proportionally increase ego based on the 
		ego += job_inc*0.005;
	}
	
	// meeting fails based on rand
	else{
		scroll("Unfortunately, your meeting didn't go so well...\n");
		scroll("Trump's ego takes damage...\n");
		ego -= 5;
	}
	Sleep(0.5);
}

// function of President that gives him a tan
void President::pamper(){
	
	cout << endl;
	
	// initiate tanning sequence 
	scroll("Stepping inside tanning booth...\n");
	scroll("Tanning...\n");
	Sleep(2);
	
	// rand decides if tan turns out well
	if(rand()%2){
		scroll("Ouch! Your tan is botched. The media is making fun of you.\n");
		scroll("Trumps ego declines and anger rises...\n");
		ego -= 10;
		anger += 10;
		Sleep(.5);
	}
	
	// tan fails based on rand
	else {
		scroll("Great tan, sir!\n");
		scroll("Trumps ego increases...\n");
		ego+=10;
		sleep(.5);
	}
	
	// set bool so that you can achieve goal 
	did.pamper = true;
	
}

// function of President that lets user build a wall
void President::wall(){
	
	int choice;
	float speed = 0.01;
	cout << endl;
	
	// check if wall was already made 
	if (did.wall){
		scroll("Your wall is already built, Mr. President!\n");
	}
	
	else {
		
		// let user choose between 
		while(!(choice < 3 && choice > 0)){
			scroll("Welcome to Trump's Wall Builder\n");
			scroll("First off, choose who pays for the wall:\n");
			scroll("1.) Taxpayers\n", speed);
			scroll("2.) Mexico\n", speed);
			scroll("Well? ");
			cin >> choice;
			if(choice < 3 && choice > 0){
				
				if(choice == 1) ego -= 10;
				else ego += 10;
				scroll("\n");
				scroll("Building wall...\n",0.1);
				scroll("\n");
				
				// random chance of the wall being built
				if(rand()%4) {
					
					// pick random height
					int height = rand()%15;
					while(height == 0) height = rand()%15;
					
					scroll("Your wall has been successfully built!\n\n");
					
					// add an achievement
					score++;
					
					scroll("It is "); 
					cout << height;
					cout<<" feet tall";
					scroll("\n\n");
					
					// if the height is small give Trump crap
					if(height<8){
						scroll("That's actually pretty small...\n");
						scroll("Trump's ego takes damage...\n");
						ego -= 10;
					}
					
					// hey, that'ss pretty good
					else{
						scroll("That's a decent sized wall, nice job!\n");
						ego += 10;
					}
					
					// built a wall
					did.wall = true;
					
				}
				
				// building wall fails
				else {
					scroll("I'm so sorry, sir. Your wall crumbled!\n");
					scroll("Trump's anger rises...\n");
					scroll("Trump's ego takes damage...\n");
					anger += 30;
					ego -= 20;
					
					did.wall = false;
				}
				Sleep(1);
			}
			
			// user inputs wrong
			else{
				clear_screen();
				scroll("Please choose again...\n");
			}
		}
	
	}
	
}

// function of President that finds aliens and subtracts the # of
// aliens found from the country class that is passed to it
void President::deport(Country &a){
	
	// user choice
	string choice;
	
	// speed of scroll text
	float speed = 0.02;
	cout << endl;
	
	// check if user has seen the menu before 
	if (did.deport){
		speed = 0.0001;
	}
	else {
		scroll("As you know, millions of space aliens have invaded the US...\n");
		scroll("They are hiding, looking for the next opportunity to steal jobs... \n");
	}
	while(choice == ""){

		scroll("Where would you like to search for aliens? ");
		
		// fix weird bug
		cin.ignore(1,'\n');
		getline(cin, choice);
		scroll("\n");
		
		// if user actually entered something
		if(choice != ""){
			
			// random chance of finding an alien
			if(rand()%3){
				scroll("Found ");
				// random number of aliens from 0 to 10000
				int x = rand()%10000;
				cout << x;
				
				// subtract aliens 
				a.aliens -= x;
				cout << " aliens! Sending them back to space!\n";
				Sleep(.5);
				scroll("Trump's ego rises...\n");
				ego +=10;
				anger -= 10;
				
			}
			
			// finding aliens fails
			else {
				scroll("No aliens found!\n");
				scroll("Trump's anger rises...\n");
				anger += 10;
				ego -= 10;
				
			}
			
			// the user has already been to this menu so save them some time
			did.deport = true;
			scroll("\n");
			Sleep(.5);
		}
		
		// user input was bad
		else{
			clear_screen();
			scroll("Please choose again...\n");
		}
	}
	
}

// function of President that takes in a selection value and country class
// then executes the proper action
void President::action(int sel, Country &a){
	
	// execute proper action
	switch (sel) {
		case 1: eat();
				break;

		case 2: tweet();
				break;

		case 3: jobs(a);
				break;

		case 4: wall();
				break;
		
		case 5: attack();
				break;

		case 6: deport(a);
				break;
		
		case 7: pamper();
				break;
		
		case 8: stats(a);
				Sleep(1);
				break;
				
		case 9: goals(a);
				break;
	}
}

//function of President that picks a random event to execute
void President::rand_event(Country &a){
	cout << endl;
	int choice;
	
	// random gift of jobs/aliens leaving
	int aliens_away;
	int new_jobs;
	
	// char to hold response y/n
	char resp;
	
	// rand to choose the event
	int event_seed = rand()%7;
	switch(event_seed){
		case 0:
			// if user is in a twitter war 
			if(war.china || war.n_korea || war.isis || war.libya){
				scroll("Oh no! Due to your Twitter wars, your DM's have\n");
				scroll("flooded with angry messages!!\n");
				scroll("Would you like to retaliate with more tweets? (y)es or (n)o: ");
				cin >> resp;
				
				// does user want to tweet back 
				if(resp == 'y'){
					scroll("Firing back with an ill-tempered tweet!\n");
				}
				else scroll("Ignoring the hate...");
				
				// did the user make the right choice based on rand
				if(rand()%3){
					scroll("Your decision paid off! Good choice!\n");
					scroll("Trump's ego increases...\n");
					ego += 10;
				}
				// rand decided it was bad
				else{
					scroll("Your decision was terrible!\n");
					scroll("Trump's anger rises...\n");
					anger += 10;
				}
				
			}
			
			// user is not in a twitter war
			else {
				scroll("Trump is getting restless...\n");
				scroll("Maybe he should send an angry tweet to another country...\n");
				Sleep(0.5);
			}
			break;
		
		// Melania copies speaches
		case 1:
			scroll("Oh no! Melania was caught copying a speech again!\n");
			Sleep(0.5);
			scroll("Trump's ego takes damage...\n");
			ego -= 5;
			break;
		
		// wall gets destroyed or if the user didn't build a wall
		// remind them to 
		case 2:
			if(did.wall){
				scroll("Oh no! Your wall has been destroyed by an angry mob...\n");
				did.wall = false;
			}
			else{
				scroll("Reminder: Trump promised to build a wall...\n");
			}
			break;
			
		// trump's business benifits from his presidency 
		case 3:
			scroll("Trump's businesses are benifiting quite well from his presidency!\n");
			Sleep(0.25);
			scroll("Trump's ego rises...\n");
			ego += 20;
			Sleep(0.5);
			break;
		
		// protesters
		case 4:
			scroll("Oh no! There is an angry mob of protesters outside!\n\n");
			Sleep(0.5);
			scroll("How would you like to respond?\n");
			scroll("1.) Criticize protestors\n");
			scroll("2.) Blame someone else for the problem\n");
			scroll("3.) Accept blame\n");
			scroll("Well? ");
			cin >> choice;
			scroll("\n");
			
			// accept if it fits the query 
			if(choice < 4 && choice > 0){
				
				// rand chance of protesters leaving
				if(rand()%2){
					scroll("It worked! Protesters are leaving..\n");
					ego += 10;
				}
				
				// rand chance of the protesters getting angry
				else {
					scroll("Your response only made them more angry!\n");
					scroll("Trump's anger rises...\n");
					anger += 10;
				}
			}
			else{
				scroll("You failed to respond...");
			}
			Sleep(0.5);
			break;
		
		// rand amnt of jobs are added to the USA
		case 5:
			scroll("Good news!\n");
			new_jobs = rand()%5000;
			a.jobs += new_jobs;
			cout << "	" << new_jobs << " jobs have been added to USA\n";
			Sleep(0.5);
			scroll("\n");
			break;
		
		// rand amnt of aliens taken away from USA
		case 6:
			if(a.invasion){
				scroll("Good news!\n");
				aliens_away = rand()%5000;
				a.aliens -= aliens_away;
				cout << "	" << aliens_away << " aliens have decided to go back to space\n";
				Sleep(0.5);
				scroll("\n");
			}
			break;
	}
}

// opening scene
void opening(){
	
	// opening scene
	clear_screen();
	tab(1);
	scroll("    WELCOME TO\n");
	scroll("TRUMP'S BIG WHITE HOUSE ADVENTURE\n");
	scroll("\n\n");
	scroll("The beauty of me is that I'm very rich...\n");
	scroll("- Donald J. Trump");
	scroll("\n\n\n");
}

// good morning message
void morning(President &pres, Country &a){

	// morning greeting
	scroll("Good morning, President Trump...\n");
	scroll("Your schedule looks pretty full today...\n");
	scroll("\n");
	pres.goals(a);
	scroll("What would you like to do?\n");

}	

// print the main menu for user selection
int selection(){
	int choice;
	
	// give user the options and control errors in input
	while(!(choice < 10 && choice > 0)){
		
		scroll("1.) Eat\n", 0.005);
		scroll("2.) Tweet\n", 0.005);
		scroll("3.) Bring jobs back\n", 0.005);
		scroll("4.) Build a wall\n", 0.005);
		scroll("5.) Attack a country\n", 0.005);
		scroll("6.) Deport aliens\n", 0.005);
		scroll("7.) Get a tan\n", 0.005);
		scroll("8.) View stats\n", 0.005);
		scroll("9.) View goals\n", 0.005);
		scroll("Well?... ");
		
		// make sure user doesn't enter a letter
		while(!(cin >> choice)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			scroll("Invalid input. Try again: ");
		}
		// user fit the query 
		if(choice < 10 && choice > 0){
			return choice;
		}
		
		// wrong input
		else{
			clear_screen();
			scroll("Please choose again...\n");
		}
	
	}
	
}

// give the user a hint about the aliens and the jobs
void hint(){
	cout << endl;
	scroll("HINT:\n");
	scroll("Each turn, aliens will increase by 250 and jobs will\n");
	scroll("decrease by 250. Aliens will stop invading once you find\n");
	scroll("them all.\n");
	Sleep(1.5);
}

// main function
int main() {
	
	// move count
	int mv_count = 0;
	
	// char to hold the repeat query response
	char repeat;
	
	bool play_again = true;
	
	// loop so user can choose to play again
	while(play_again){
		
		// initialize usa with 10000 aliens 
		// and 100000 jobs
		Country usa(10000,100000);
		
		// initialize President Trump
		President trump;
		
		// reset game won status
		trump.success = false;
		
		// display opening scene and good morning 
		opening();
		morning(trump, usa);
		
		while(!trump.success){
			
			// at mv_count = 0, the morning message takes care of this question
			if(mv_count > 0) scroll("What's next on the agenda, Mr. President?\n");
			
			// query the player to select trumps action
			// then execute it
			trump.action(selection(), usa);
			trump.monitor(usa);
			mv_count++;
		
			// each turn add some aliens and subtract jobs
			// unless President already found all the aliens 
			if(usa.invasion) usa.aliens += 250;
			usa.jobs -= 250;
			
			// trump success depends on if all the goals 
			// were met
			if(!trump.success){
				// every three moves trigger a random event
				if(!(mv_count%3)) {
					trump.rand_event(usa);
				}
			}
			
			// show the hint at the users 2nd move 
			// (mv_count starts at 0)
			if(mv_count == 1){
				hint();
			}
			
			cout << endl;
			
			// user completed the game, ask if they want to play again 
			// and do the appropriate action for the response 
			if(trump.success){
				scroll("Would you like to play again? (y)es or (n)o: ");
				cin >> repeat;
				if(repeat == 'y') play_again = true;
				else play_again = false; 
				
			}
		}
	}
	
	return 0;
}
