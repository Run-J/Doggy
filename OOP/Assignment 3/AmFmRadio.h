// File name: AmFmRadio.h
// Project: assignment 3
// Programmer: Run Ji
// First version: 2/08/2024
// Description: define a struct and a class

#ifndef _AMFMRADIO_H
#define _AMFMRADIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#pragma warning(disable:4996) // compiler said strcpy is unsafe

#define NUM_OF_DEFAULT_STATION 5
#define NUM_OF_BAND 3 // 1 for \0
#define VOLUME_BUF 20
#define INPUT_BUFFER 20
#define MAXIMUM_VOLUME 100
#define MINIMUM_VOLUME 0
#define FIRST_AM_FREQUENCY 530
#define LAST_AM_FREQUENCY 1700
#define FIRST_FM_FREQUENCY 87.9
#define LAST_FM_FREQUENCY 107.9
#define DEFAULT_AMFREQ 530
#define DEFAULT_FMFREQ 87.9

struct freqs
{
	int amFreq;
	double fmFreq;
};

// Class name: AmFmRadio.
// Class description: 
//		-- It simulates the behavior of a radio, including the functions of power on/off, volume control, 
//		-- frequency selection, setting and selection of preset frequencies, and AM/FM band switching. 

class AmFmRadio
{
private:
	double	currentStation; // station frequency
	char	band[NUM_OF_BAND]; // am or fm
	int		volume; // radio volume
	int		preVolume; // last volume that used on radio before turn off
	bool	on; // for power toggle
	freqs	button[NUM_OF_DEFAULT_STATION]; // button that store the station frequency
	freqs   lastFreq; // for store last frequency that tuned on certain band
	bool	displayOutput; // Used to control whether or not the output is displayed

public:
	// constructors
	AmFmRadio(bool on = false);
	AmFmRadio(bool on, freqs preset[NUM_OF_DEFAULT_STATION]);

	// deconstructor
	~AmFmRadio(void);

	// accessor, get current station
	double GetCurrentStation(void) const;

	// accessor, get volume
	int GetVolume(void) const;

	// accessor, get radio preset
	freqs* GetPreset(void) const;

	// accessor, get current band
	const char* GetBand(void) const;

	// accessor, get whether or not display output
	bool GetDisplayOutput(void) const;

	// power switch
	void PowerToggle(void);

	// check radio on or off
	bool IsRadioOn(void);

	// toggles frequency between AM and FM and sets current station
	void ToggleBand(void);

	// sets button (radio preset) with current station by being passed a button number
	bool SetPresetButton(int button_num);

	// setting the current frequency of the radio
	void SetCurrentStation(double newStation);

	// used to change whether or not the output is displayed
	void SetDisplayOutput(bool display);

	// sets current station to radio preset by being passed a button number
	bool SelectPresetButton(int buttonNum);

	// sets volume
	int SetVolume(void);

	// set volume, but allow users to get volume values in their own way
	int SetVolume(int newVolume);

	// shows volume, button settings, current station, AM or FM
	void ShowCurrentSettings(void);

	// changes frequency up in increments of .2 for FM, 10 for AM
	void ScanUp(void);

	// changes frequency down in descrements of .2 for FM, 10 for AM
	void ScanDown(void);

};
#endif // _AMFMRADIO_H