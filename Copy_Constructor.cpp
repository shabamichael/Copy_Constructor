#include <iostream>
#include <string>

using namespace std;



class Movie
{
public:
	//parameterized constructor
	Movie(string name, string genre, float rating)
	{
		Name = name;
		Genre = genre;
		Rating = rating;
		ActorsCounter = 0;
		Actors = new string[ActorsCounter];
	}

	~Movie()
	{
		delete[] Actors;
		Actors = nullptr;
	}
	//default constructor
	Movie()
	{ 
		Name = "";
		Genre = "";
		Rating = 0.0;
	}
	//copy constructor
	Movie(const Movie& original)
	{
		Name = original.Name;
		Genre = original.Genre;
		Rating = original.Rating;
		ActorsCounter = original.ActorsCounter;
		Actors = new string[ActorsCounter];
		for (int i = 0; i < ActorsCounter; i++)
		{
			Actors[i] = original.Actors[i];
		}
	}
	//Assignment operator
	Movie operator =(const Movie & original)
	{
		if (&original != this)
		{
			Name = original.Name;
			Genre = original.Genre;
			Rating = original.Rating;
			ActorsCounter = original.ActorsCounter;
			delete[] Actors;
			//Actors = nullptr;

			Actors = new string[ActorsCounter];
			for (int i = 0; i < ActorsCounter; i++)
				Actors[i] = original.Actors[i];

			return *this;
		}
		
	}

	void AddActor(string newActorName)
	{
		string* newActors = new string[ActorsCounter + 1];
		for (int i = 0; i < ActorsCounter; i++)
			newActors[i] = Actors[i];

		newActors[ActorsCounter] = newActorName;

		delete[] Actors;
		Actors = newActors;
		ActorsCounter++;
	}

	void PrintInfo()
	{
		cout << Name << endl;
		cout  << Genre << endl;
		cout  << Rating << endl;
		cout << "Actors: " <<endl;
		for (int i = 0; i < ActorsCounter; i++)
			cout << Actors[i] << endl;
		cout << endl;	
	}
	
private:
	string Name;
	string Genre;
	float Rating;
	int ActorsCounter;
	string* Actors;
};
int main()
{
	Movie movie1("Very Dark Man", "Action", 8.9);
	Movie movie2("The Lion King", "Animated", 8.0);
	
	movie1.AddActor("Will Smith");
	movie1.AddActor("Denzel Washington");

	movie1.PrintInfo();

	Movie movie3(movie1); //copy constructor

	Movie movie4 = movie2; //copy constructor

	movie3.PrintInfo();

	movie3 = movie4;
	movie3.PrintInfo();

}