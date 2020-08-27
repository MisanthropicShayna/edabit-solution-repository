/* Is Johnny Making Progress? @ https://edabit.com/challenge/7wzdYkHSfWFsRdQfi
**
** To train for an upcoming marathon, Johnny goes on one long-distance run each Saturday.
** He wants to track how often the number of miles he runs this Saturday exceeds the number of
** miles run the previous Saturday. This is called a progress day.
**
** Create a function that takes in an array of miles run every Saturday
** and returns Johnny's total number of progress days.
** */

#include <vector>

int progressDays(std::vector<int> runs) {
	int progress_days = 0;

	for(size_t i=0; i<runs.size(); ++i) {
		if(i != 0 && runs[i-1] < runs[i]) progress_days++;
	}

	return progress_days;
}
