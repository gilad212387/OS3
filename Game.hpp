#ifndef __GAMERUN_H
#define __GAMERUN_H

#include "Headers.hpp"
#include "Thread.hpp"
#include "Job.hpp"
#include "PCQueue.hpp"

/*--------------------------------------------------------------------------------
								  Auxiliary Structures
--------------------------------------------------------------------------------*/
struct game_params {
	// All here are derived from ARGV, the program's input parameters. 
	uint n_gen;
	uint n_thread;
	string filename;
	bool interactive_on; 
	bool print_on; 
};
/*--------------------------------------------------------------------------------
									Class Declaration
--------------------------------------------------------------------------------*/
class Game {
private:
    void print_board(const char* header) const;
public:

	Game(game_params);
	~Game();
	void run(); // Runs the game
	const vector<float> gen_hist() const; // Returns the generation timing histogram  
	const vector<float> tile_hist() const; // Returns the tile timing histogram
	uint thread_num() const; //Returns the effective number of running threads = min(thread_num, field_height)
    void start_all_threads();
    void wait_for_threads();

protected: // All members here are protected, instead of private for testing purposes

	// See Game.cpp for details on these three functions
	void _init_game(); 
	void _step(uint curr_gen); 
	void _destroy_game();

	uint m_gen_num; 			 // The number of generations to run
	uint m_thread_num; 			 // Effective number of threads = min(thread_num, field_height)
	vector<float> m_tile_hist; 	 // Shared Timing history for tiles: First m_gen_num cells are the calculation durations for tiles in generation 1 and so on. 
								 // Note: In your implementation, all m_thread_num threads must write to this structure.
	vector<float> m_gen_hist;  	 // Timing history for generations: x=m_gen_hist[t] iff generation t was calculated in x microseconds
	vector<Thread*> m_threadpool;// A storage container for your threads. This acts as the threadpool.

	Lock m_tile_hist_lock;

	bool interactive_on; // Controls interactive mode - that means, prints the board as an animation instead of a simple dump to STDOUT 
	bool print_on; // Allows the printing of the board. Turn this off when you are checking performance (Dry 3, last question)

	// Implementation
	int field_width;
	int field_height;
	bool_mat *current_field, *next_field;
    PCQueue<Job*> jobs;
	string filename;
	Lock tile_lock;
};
#endif
