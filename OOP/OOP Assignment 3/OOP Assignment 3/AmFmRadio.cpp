// fileName: AmFmRadio.cpp
// project: assignment 3
// programmer: Run Ji 8874457
// first version: 2/08/2024
// description: 
//		-- This file is the methods of the class. 
//		-- The methods in the class allow the user to simulate the operation of an actual radio, 
//		-- such as adjusting the volume, changing the channel, saving and selecting a preset frequency.

#include "AmFmRadio.h"

// constructor 1
// parameters: bool on
//		-- on indicate the power satus
// constructor description: 
//		-- This constructor can just instance of a radio, and set power status
AmFmRadio::AmFmRadio(bool on) : on(on), volume(0), currentStation(DEFAULT_AMFREQ), preVolume(0), displayOutput(false)
{
	strcpy(band, "AM"); // initial band is AM 
	lastFreq.amFreq = DEFAULT_AMFREQ; // initial am frequency
	lastFreq.fmFreq = DEFAULT_FMFREQ; // initial fm frequency

	for (int i = 0; i < NUM_OF_DEFAULT_STATION; i++) // initial all of button store the default frequency
	{
		button[i].amFreq = DEFAULT_AMFREQ;
		button[i].fmFreq = DEFAULT_FMFREQ;
	}

}

// constructor 2
// parameters: bool on
//		-- on indicate the power satus
// constructor description: 
//		-- This constructor can set preset station and set power status
AmFmRadio::AmFmRadio(bool on, freqs preset[NUM_OF_DEFAULT_STATION]) : on(on), volume(0), currentStation(DEFAULT_AMFREQ), preVolume(0), displayOutput(false)
{
	strcpy(band, "AM"); // initial band is AM 
	lastFreq.amFreq = DEFAULT_AMFREQ; // initial am frequency
	lastFreq.fmFreq = DEFAULT_FMFREQ; // initial fm frequency

	// initialize(preset) the AmFmRadio button's AM freqs preset
	for (int i = 0; i < NUM_OF_DEFAULT_STATION; i++)
	{
		if ( preset[i].amFreq >= FIRST_AM_FREQUENCY && preset[i].amFreq <= LAST_AM_FREQUENCY)
		{
			button[i].amFreq = preset[i].amFreq;
		}
		else if (preset[i].amFreq < FIRST_AM_FREQUENCY)
		{
			button[i].amFreq = FIRST_AM_FREQUENCY;
		}
		else
		{
			button[i].amFreq = LAST_AM_FREQUENCY;
		}
	}
	// initialize(preset) the AmFmRadio button's FM freqs preset
	for (int i = 0; i < NUM_OF_DEFAULT_STATION; i++)
	{
		if (preset[i].fmFreq >= FIRST_FM_FREQUENCY && preset[i].fmFreq <= LAST_FM_FREQUENCY)
		{
			button[i].fmFreq = preset[i].fmFreq;
		}
		else if (preset[i].fmFreq < FIRST_FM_FREQUENCY)
		{
			button[i].fmFreq = FIRST_FM_FREQUENCY;
		}
		else
		{
			button[i].fmFreq = LAST_FM_FREQUENCY;
		}
	}
}

// deconstructor
// parameter: void
// deconstructor description: destroy the radio object and shows a destroying message
AmFmRadio::~AmFmRadio(void)
{
	printf("Destroying AmFmRadio");
}


// method name: PowerToggle
// parameters: void
// return value: void
// method description:
//		-- like a light swicth. When light on, press the switch, the light going off. Vice versa.
//		-- When turning the radio on after being off, go immediately to the previous band (AM or FM) 
//		-- and last frequency tuned on that band which the radio was set to before being powered off.
//		-- When turning the radio off, turn the volume down to 0. When turning the radio back on, restore the previous volume level.

void AmFmRadio::PowerToggle(void)
{
	if( on == false )
	{
		on = true; // turn on the radio
		
		if ( strcmp(band, "AM") == 0 )
		{
			currentStation = lastFreq.amFreq; // change the currentStation to the station which when radio tuned off
		}
		else
		{
			currentStation = lastFreq.fmFreq;
		}

		volume = preVolume; // restore the previous volume level

	}
	else // turn off the radio
	{
		on = false; // turn off the radio

		if ( strcmp(band, "AM") == 0 )
		{
			lastFreq.amFreq = currentStation; // save currentStation
		}
		else
		{
			lastFreq.fmFreq = currentStation;
		}

		preVolume = volume; // save current volume
		volume = 0; // turn the volume down to 0
	}

}


// method name: IsRadioOn
// parameter: void
// return value: bool
// method description: 
//		--returns a true if the radio is currently powered on, and false if the radio is in
//      --the off position

bool AmFmRadio::IsRadioOn(void)
{
	if (on == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// method name: SetVolume
// parameter: void
// return value: int
//		-- return value from the SetVolume(int newVolume)
//		--0: The input volume is below the minimum volume and the volume is set to the minimum volume.
//		--1: The input volume is between the minimum volume and the maximum volume, the volume is set successfully.
//		--2: The input volume is higher than the maximum volume, the volume is set to the maximum volume.
//		--(-1): Indicates the power status is off, setting volume failed.
// method description: 
//		-- The user enters a number representing the volume level, ranging from 0 to 100. 
//		-- The input is converted to an integer and pass it input to the SetVolume(int newVolume) methods.

int AmFmRadio::SetVolume(void)
{
	//if (on == false) // if radio power off, then can not change the volume. Only can change the volume when power on
	//{
	//	return -1;
	//}

	char buf[VOLUME_BUF] = ""; // buffer for input number + \n + \0
	int userVolume = 0;

	printf("\nEnter the volume level (0 - 100) >> ");
	fgets(buf, sizeof(buf), stdin);
	userVolume = atoi(buf); // Any illegal input, the return value of atoi will be equal to 0, another word, volume will be 0

	return SetVolume(userVolume);
}


// method name: SetVolume
// parameter: int newVolume -- the newVolume can directly change the volume
// return value: int
//		--0: The input volume is below the minimum volume and the volume is set to the minimum volume.
//		--1: The input volume is between the minimum volume and the maximum volume, the volume is set successfully.
//		--2: The input volume is higher than the maximum volume, the volume is set to the maximum volume.
//		--(-1): Indicates the power status is off, setting volume failed.
// method description: 
//		-- This method sets the volume to the given new volume value.
//		-- If the new volume is below the minimum volume limit, the volume will be set to the minimum volume and return 0
//		-- If the new volume is above the maximum volume limit, the volume will be set to the maximum volume and return 2
//		-- If current radio is power off, then the volume can not be changeed, return -1.
//		-- Otherwise, the volume will be set to the new volume value and return 1

int AmFmRadio::SetVolume(int newVolume)
{
	//if (on == false) // if radio power off, then can not change the volume. Only can change the volume when power on
	//{
	//	return -1;
	//}

	if (newVolume < MINIMUM_VOLUME) // if user enters volume less than minimum volume, volume = minimum volume
	{
		volume = MINIMUM_VOLUME;
		return 0;
	}

	if (newVolume > MAXIMUM_VOLUME) // if user enters volume greater than maximum volume, volume = maximum volume
	{
		volume = MAXIMUM_VOLUME;
		return 2;
	}

	volume = newVolume; // normal situation
	return 1;
}


// method name: ToggleBand
// parameters: void
// return value: void
// method description:
//		-- band switch, am - fm, or fm - am.
//		-- First store the current station to lastFreq, then tune the current station to lastFreq. 
//		-- both AM and FM have their own counterparts.

void AmFmRadio::ToggleBand(void)
{
	if( strcmp(band, "AM") == 0 )
	{
		strcpy(band, "FM");
		lastFreq.amFreq = currentStation;
		currentStation = lastFreq.fmFreq;
	}
	else
	{
		strcpy(band, "AM");
		lastFreq.fmFreq = currentStation;
		currentStation = lastFreq.amFreq;
	}
}


// method name: SetPresetButton
// parameters: int buttonNum
//		-- buttonNum is just button's number, first button, second button...
// return value: bool
//		-- true if set prest button successfully, vice versa
// method description:
//		-- Saves the current radio frequency to a preset button. 
//		-- It accepts an integer parameter button_num indicating the number of the preset button to be set

bool AmFmRadio::SetPresetButton(int buttonNum)
{
	if( (buttonNum >= 0) && (buttonNum <= 4) )
	{
		if( strcmp("AM", band) == 0 ) // AM
		{
			button[buttonNum].amFreq = currentStation;
		}
		else // FM
		{
			button[buttonNum].fmFreq = currentStation;
		}
		return true;

	}
	
	return false; // the button num out of the range
}


// method name: SetCurrentStation
// parameters: double newStation
// return value: void
// method description:
//		-- setting the current frequency of the radio, if user input Station not in the range, the radio station will be
//		-- set first frequency or last frequency

void AmFmRadio::SetCurrentStation(double newStation)
{
	if (strcmp("AM", band) == 0)
	{
		if (newStation >= FIRST_AM_FREQUENCY && newStation <= LAST_AM_FREQUENCY)
		{
			currentStation = newStation;
		}
		else if (newStation < FIRST_AM_FREQUENCY)
		{
			currentStation = FIRST_AM_FREQUENCY;
		}
		else
		{
			currentStation = LAST_AM_FREQUENCY;
		}
	}
	else
	{
		if (newStation >= FIRST_FM_FREQUENCY && newStation <= LAST_FM_FREQUENCY)
		{
			currentStation = newStation;
		}
		else if (newStation < FIRST_FM_FREQUENCY)
		{
			currentStation = FIRST_FM_FREQUENCY;
		}
		else
		{
			currentStation = LAST_AM_FREQUENCY;
		}
	}
}


// method name: SelectPresetButton
// parameters: int buttonNum
//		-- buttonNum is just button's number, first button, second button...
// return value: bool
//		-- true if selected button successfully, vice versa
// method description:
//		-- Sets the current frequency of the radio to the frequency saved by this preset button

bool AmFmRadio::SelectPresetButton(int buttonNum)
{
	if( (buttonNum >= 0) && (buttonNum <= 4) )
	{
		if( strcmp("AM", band) == 0 ) // AM
		{
			currentStation = button[buttonNum].amFreq;
		}
		else // FM
		{
			currentStation = button[buttonNum].fmFreq;
		}

		return true;
	}

	return false;
}


// method name: ShowCurrentSettings
// parameters: void
// return value: void
// method description:
//		-- show radio information volume, button settings, current station, as well as button setting

void AmFmRadio::ShowCurrentSettings(void)
{
	if( on == true )
	{
		printf("\n\nRadio is on. \n");
	}
	else // on == false
	{
		printf("\n\nRadio is off. \n");
	}

	printf("\nRadio Band: %s\n", band); // show am or fm
	printf("Volume: %d\n", volume); // show volume level
	printf("Current Station: %.1f %s\n", currentStation, band); // show frequency with am/fm
	printf("AM Button Settings: "); // show AM Button Settings: 1)      530 2)      630 3) ...
	for( int i = 0; i < NUM_OF_DEFAULT_STATION; ++i )
	{
		printf("%d) %6d ", i + 1, button[i].amFreq);
	}

	printf("\nFM Button Settings: "); // show FM Button Settings: 1)      87.9 2)      89.1 3) ...
	for( int j = 0; j < NUM_OF_DEFAULT_STATION; ++j )
	{
		printf("%d) %6.1f ", j + 1, button[j].fmFreq);
	}

	printf("\n");
}


// method name: ScanUp
// parameters: void
// return value: void
// method description:
//		-- Each scan up, adjusts am up by 10 or fm up by 0.2. or 
//		-- when the current channel reaches the last one, it will retune back to the first one.

void AmFmRadio::ScanUp(void)
{
	if( strcmp("AM", band) == 0 )
	{
		//if current_station is LAST_AM_FREQUENCY, the current_station becomes FIRST_AM_FREQUENCY
		if(currentStation == LAST_AM_FREQUENCY)
		{
			currentStation = FIRST_AM_FREQUENCY;
		}
		else
		{
			currentStation = currentStation + 10;
		}
	}
	else
	{
		//if the current_station is LAST_FM_FREQUENCY, the current_station becomes FIRST_FM_FREQUENCY
		if(currentStation >= LAST_FM_FREQUENCY)
		{
			currentStation = FIRST_FM_FREQUENCY;
		}
		else
		{
			currentStation = currentStation + .2;
		}
	}

	if (displayOutput)
	{
		printf("\nCurrent station: %.1f %s\n", currentStation, band);
	}

}


// method name: ScanDown
// parameters: void
// return value: void
// method description:
//		-- Each scan down, adjusts am down by 10 or fm up by 0.2. or 
//		-- when the current channel going down and reaches the first one, it will retune to the last one.

void AmFmRadio::ScanDown(void)
{
	if ( strcmp("AM", band) == 0 )
	{
		//if current_station is FIRST_AM_FREQUENCY, the current_station becomes LAST_AM_FREQUENCY
		if (currentStation == FIRST_AM_FREQUENCY)
		{
			currentStation = LAST_AM_FREQUENCY;
		}
		else
		{
			currentStation = currentStation - 10;
		}
	}
	else // "FM"
	{
		//if the current_station is FIRST_FM_FREQUENCY, the current_station becomes LAST_FM_FREQUENCY
		if (currentStation <= FIRST_FM_FREQUENCY)
		{
			currentStation = LAST_FM_FREQUENCY;
		}
		else
		{
			currentStation = currentStation - .2;
		}
	}

	if (displayOutput)
	{
		printf("\nCurrent station: %.1f %s\n", currentStation, band);
	}

}


// method name: SetDisplayOutput
// parameters: bool display
// return value: void
// method description: set whether or not display output

void AmFmRadio::SetDisplayOutput(bool display)
{
	displayOutput = display;
}


// method name: GetCurrentStation
// parameters: void
// return value: double
// method description: get currentStation, this function return current station

double AmFmRadio::GetCurrentStation(void) const
{
	return currentStation;
}


// method name: GetVolume
// parameters: void
// return value: int
// method description: get volume, this function return volume.

int AmFmRadio::GetVolume(void) const
{
	return volume;
}


// method name: GetPreset
// parameters: void
// return value: freqs
// method description: get a set of preset station, return a copy of preset

freqs* AmFmRadio::GetPreset(void) const
{
	int numberOfPresets = NUM_OF_DEFAULT_STATION;
	freqs* presetsCopy = (freqs*)malloc(numberOfPresets * sizeof(freqs));
	if (presetsCopy != nullptr)
	{
		memcpy(presetsCopy, button, numberOfPresets * sizeof(freqs));
	}
	
	return presetsCopy;
}


// method name: GetBand
// parameters: void
// return value: const char*
// method description: get current band, return a copy of current band

const char* AmFmRadio::GetBand(void) const
{
	size_t length = strlen(band) + 1; // 1 for '\0'

	char* bandCopy = (char*)malloc(sizeof(band));
	if (bandCopy != nullptr)
	{
		memcpy(bandCopy, band, length);
	}

	return bandCopy;
}


// method name: GetDisplayOutput
// parameters: void
// return value: bool
// method description: return a bool value that indicates whether or not disply output

bool AmFmRadio::GetDisplayOutput(void) const
{
	return displayOutput;
}