#include <iostream>
#include <ctime>
#include <string>


class Track
{
private:

	std::string nameTrack[5];		
	std::string dateOfCreationTrack[5];
	int durationTrack[5];

public:	
	
	std::string valueNameTrack;
	void SetRecordNameTrack()
	{
		
		for (int i = 0; i < 5; ++i) {

			valueNameTrack = "track";
			std::string numberOfTrack = std::to_string(i + 1);
			valueNameTrack += numberOfTrack;
			nameTrack[i] = valueNameTrack;			
			
		}		
	}

	void inTrackList(std::string trackList[])
	{

		for (int i = 0; i < 5; ++i) {

			trackList[i] = nameTrack[i];

		}
	}
	
	int GetNumberTrack(std::string songName)
	{

		for (int i = 0; i < 5; ++i) {			

			if (songName == nameTrack[i])
			{

				return i;
				
			}
		}
	}
	

	void SetRecordDateOfCreation()
	{

		std::time_t date = std::time(nullptr);
		std::tm today;
		localtime_s(&today, &date);
		today.tm_year = today.tm_year + 1900;
		++today.tm_mon;

		for (int i = 0; i < 5; ++i)
		{
			dateOfCreationTrack[i] = "";
			std::string result = std::to_string(today.tm_mday);
			dateOfCreationTrack[i] += result + ':';

			result = std::to_string(today.tm_mon);
			dateOfCreationTrack[i] += result + ':';

			result = std::to_string(today.tm_year);
			dateOfCreationTrack[i] += result + ' ';

			result = std::to_string(today.tm_hour);
			dateOfCreationTrack[i] += result + ':';

			result = std::to_string(today.tm_min);
			dateOfCreationTrack[i] += result;
		}
	}

	std::string GetDateOfCreationTrack(int number)
	{

		for (int i = 0; i < 5; ++i)
		{

			if (number == i)
			{

				return dateOfCreationTrack[i];

			}
		}
	}

	void SetRecordDurationTrack()
	{
		int volueDurationTrack[5];		

		volueDurationTrack[0] = 12;
		volueDurationTrack[1] = 5;
		volueDurationTrack[2] = 16;
		volueDurationTrack[3] = 3;
		volueDurationTrack[4] = 14;
		
		durationTrack[0] = volueDurationTrack[0];
		durationTrack[1] = volueDurationTrack[1];
		durationTrack[2] = volueDurationTrack[2];
		durationTrack[3] = volueDurationTrack[3];
		durationTrack[4] = volueDurationTrack[4];
	}

	int GetDurationTrack(int number)
	{

		for (int i = 0; i < 5; ++i)
		{

			if (number == i)
			{

				return durationTrack[i];

			}
		}

	}
	
	void PrintNameTrack()
	{
		
		std::cout << nameTrack[3] << " ";
	}

	void PrintDateOfCreation() 
	{

		std::cout <<  dateOfCreationTrack[3] << " ";

	}

	void PrintDurationTrack()
	{

		std::cout << durationTrack[3] << " sec." << std::endl;

	}
	
	

};



class Player
{

private:

	std::string nameMusic[5];
	std::string dateOfCreationMusic;
	int durationMusic;
	int nextNumber;

public:	

	std::string GetNameSong(std::string songName, Track track)
	{					

		track.inTrackList(nameMusic);
		
		bool is_availability = false;
		for (int i = 0; i < 5; ++i)
		{

			if (songName == nameMusic[i])
			{

				is_availability = true;
				break;

			}			
		}

		if (is_availability)
		{

			return songName;

		}
		else
		{

			songName = "There is no track with this name in the playlist";
			return songName;

		}		
	}

	int GetNumberSong(std::string songName, Track track)
	{			

		return track.GetNumberTrack(songName);

	}

	std::string GetSongCreationDate(std::string songName, Track track)
	{		
		
		dateOfCreationMusic = track.GetDateOfCreationTrack(GetNumberSong(songName, track));

		return dateOfCreationMusic;
	}

	int GetSongDuration(std::string songName, Track track)
	{
		
		durationMusic = track.GetDurationTrack(GetNumberSong(songName, track));

		return durationMusic;
	}

	std::string GetNextNameSong(Track track, int nextNumber)
	{		

		track.inTrackList(nameMusic);

		for (int i = 0; i < 6; ++i)
		{

			if (nextNumber == i)
			{

				return nameMusic[i];

			}
		}
	}

	int GetNextNbmberSong()
	{

		int number = std::rand() % 5;
		
		return number;

	}

	std::string GetNextSongCreationDate(Track track, int nextNumber)
	{

		dateOfCreationMusic = track.GetDateOfCreationTrack(nextNumber);

		return dateOfCreationMusic;
	}

	int GetNextSongDuration(Track track, int nextNumber)
	{
				
		durationMusic = track.GetDurationTrack(nextNumber);

		return durationMusic;
	}
};





int main()
{

	std::srand(std::time(nullptr));

	Track track;

	track.SetRecordNameTrack();
	track.SetRecordDateOfCreation();
	track.SetRecordDurationTrack();

	Player examination;	

	std::string command;
	std::string songName;

	bool is_playback = false;
	int timer = 0;

	do {


		std::cout << "Enter command: ";
		std::cin >> command;

		std::time_t tt = std::time(nullptr);
		std::tm time_tt;
		localtime_s(&time_tt, &tt);
		
		if (command == "play" && (tt >= timer)) {
			
			do
			{
			
				std::cout << "Enter song title: ";
				std::cin >> songName;
				

			} while (examination.GetNameSong(songName, track) == "There is no track with this name in the playlist");				

				std::cout << examination.GetNameSong(songName, track) << " " << examination.GetSongCreationDate(songName, track) << " duration: " << examination.GetSongDuration(songName, track) << " sec.\n";
				
				timer = examination.GetSongDuration(songName, track);

				std::time_t tt_timer = std::time(nullptr) + timer;
				std::tm time_timer;

				localtime_s(&time_timer, &tt_timer);

				timer = tt_timer;
				is_playback = true;				
				
		}
		else if (command == "pause" && is_playback == true) {

			std::cout << "Paused recording" << std::endl;
			timer = 0;
			is_playback = false;

		}
		else if (command == "next") {

			int nextNumber = examination.GetNextNbmberSong();
			std::cout << examination.GetNextNameSong(track, nextNumber) << " " << examination.GetNextSongCreationDate(track, nextNumber) << " duration: " << examination.GetNextSongDuration(track, nextNumber) << " sec.\n" << std::endl;

			timer = examination.GetNextSongDuration(track, nextNumber);

			std::time_t tt_ntimer = std::time(nullptr) + timer;
			std::tm time_ntimer;

			localtime_s(&time_ntimer, &tt_ntimer);

			timer = tt_ntimer;			

			is_playback = true;
		}
		else if (command == "stop" && is_playback == true) {

			std::cout << "Recording " << examination.GetNameSong(songName, track) <<  " stopped" << std::endl;
			
			is_playback = false;
		}
	} while (command != "exit");

	return 0;
}